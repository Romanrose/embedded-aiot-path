# 发展脉络（非年表式）

1) 从“设备即文件”到“标准子系统并行”  
- 问题：字符设备是否覆盖一切设备抽象？  
- 机制：Linux 从早期“VFS 下的设备文件”出发，逐步形成网络、块、输入、媒体、显示、传感（IIO/hwmon）等子系统，各自定义面向用户/用户态的稳定 ABI 与内核内部接口。  
- 边界：并非所有场景都适合自定义 `ioctl` 的私有字符设备；若子系统已提供稳定 ABI，应优先挂接。  
- 来源：docs.kernel.org driver-api 与各子系统首页；LDD3 概念仅作历史参考。  
- 验证：用 Linux Kernel Labs 的字符设备任务理解基本路径，再在板上完成一次 IIO/hwmon 的最小接入对照。

2) 从板级硬编码到设备模型/设备树（Device Model/DT）  
- 问题：不同板卡上相同控制器/外设的资源与连线如何解耦？  
- 机制：设备模型抽象 device/driver/bus；对不可自枚举外设，以 Device Tree/ACPI 提供“硬件描述”，驱动通过 `compatible` 与资源表完成匹配与获取。  
- 边界：DT 不是驱动实现，不保证设备被实例化、资源即可用；也不是“所有设备都归 Platform”。  
- 来源：docs.kernel.org driver-model 与 devicetree 文档。  
- 验证：在 QEMU/VM 先理解模块与字符设备；到板上用已存在的 DTS 节点完成一次最小 Platform `probe`，不写虚假节点。

3) BSP 与主线的分与合  
- 问题：BSP 与 SDK 与主线内核是什么关系？  
- 机制：BSP 是交付集合（Bootloader/Kernel/Drivers/Configs/Build/文档）；SDK 是配套工具/示例；两者服务具体 SoC/板。上游主线是社区内核，接口与代码风格受维护者治理。  
- 边界：能在 BSP 跑通 ≠ 已主线可用；厂商示例不等价于标准做法。  
- 来源：厂商文档与 MAINTAINERS；docs.kernel.org（UAPI vs 内核内部接口）。  
- 验证：同一功能分别用“BSP 示例 + 上游推荐子系统”各做一次最小验证，记录差异与限制。

