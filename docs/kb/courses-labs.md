# 课程与 lab（首批）

卡片说明：学什么/环境与版本/第一实验/免费与付费边界/不覆盖什么/如何与本仓路线衔接。

1) Linux Kernel Labs（Device Drivers）  
- 学什么：字符设备、阻塞/非阻塞、`poll`、ioctl、异步通知等；提供 QEMU/VM 环境与作业。  
- 环境与版本：站点构建基于 5.10.14（页面下注有提示），使用 QEMU/x86 或 ARM；页面结构随时间可能调整。  
- 第一实验：在 VM 上完成字符设备的基本数据路径与 `poll`。  
- 免费/付费边界：公开讲义与作业免费。  
- 不覆盖：板级 GPIO/pinctrl/电气连接与实物 I2C 外设。  
- 衔接：本仓第 1 月后半与第 2 月前半可复用其任务作为“先在 VM 演练”的步骤。  
- 入口：`https://linux-kernel-labs.github.io/refs/heads/master/labs/device_drivers.html`

2) Bootlin Linux Kernel Training  
- 学什么：设备模型、字符设备、`probe`/`remove`、I2C 串行外设与指定板上的实操。  
- 环境与版本：slides 与实验 PDF 免费公开；实验板以 BBB/BeaglePlay/i.MX93 FRDM 为主；未见 kernel 课的 QEMU 实验包。  
- 第一实验：按所选板卡的串口/按钮/I2C lab 完成一次最小 `probe` 与数据读取。  
- 免费/付费边界：slides/data 免费；授课/答疑收费。  
- 不覆盖：你的特定 SoC/板型；需自行对照 BSP/SDK。  
- 衔接：本仓第 2 月 GPIO/IRQ/I2C 阶段优先参考对应板卡实验。  
- 入口：`https://bootlin.com/doc/training/linux-kernel/`

3) 板商中文教程（以 LubanCat RK 系为例）  
- 学什么：模块→字符→设备模型/Platform→DT→GPIO/IRQ/I2C/SPI 等，紧贴厂商 BSP。  
- 环境与版本：以 RK356x 系列为例，文档常见内核 5.10.160；需锁定板型/分支/提交。  
- 第一实验：模块与字符设备在本机/VM 演练；到板上完成一次 GPIO/IRQ 或 I2C 的最小链路。  
- 免费/付费边界：在线文档免费；设备/板卡需自备。  
- 不覆盖：上游标准做法的所有细节（需配合 docs.kernel.org）。  
- 衔接：与本仓第 2 月板级实验衔接；不可与其他厂商固件“混刷”。  
- 入口：`https://doc.embedfire.com/linux/rk356x/driver/zh/latest/`

4) 先修 OS（仅补充，不是 Linux 驱动主课）  
- MIT 6.1810、jyy OS：理解并发/内存/设备与 OS 抽象；不覆盖 Linux 驱动子系统与 BSP。  
- 入口：`https://pdos.csail.mit.edu/6.1810/2025/overview.html`、`https://jyywiki.cn/OS/2026/`（阅读作概念补充即可）

