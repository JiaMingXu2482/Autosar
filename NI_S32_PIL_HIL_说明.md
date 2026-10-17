# NI–S32K144 PIL/HIL 联调说明

> S32K144 作实时控制器，NI PXI 作实时仿真/测试上位机，经 CAN 总线闭环。
> S32 侧 10ms 控制周期跑 PI，PXI 侧跑 CarSim 整车模型（VeriStand/CarSim RT）。

## 1. 系统拓扑

```
┌──────────────┐  CAN 500kbit/s   ┌──────────────┐
│  NI PXI      │ ◄──────────────► │  S32K144     │
│  PXIe-8135   │   0x100 ↓ Vx/Cnt │  品智开发板   │
│  PXI-8513    │   0x200 ↑ Cmd    │  FlexCAN1    │
│  PharLap ETS │                  │  10ms PI     │
└──────────────┘                  └──────────────┘
```

- PXI：PXIe-1071 机箱 + PXIe-8135（Phar Lap ETS 13.1，IP 169.254.66.2）+ PXI-8513 CAN 卡
- 软件：NI-XNET **20.0**（本机与 PXI 必须一致，VeriStand 2020 搭配），LabVIEW 直连
- S32：S32DS + J-Link V9（SWD）烧录调试；CAN 收发测试另用 CANalyst-II

## 2. CAN 通信矩阵（`PI_HIL.dbc`）

| 帧 ID | 帧名 | 方向 | 周期 | 信号 | 含义 |
|---|---|---|---|---|---|
| 0x100 | HIL_Vx | PXI → S32 | 1ms | Vx (16bit, 0.01) | 车速 km/h（CarSim 输出） |
| | | | | Cnt (16bit, U16) | PXI 帧计数器，每帧 +1，溢出回 0 |
| 0x200 | HIL_Cmd | S32 → PXI | 10ms | Throttle (0.0001) | 油门开度 0~1 |
| | | | | Pcon (0.001 MPa) | 制动压力 |
| | | | | Heartbeat (8bit) | S32 心跳，每 10ms 自增 |
| | | | | Fault (8bit) | 故障字，见 §4 |

- DBC 在 NI MAX 的部署别名为 **`PI_HIL`**（更新 DBC 后同名重新 Deploy 即覆盖，LabVIEW VI 不用改）
- 注：曾计划在 0x200 加 `CtrlTime` 信号，当前磁盘版 DBC 尚未包含，部署前请核对

## 3. S32 固件流程（10ms 周期）

```
收到 0x100 → 解析 Vx/Cnt → Cnt 连续性检查 → PI 计算 CTRL_Step()（约 0.003ms）
    → 打包 0x200（Throttle/Pcon/Heartbeat++/Fault）→ CAN 发送
    → 50ms 超时检查：超时则 Fault=1、油门清零
```

- 心跳机制：Heartbeat 每控制周期自增，PXI 侧看心跳是否停滞判断 S32 存活
- Cnt 校验：不连续 → 丢帧；长时间不变 → 链路中断
- 看门狗：当前固件未启用硬件 WDOG，靠应用层 Heartbeat + 50ms 超时做系统级监控

## 4. 故障保护

| 条件 | 动作 |
|---|---|
| 50ms 未收到 0x100 | Fault 置 1，油门清零 |
| Cnt 不连续 | 记丢帧（PXI 侧统计） |
| Heartbeat 停滞 | PXI 判定 S32 失活 |

## 5. 硬件连接（CAN1 版）

```
S32 板载 DB9（公头）--DB9 公对母直通线--> PXI-8513 端口
  Pin 7 = CAN_H，Pin 2 = CAN_L，Pin 3 = GND（标准 DB9 定义）
```

- 板载 CAN1 收发器 TJA1051T：PTA13=CAN1_TX，PTA12=CAN1_RX（ALT3）
- 终端电阻：板载 R50（120Ω）固定接在 CAN1HO/CAN1LO 之间，S32 侧不用加；8513 侧按 NI 要求在总线末端加 120Ω
- 供电注意：CAN 实验必须 **12V DC** 供电（USB 供不动 TJA1051T）
- 另有 CAN0 版固件（蓝色 H6 端子），回烧即切换（见 README_CAN1.md）

## 6. 文件目录说明

```
~/workspace/your_files/
├── PI_HIL.dbc                      # CAN 数据库（0x100/0x200 定义）
└── s32k144_HIL_PID_CAN1/           # S32 固件工程（S32DS，CAN1 版，已实机验证）
    ├── README_CAN1.md              # CAN1 版说明：接线、相对 CAN0 版的 3 处改动
    ├── README_PID.md               # PI 控制器说明
    ├── Sources/
    │   ├── main.c                  # 主循环，10ms 调度
    │   ├── controller.c / .h       # PI 控制器（CTRL_Step）
    │   ├── can_hil.c / .h          # HIL CAN 收发（0x100 解析 / 0x200 打包）
    │   ├── can_cmd.c / .h          # 0x10 控灯等调试命令
    │   ├── hil_timer.c / .h        # 10ms 定时器
    │   ├── sys_cfg.c / .h          # 时钟/引脚系统配置
    │   ├── wdog.c / uart.c / delay.c
    ├── include/ / src/             # 头文件与源码目录
    ├── SDK/                        # S32 SDK
    ├── Generated_Code/             # Processor Expert 生成代码
    └── Documentation/
```

- LabVIEW VI（PXI 侧 Timed Loop + NI-XNET 收发）在用户本机，不在此目录
- 关键约束：`main.c` 与 `main_CAN.c` 不可同时参与构建；源文件注释只用 GBK 安全字符；耗时测量用 DWT 固定地址（详见 README）

## 7. 关键参数速查

| 参数 | 值 |
|---|---|
| CAN 波特率 | 500 kbit/s |
| S32 控制周期 | 10 ms |
| PI 单步耗时 | 约 0.003 ms |
| 接收超时 | 50 ms → Fault + 油门清零 |
| NI-XNET 版本 | 20.0（本机/PXI 一致） |
| PXI IP | 169.254.66.2（Phar Lap ETS 13.1） |
| DBC 部署别名 | PI_HIL |
