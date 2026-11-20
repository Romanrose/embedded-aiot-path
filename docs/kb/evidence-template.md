# 学习与实验证据模板

用于 `experiments/YYYY-MM-DD-wNN-<slug>/README.md`

```markdown
# <标题>

- 状态：done | in_progress | blocked
- 环境：VM/QEMU | 实验板(<型号>) | 仅编译验证
- 目标内核：uname -r=<...>；KDIR=<path or N/A>；ARCH/CROSS_COMPILE=<值或 N/A>
- BSP/SDK：<名称/版本>（若适用）
- 目的：一句话

## 资料与版本
- 来源 1：URL（访问日期：YYYY-MM-DD；核验范围：正文/目录/仅 200；许可：公开/需账号/付费）
- 来源 2：...

## 步骤
1. ...
2. ...

## 结果与证据
- 关键命令与截屏/日志（仅必要片段）
- 差异/失败与原因定位

## 机制复述（不看资料尝试写 3–5 句）
- ...

## 边界与下一步
- 本次未验证处与原因
- 下一周/次计划
```

