/*
 * controller.c
 * PID 车速控制 (10ms 一拍), 从已验证固件 s32k144_HIL_PID_CAN1 移植:
 *   e = Vset - Vx
 *   u = Kp*e + Ki*积分(e) + Kd*d(e)/dt, 限幅到 [-1, 1]
 *   u >= 0 : throttle = u,   pcon = 0
 *   u <  0 : throttle = 0,   pcon = -u * PCON_MAX
 * 抗积分饱和: 只有"未饱和"或"误差与输出反向"时才积分; 积分限幅取 1/Ki。
 * 参数整定 (PC纵向模型, 2000kg, 含int16量化):
 *   0->60km/h : 超调 +1.1km/h, 约10.8s进入 +-0.5km/h
 *   80->40km/h: 下冲 -1.3km/h, 制动正常介入
 * 注意: 不用 math 库, 纯加减乘除。
 * 以后换 PMPC: 只替换本文件和 controller.h, SWC 侧不用动。
 */
#include "controller.h"

#define CTRL_KP    (0.12f)
#define CTRL_KI    (0.045f)
#define CTRL_KD    (0.006f)
#define CTRL_DT_S  (0.01f)         /* 控制周期 10ms */
#define CTRL_PCON_MAX_MPA (8.0f)   /* 制动压力上限 [MPa] */

static float s_i;       /* 积分项 */
static float s_e_prev;  /* 上一拍误差, 求微分用 */

void CTRL_Init(void)
{
    s_i      = 0.0f;
    s_e_prev = 0.0f;
}

void CTRL_Step(float vx_kmh, ctrl_out_t *out)
{
    float e, u_p, u_i, u_d, u, u_sat, i_lim;

    e   = CTRL_VSET_KMH - vx_kmh;
    u_p = CTRL_KP * e;
    u_i = CTRL_KI * s_i;
    u_d = CTRL_KD * (e - s_e_prev) / CTRL_DT_S;

    u = u_p + u_i + u_d;
    u_sat = u;
    if (u_sat > 1.0f)
    {
        u_sat = 1.0f;
    }
    else if (u_sat < -1.0f)
    {
        u_sat = -1.0f;
    }

    /* 条件积分: 未饱和, 或误差与输出反向时才积分 */
    if ((u == u_sat) || ((e > 0.0f) != (u > 0.0f)))
    {
        s_i += e * CTRL_DT_S;
        i_lim = 1.0f / CTRL_KI;
        if (s_i > i_lim)
        {
            s_i = i_lim;
        }
        else if (s_i < -i_lim)
        {
            s_i = -i_lim;
        }
        u = u_p + CTRL_KI * s_i + u_d;
        if (u > 1.0f)
        {
            u = 1.0f;
        }
        else if (u < -1.0f)
        {
            u = -1.0f;
        }
        u_sat = u;
    }
    s_e_prev = e;

    /* 输出分配: 油门和制动互斥 */
    if (u_sat >= 0.0f)
    {
        out->throttle = u_sat;
        out->pcon_mpa = 0.0f;
    }
    else
    {
        out->throttle = 0.0f;
        out->pcon_mpa = -u_sat * CTRL_PCON_MAX_MPA;
    }
}
