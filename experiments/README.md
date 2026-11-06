# experiments · 可复现实验记录

本目录只存放 **真实执行过** 的实验说明、配置快照、日志摘录与结果。  

## 禁止

- 禁止编造 FPS、mAP、功耗、寄存器读数、波形结论  
- 禁止用「预期结果」冒充「实测结果」  
- 禁止提交大权重、大数据集、虚拟环境目录（见根目录 `.gitignore`）  

未做完的实验：状态写 `blocked` / `in_progress`，结果区留空或写「未测」。

## 建议目录布局

```text
experiments/
  README.md                          ← 本文件
  2026-11-04-e0-uart-loopback/       ← 日期 + 节点 + 短标题
    README.md                        ← 必填：环境与步骤
    notes.md                         ← 可选：踩坑
    logs/                            ← 可选：串口/构建日志摘录
    configs/                         ← 可选：精简后的配置副本
  2026-11-10-l1-onnx-ort-cpu/
    README.md
    ...
```

命名：`YYYY-MM-DD-<eN|lN>-<slug>/`，slug 用英文短横线。

也可使用周序命名：`YYYY-MM-DD-wNN-<slug>/`（如 `2026-11-20-w05-gpio-irq/`）。

## 单次实验 README 模板

```markdown
# <标题>

- 状态：done | in_progress | blocked
- 轨道节点：E0 / L1 / ...
- 日期：YYYY-MM-DD（Asia/Shanghai）
- 板卡 / 机器：型号；无则写 desktop
- 目标：一句话

## 环境

- OS：
- 工具链 / SDK / 运行时版本：
- 模型（若有）：名称、输入 shape、精度、来源 commit/tag

## 步骤

1. …
2. …（命令可复制）

## 结果

- 仅写实测。无数据则写「未测」并说明原因。
- 延迟：__ ms（是否含前后处理：是/否；重复次数：__）

## 结论与下一步

- …
```

## 与 tracks 的关系

- `tracks/**/README.md`：学什么、checklist。  
- `experiments/**`：某天实际做了什么、得到了什么。  

合并 PR 或推公开仓前：扫一眼是否有机密 Wi-Fi 密码、内网地址、未脱敏日志。
