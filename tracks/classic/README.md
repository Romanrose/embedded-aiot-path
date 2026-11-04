# Classic 轨（嵌入式基础）

目标：建立 **MCU → RTOS →（可选）Linux 驱动** 的可迁移基础，支撑后续边缘板上的外设、通信与稳定性工作。

## 节点一览

| 节点 | 目录 | 状态 |
| --- | --- | --- |
| E0 | [E0/](E0/) | MCU / GPIO / UART / I2C |
| E1 | [E1/](E1/) | FreeRTOS · bare-metal vs Linux |
| E2–E6 | （后续补目录） | 见 [`docs/roadmap.md`](../../docs/roadmap.md) |

## 建议工具链（按你实际板卡填写）

- IDE / SDK：________（如 STM32CubeIDE、ESP-IDF、Zephyr 等）
- 调试器：________（SWD / JTAG）
- 串口工具：________

## 记录规范

- 通断、引脚、波特率等写入 `experiments/` 对应子目录。  
- **未实测** 的标「待板上验证」，不要写假波形或假寄存器读数。
