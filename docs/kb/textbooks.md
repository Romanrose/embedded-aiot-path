# 分层教材（首批）

目标：按“工程可落地优先、上游一手参考配套”的顺序组织，不重复两套同义教材。

工程向（主线）
- 板商驱动课程/文档（示例：LubanCat RK 系列）  
  - 作用：紧贴 BSP/SDK 与实板外设，覆盖模块→字符→Platform/DT→GPIO/IRQ→I2C/SPI 等工程环节  
  - 边界：不是上游标准的全部做法；需对照 docs.kernel.org  
  - 链接：`https://doc.embedfire.com/linux/rk356x/driver/zh/latest/`

体系参考
- Bootlin Linux Kernel slides + labs  
  - 作用：以设备模型/子系统为主线的体系讲解；labs 需指定板  
  - 链接：`https://bootlin.com/doc/training/linux-kernel/`

补充（历史/概念）
- LDD3  
  - 作用：经典概念参考  
  - 边界：面向 2.6 时代，API 不可直接照抄  
  - 链接：`https://lwn.net/Kernel/LDD3/`

邻域（OS 基础，择需而读）
- OSTEP、MIT 6.1810、jyy OS  
  - 作用：并发、内存、I/O 抽象理解  
  - 边界：不替代 Linux 驱动子系统学习  
  - 链接：`https://pages.cs.wisc.edu/~remzi/OSTEP/`、`https://pdos.csail.mit.edu/6.1810/2025/overview.html`、`https://jyywiki.cn/OS/2026/`

