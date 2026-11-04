# L1 · PyTorch → ONNX → INT8 → ORT / TensorRT / RKNN / QNN

**目标**：打通 **至少一条** 从训练侧权重到可推理引擎的路径。优先桌面 ORT；有板再换对应厂商工具。

## 总览 checklist

- [ ] 固定一个 **小模型**（如轻量分类/检测；避免一上来就大 LLM）  
- [ ] 记录：框架版本、Python、CUDA（若有）、模型输入 shape  
- [ ] 导出 ONNX，并用 ONNX checker / netron（可选）看图  
- [ ] FP32（或 FP16）在 ORT 跑通，得到 **基线** latency（真实测量）  
- [ ] 再尝试 INT8 PTQ（工具随后端变）  
- [ ] 对比精度抽检集（自己准备小集即可；无集则定性说明风险）

## 路径 A · ONNX Runtime（推荐先做）

- [ ] `onnxruntime` CPU EP 推理脚本  
- [ ] （可选）CUDA / TensorRT EP — 以你机器与官方文档为准  
- [ ] 记录 session 配置与线程数

## 路径 B · TensorRT（NVIDIA 生态）

- [ ] 了解：ONNX → TensorRT engine 的官方流程  
- [ ] 参考上游（见 `resources/upstream.md`）：如 `dusty-nv/jetson-inference`、Jetson AI Lab 相关资料  
- [ ] 仅在 **真实 Jetson/NVIDIA 环境** 记录 engine 构建日志与测速

## 路径 C · RKNN（瑞芯微）

- [ ] 查阅当前 RKNN-Toolkit 文档版本（自行检索官网/GitHub）  
- [ ] ONNX → RKNN 转换与 PC 模拟 / 板上 runtime  
- [ ] 记录芯片平台（如 RK3588 等）与工具版本

## 路径 D · QNN / 高通系

- [ ] 以高通官方 QNN / AI Engine 文档为准  
- [ ] 搞清：模型转换工具名称与目标 DSP/NPU 后端命名  
- [ ] 无开发板时只做文档精读 + 环境安装尝试，状态标「未上板」

## 量化 checklist（通用）

- [ ] PTQ vs QAT：本阶段以 PTQ 为主即可  
- [ ] 校准数据是否代表性（写下数据来源，勿假造 mAP）  
- [ ] 失败时：哪些算子被 fallback；如何缩小复现模型

## 验收

1. 一条可复现命令序列（写入 `experiments/.../README.md`）。  
2. 环境表：OS、CPU/GPU、运行时版本。  
3. **真实** 延迟数字或明确「仅转换成功、未测速」。  
4. （有板）同一模型在两种后端的对比表 — 无数据则留空表头。
