#ifndef CONTROLLER_H
#define CONTROLLER_H

/* 目标车速 [km/h]: 改这一行即可 */
#define CTRL_VSET_KMH  (60.0f)

typedef struct
{
    float throttle;   /* 油门开度 [0..1] */
    float pcon_mpa;   /* 制动主缸压力 [MPa], 0 = 不制动 */
} ctrl_out_t;

void CTRL_Init(void);
void CTRL_Step(float vx_kmh, ctrl_out_t *out);  /* 每10ms调用一拍 */

#endif /* CONTROLLER_H */
