# S32K144 AUTOSAR (MICROSAR) HIL 工程

NI PXI ↔ S32K144 最小 CAN/PIL 链路：10ms 周期，0x100(HIL_Vx: Vx/Cnt) → S32K144 → 0x200(HIL_Cmd: Throttle/Pcon/Heartbeat/Fault)，500 kbit/s。

## 目录结构

| 目录 | 说明 |
|---|---|
| `dvc_project/` | DaVinci Configurator 工程（`s32k_dvc.dpa`）+ 生成代码（`Appl/GenData`，**不要手改**，改配置后重新 Generate） |
| `eb_projects/` | EB Tresos MCAL 工程（S32K144 MCAL 配置） |
| `iar_projects/` | IAR 工程（`iar_project.ewp`，ARM 工具链） |
| `swc/` | 手写代码：`HIL_Controller.c`（SWC Runnable 实现）、`controller.c`/`controller.h`（控制算法，从已验证 PI 固件移植） |
| `PIL_10_5/` | NI 侧：DBC（`PIHIL_ctrltime_ms.dbc`）、LabVIEW 工程 |

## 构建流程（顺序不能乱）

1. **DaVinci Developer**：改 SWC/端口/Runnable（只动结构）。
2. **DaVinci Configurator**：配 BSW/MCAL → Validate → **Generate**（全模块勾选，含 Mcu），生成代码落到 `dvc_project/Appl/GenData`。
3. **IAR**：以 `iar_projects/iar_project.ewp` 为底，把 `Appl/GenData`、`swc/`、BSW/MCAL 源码或库、启动文件/链接文件加进工程；device 选 S32K144（注意不要混入 `CPU_S32K148` 宏）；编译。
4. **J-Link**：下载调试。先看启动（`EcuM_Init → StartOS`，Heartbeat 每 10ms 自增），再用 CANalyst-II 验证 0x200 发送 / 0x100 接收 / 50ms 超时保护（Fault 置 1、油门清零），最后上 PXI 联调。

## 当前控制算法

`swc/controller.c`：PID 车速控制（Kp=0.12, Ki=0.045, Kd=0.006, 目标 60km/h，条件积分抗饱和），从实机验证过的 `s32k144_HIL_PID_CAN1` 固件移植。换 PMPC 时只替换 `controller.c`/`controller.h`，SWC 侧不用动。

## 硬件要点

- 板子：品智 S32K144 V2.2；CAN1 走板载 DB9（7=CAN_H、2=CAN_L、3=GND），PTA12/13 ALT3。
- CAN 实验必须 **12V DC 供电**（USB 带不动 TJA1051T）。
- 烧录：J-Link V9，SWD。
