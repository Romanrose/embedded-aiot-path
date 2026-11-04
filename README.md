# embedded-aiot-path

面向 **AIoT / 边缘 AI** 的双轨学习仓：经典嵌入式（MCU → RTOS → 驱动）与边缘推理（SoC / NPU / 模型部署）并行推进。

> 作者：Roman Rose（厦大软工研二）  
> 背景：LLM / Agent → 转向边缘侧落地  
> 公开仓：https://github.com/Romanrose/embedded-aiot-path  
> 与 `llm_learn` **分开维护**，本仓专注硬件、系统与端侧推理链路。

## 为什么双轨

边缘 AI 不是「会训模型」或「会写 MCU」单点技能，而是：

| 经典嵌入式（约 4） | 边缘 AI（约 6） |
| --- | --- |
| 外设、中断、驱动、RTOS/Linux | 模型转换、量化、推理引擎、板端部署 |

比例约 **4 : 6**（经典 : 边缘），可按周复盘微调，不必机械凑课时。

## 双轨地图

```
E0  MCU / GPIO / UART / I2C          L0  SoC vs MCU · NPU/GPU · 部署概览
E1  FreeRTOS / bare-metal vs Linux   L1  PyTorch→ONNX→INT8→ORT/TRT/RKNN/QNN
E2  （规划）驱动与外设深入            L2  （规划）板端 benchmark / 功耗
E3  （规划）Linux 驱动入门            L3  （规划）多模型 / pipeline
E4  （规划）通信与协议                L4  （规划）与云/Agent 协同
E5  （规划）系统联调                  L5  （规划）作品集级项目
E6  （规划）综合项目
```

详细里程碑见 [`docs/roadmap.md`](docs/roadmap.md)。

## 目录结构

```
docs/           路线图与说明
tracks/classic/ E0–E6 经典轨
tracks/edge/    L0–L5 边缘轨
resources/      上游资料与面试清单
experiments/    可复现实验记录（禁止虚构结果）
```

## 怎么用

1. 打开 [`docs/roadmap.md`](docs/roadmap.md)，按当前周次勾选 E / L 节点。  
2. 进入对应 `tracks/.../Ex` 或 `Ly` 的 README，按 checklist 做实验。  
3. 实验记录只写 **真实跑通** 的内容，模板见 [`experiments/README.md`](experiments/README.md)。  
4. 上游链接以 [`resources/upstream.md`](resources/upstream.md) 为准；不确定的条目标「自行检索」，勿粘假 URL。  
5. 求职向关键词见 [`resources/interview.md`](resources/interview.md)。

## 进度占位（自行更新）

| 轨道 | 当前节点 | 状态 | 备注 |
| --- | --- | --- | --- |
| Classic | E0 | ☐ 未开始 / ☐ 进行中 / ☐ 完成 | |
| Classic | E1 | ☐ | |
| Edge | L0 | ☐ | |
| Edge | L1 | ☐ | |

周次：第 __ / ~12 周 · 上次复盘：____-__-__

## 原则

- **简体中文**写说明；路径、芯片、工具名保留英文。  
- **不编造**板测数据、benchmark、假链接。  
- 大模型权重、本地 venv 等不进仓（见 `.gitignore`）。

## License

MIT © 2026 Roman Rose — 见 [`LICENSE`](LICENSE)。
