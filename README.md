# embedded-aiot-path

定位：以 **Linux BSP / 驱动 + 薄用户态应用** 为主线的 12 周学习与实验仓；端侧 AI 作为完成主线后的可选进阶。旧的「classic/edge 双轨」改为补充/归档材料，保留入口不删改有价值内容。

> 公开仓：`https://github.com/Romanrose/embedded-aiot-path`  
> 说明：本仓不依赖任何私有语雀内容即可学习；必要时仅给出公开来源入口与版本说明。

## 你将面向哪些岗位

- 芯片原厂/方案商的 **Linux 驱动 / BSP / SDK 工程师**（GPIO/IRQ/I2C 等外设，IIO/hwmon，DTS/Platform，总线子系统基础）
- 终端厂的 **Linux 驱动 + C/C++ 应用**（用户态与内核态协作、稳定性与可复现）
- 选修：**V4L2 或 DRM** 基础；完成后可再选端侧 AI（ONNX Runtime / RKNN 等）做应用侧增强

前置建议（可与主线并行的「轻量基础」）：

- C 语言、指针与结构体；会写最小 C++ 用户态程序（选修周用）  
- 操作系统 / 计组 基础（MIT 6.1810、jyy 作为补充，不把它当 Linux 驱动课）  
- Git / Shell 基础

避坑共识：

- LDD3 作为概念参考可读，API 以 `docs.kernel.org` 与目标内核源码为准  
- BSP 定制 ≠ 从零移植整棵内核；UVC 采集 ≠ 自写 sensor/ISP  
- 早期可用 QEMU 演练「模块/字符设备/中断语义」，但 GPIO/pinctrl/外设一定要在真实板验证

## 12 周主线

按周的目标、资源、具体实验与「验收证据」见：[`docs/roadmap.md`](docs/roadmap.md)  
— 规划按每周约 15–20 小时设计，属于「学习规划假设」，不是你的承诺；时间不足可按文中「最小路径」执行。

## 目录结构

```
docs/           路线图与说明
tracks/driver/  驱动主线实验导航（本次改版新增）
tracks/classic/ MCU/RTOS 等补充（归档保留）
tracks/edge/    端侧 AI 选修（归档保留）
resources/      精选公开资料（标注免费/付费边界、板卡与内核版本）
experiments/    可复现实验记录（禁止虚构结果）
```

## 怎么用

1. 打开 [`docs/roadmap.md`](docs/roadmap.md)，按当前周次执行主线任务。  
2. 进入 `tracks/driver/` 查看「按驱动链路组织」的实验导航与验收清单。  
3. 实验记录只写 **真实跑通** 的内容，模板见 [`experiments/README.md`](experiments/README.md)。  
4. 资源以 [`resources/upstream.md`](resources/upstream.md) 为准；外链 404 会被剔除或标「自行检索」。  
5. 求职向关键词见 [`resources/interview.md`](resources/interview.md)。

## 板卡与环境（建议）

- 无板月份：先在 QEMU/x86 上完成「模块/字符设备/poll 语义」  
- 有板后：GPIO/IRQ/I2C 必须在板上完成；RK3568 可作为跟课候选（不强制购买/不指定具体板型）
- 交叉编译与 SDK：以目标板官方工具链为准（Yocto/Buildroot/厂商 SDK 皆可）

## 进度（自行更新）

| 轨道 | 当前节点 | 状态 | 备注 |
| --- | --- | --- | --- |
| Driver 主线 | Week ☐1–12 | ☐ 未开始 / ☐ 进行中 / ☐ 完成 | |
| 选修 · V4L2/DRM | ☐ | | |
| 选修 · 端侧 AI | ☐ | | |

周次：第 __ / ~12 周（规划假设） · 上次复盘：____-__-__

## 原则

- **简体中文**写说明；路径、芯片、工具名保留英文。  
- **不编造**板测数据、benchmark、假链接。  
- 大模型权重、本地 venv 等不进仓（见 `.gitignore`）。

## License

MIT © 2026 Roman Rose — 见 [`LICENSE`](LICENSE)。
