# 上游资料（精选）

原则：**只放有把握的公开 https**；不确定的写「名称 + 自行检索」，避免死链与假链。版本会变，以你克隆日的 upstream README 为准。

## 官方 / 文档入口（自行打开核对）

| 主题 | 怎么找 | 备注 |
| --- | --- | --- |
| ONNX | 自行检索 `onnx` GitHub / onnx.ai | 导出与算子规范 |
| ONNX Runtime | https://github.com/microsoft/onnxruntime | 多 EP 推理 |
| PyTorch 导出 | 自行检索 PyTorch 官方 `torch.onnx` 文档 | 与版本强相关 |
| NVIDIA TensorRT | 自行检索 NVIDIA TensorRT 文档中心 | 需账号看部分文档时以官网为准 |
| NVIDIA Jetson 推理示例 | https://github.com/dusty-nv/jetson-inference | 视觉部署经典入门仓 |
| Jetson AI Lab | 自行检索 `NVIDIA jetson-ai-lab` | 教程与容器生态，名称以官网为准 |
| FreeRTOS | https://github.com/FreeRTOS/FreeRTOS | 内核与示例 |
| 瑞芯微 RKNN | 自行检索 `rknn-toolkit2` / Rockchip RKNN | 工具与芯片文档版本多，核对平台号 |
| 高通 QNN | 自行检索 Qualcomm AI Engine / QNN 文档 | 许可与下载流程走官网 |

## 社区 / 学习向（链接有把握才给出）

| 名称 | URL 或检索提示 | 用途 |
| --- | --- | --- |
| dusty-nv/jetson-inference | https://github.com/dusty-nv/jetson-inference | Jetson 上检测/分类等 pipeline |
| wang-xinyu/tensorrtx | https://github.com/wang-xinyu/tensorrtx | TensorRT 层实现与示例（自行核对 license 与模型） |
| TensorRT 相关解读/博客 | 自行检索「tensorrt insight」等关键词 | 辅助理解 engine/profile；注意过时风险 |
| Zephyr RTOS | https://github.com/zephyrproject-rtos/zephyr | 若走 Zephyr 路线 |
| ESP-IDF | https://github.com/espressif/esp-idf | 若用 ESP32 系做 E0/E1 |

## 经典嵌入式手册习惯

- 目标芯片 **Reference Manual / Datasheet**：只从原厂官网下载，本清单不镜像 PDF。  
- 板级原理图：以板厂 GitHub 或文档包为准，自行检索板型号。

## 使用建议

1. 克隆或收藏前先 `git ls-remote` / 打开网页确认仓库仍在。  
2. 在实验笔记中写：**commit 或 release tag**，避免「跟过时教程步步错」。  
3. 发现断链：改本文件为「自行检索」，不要留 404。
