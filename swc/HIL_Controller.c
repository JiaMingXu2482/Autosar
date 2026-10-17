/**********************************************************************************************************************
 *  FILE: HIL_Controller.c
 *  SWC : HIL_Controller
 *  说明: 10ms HIL 控制 Runnable。
 *        链路: 0x100(HIL_Vx: Vx/Cnt) -> S32K144 -> 0x200(HIL_Cmd: Throttle/Pcon/Heartbeat/Fault)
 *        控制算法在 controller.c (CTRL_Step), 已验证的PI逻辑, 以后换PMPC只改那边。
 *********************************************************************************************************************/
#include "Rte_HIL_Controller.h"
#include "controller.h"

/* 内部状态 */
static uint8  hil_heartbeat = 0U;   /* 每10ms自增的心跳 */
static uint8  hil_fault     = 0U;   /* 故障字: 50ms未收到0x100则置1 */
static uint16 hil_lastCnt   = 0U;   /* 上一周期收到的Cnt */
static uint8  hil_missTick  = 0U;   /* 连续未收到新帧的10ms tick数 */
static uint8  hil_firstRun  = 1U;   /* 首周期标志 */

#define HIL_LINK_TIMEOUT_TICKS  5U  /* 5 tick x 10ms = 50ms 超时 */

/**********************************************************************************************************************
 * 控制算法钩子: 调用 controller.c 的 CTRL_Step()。
 * 物理单位换算: Vx: S16 x0.01 -> km/h ; Throttle: x10000 -> U16 (系数0.0001) ; Pcon: x1000 -> U16 (系数0.001 MPa)
 *********************************************************************************************************************/
static void HIL_ControlStep(float vx_kph, float *throttle, float *pcon)
{
    ctrl_out_t out;
    CTRL_Step(vx_kph, &out);   /* 已验证PI算法 */
    *throttle = out.throttle;
    *pcon     = out.pcon_mpa;
}

#define HIL_Controller_START_SEC_CODE
#include "HIL_Controller_MemMap.h"

/* Runnable: HIL_Controller_Run10ms (OsAlarm_10ms -> OsTask_10ms 触发) */
FUNC(void, HIL_Controller_CODE) HIL_Controller_Run10ms(void)
{
    sint16 vx_raw;
    uint16 cnt;
    float  vx_kph, throttle_f, pcon_f;
    uint16 throttle_u16, pcon_u16;

    /* 1. 读输入: Vx (S16), Cnt (U16帧计数器) */
    Rte_Read_R_HIL_Vx_Cnt(&cnt);
    Rte_Read_R_HIL_Vx_Vx(&vx_raw);

    /* 2. 链路监督: Cnt变化=收到新帧; 连续5个tick无新帧=50ms超时 */
    if (hil_firstRun == 1U)
    {
        hil_lastCnt  = cnt;
        hil_firstRun = 0U;
        hil_missTick = 0U;
        CTRL_Init();           /* 控制器积分/微分状态复位 */
    }
    else if (cnt != hil_lastCnt)
    {
        hil_lastCnt  = cnt;
        hil_missTick = 0U;
    }
    else if (hil_missTick < 255U)
    {
        hil_missTick++;
    }

    if (hil_missTick >= HIL_LINK_TIMEOUT_TICKS)
    {
        /* 3a. 超时: 安全状态, 输出清零 */
        hil_fault    = 1U;
        throttle_u16 = 0U;
        pcon_u16     = 0U;
    }
    else
    {
        /* 3b. 正常: 跑控制算法, 物理值转总线原始值 (限幅防溢出) */
        hil_fault = 0U;
        vx_kph    = (float)vx_raw * 0.01f;
        HIL_ControlStep(vx_kph, &throttle_f, &pcon_f);
        if (throttle_f < 0.0f)    { throttle_f = 0.0f; }
        if (throttle_f > 6.5535f) { throttle_f = 6.5535f; }  /* U16 x0.0001 上限 */
        if (pcon_f < 0.0f)        { pcon_f = 0.0f; }
        if (pcon_f > 65.535f)     { pcon_f = 65.535f; }      /* U16 x0.001 MPa 上限 */
        throttle_u16 = (uint16)(throttle_f * 10000.0f);
        pcon_u16     = (uint16)(pcon_f * 1000.0f);
    }

    /* 4. 心跳自增 (U8自然溢出) */
    hil_heartbeat++;

    /* 5. 写输出 */
    Rte_Write_P_HIL_Cmd_Fault(hil_fault);
    Rte_Write_P_HIL_Cmd_Heartbeat(hil_heartbeat);
    Rte_Write_P_HIL_Cmd_Pcon(pcon_u16);
    Rte_Write_P_HIL_Cmd_Throttle(throttle_u16);
}

#define HIL_Controller_STOP_SEC_CODE
#include "HIL_Controller_MemMap.h"
