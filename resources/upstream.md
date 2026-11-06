# 上游资料（精选 · 驱动主线优先）

原则：**只放有把握的公开 https**；不确定项写「名称 + 自行检索」，避免死链与假链。版本会变，以你克隆日的 upstream README 为准。若遇登录/许可，按官网为准，仓库不镜像付费或闭源材料。

## Linux 驱动 / BSP 官方文档

| 主题 | URL | 备注 |
| --- | --- | --- |
| Kernel docs 总入口 | https://docs.kernel.org/ | 以本入口为主查 API/子系统 |
| Device Drivers API | https://docs.kernel.org/driver-api/ | 驱动主线必读 |
| Core API | https://docs.kernel.org/core-api/ | kref、workqueue、内存等 |
| Devicetree Spec/Guide | https://docs.kernel.org/devicetree/ | 绑定规范与写法 |
| gpiolib consumer | https://docs.kernel.org/driver-api/gpio/consumer.html | 仅用 descriptor API |
| I2C Subsystem | https://docs.kernel.org/i2c/index.html | I2C client/adapter |
| IIO Subsystem | https://docs.kernel.org/iio/index.html | 传感器首选挂载 |
| hwmon Subsystem | https://docs.kernel.org/hwmon/ | 温度/电压类 |
| Media (V4L2) | https://docs.kernel.org/userspace-api/media/ | 选修 |
| DRM/KMS | https://docs.kernel.org/gpu/ | 选修 |

内核版本边界：请在实验笔记标注你的目标内核版本；API 以对应版本源码为准。LDD3（Linux Device Drivers 3rd）仅作概念参考，版本老（2.6.x）。

## 培训材料（免费部分）与板卡依赖

| 名称 | URL | 免费/付费边界 | 板卡/内核提示 |
| --- | --- | --- | --- |
| Bootlin Training Materials | https://bootlin.com/training/ 与 https://github.com/bootlin/training-materials | slides/labs/data 免费；授课收费 | Kernel 驱动课 labs 以 BBB/BeaglePlay/i.MX93 为主；系统课有 QEMU 包 |
| Linux Kernel Labs | https://linux-kernel-labs.github.io/ | 公开免费 | 讲义基于 5.10.14；有 x86 VM/QEMU ARM/i.MX6UL |
| ldd3（LWN 托管） | https://lwn.net/Kernel/LDD3/ | 公开免费 | 概念可读，API 以 docs.kernel.org 与源码为准 |

国内板商/资料（示例；注意版本与付费边界）：

| 名称 | URL | 说明 |
| --- | --- | --- |
| 野火 LubanCat（RK 系）文档 | 自行检索 `doc.embedfire.com LubanCat RK 驱动` | 在线文档免费，配套代码仓公开；示例内核常见 5.10.160 |
| 韦东山 百问网 | https://ldd.100ask.net/ | 文档站部分公开；完整视频/资料付费；板 i.MX6ULL/STM32MP1 |
| 迅为 iTOP-RK3568 | 自行检索 `topeet RK3568 驱动` | 教程系列；核对章节与内核版本 |

## QEMU / 通用工具
- QEMU：早期练习模块/字符设备/`poll`；不要把 GPIO/pinctrl/I2C 的板级实验替换为 QEMU  
- libgpiod：用户态 GPIO 控制与观察（版本与内核/headers 对齐）  
- lm-sensors：用户态读取 hwmon（`sensors`）  

## 端侧 AI（选修所用公开资料）

| 主题 | 怎么找 | 备注 |
| --- | --- | --- |
| ONNX | 自行检索 `onnx` GitHub / onnx.ai | 导出与算子规范 |
| ONNX Runtime | https://github.com/microsoft/onnxruntime | 多 EP 推理 |
| PyTorch 导出 | 自行检索 PyTorch 官方 `torch.onnx` 文档 | 与版本强相关 |
| NVIDIA TensorRT | 自行检索 NVIDIA TensorRT 文档中心 | 部分文档需账号 |
| NVIDIA Jetson 推理示例 | https://github.com/dusty-nv/jetson-inference | 视觉部署经典入门仓 |
| Jetson AI Lab | 自行检索 `NVIDIA jetson-ai-lab` | 官方教程与容器生态 |
| 瑞芯微 RKNN | 自行检索 `rknn-toolkit2` / Rockchip RKNN | 平台工具多版本，核对芯片 |
| 高通 QNN | 自行检索 Qualcomm AI Engine / QNN 文档 | 许可与下载流程走官网 |

## 经典嵌入式（补充）
- FreeRTOS：https://github.com/FreeRTOS/FreeRTOS  
- Zephyr：https://github.com/zephyrproject-rtos/zephyr  
- ESP-IDF：https://github.com/espressif/esp-idf

## 使用建议
1. 克隆或收藏前先 `git ls-remote` / 打开网页确认仓库仍在。  
2. 在实验笔记中写：**commit 或 release tag**，避免「跟过时教程步步错」。  
3. 发现断链：改本文件为「自行检索」，不要留 404；遇 403 标注「无法验证」。
