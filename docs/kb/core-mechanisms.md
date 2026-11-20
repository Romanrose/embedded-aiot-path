# 核心机制与邻域关系（至少 8 条）

条目格式：问题 → 机制 → 边界/代价 → 关联 → 来源 → 如何验证

1) 交叉编译与模块兼容性  
- 问题：`uname -r` 相同为何 `.ko` 仍可能无法加载？  
- 机制：内核内部 ABI 无稳定承诺；模块还受 Kconfig、编译器、内核导出符号/版本（symbol versioning）、构建产物路径影响。  
- 边界/代价：同版本字符串但不同配置/补丁/工具链会导致 `invalid module format`；用户态 ABI 与内核内部 API 不可混谈。  
- 关联：`modinfo`、`vermagic`、`CONFIG_MODVERSIONS`。  
- 来源：docs.kernel.org kbuild/modules、core-api；厂商 SDK 说明。  
- 如何验证：记录 `KDIR`、`ARCH/CROSS_COMPILE`、`vermagic`，在 VM 与板上各尝试一次加载。

2) 模块(module) ≠ 设备(device)  
- 问题：`insmod` 成功但驱动 `probe` 未执行？  
- 机制：设备是否被创建取决于总线与设备枚举；匹配表（`of_match_table`/`id_table`）决定是否进入 `probe`。  
- 边界/代价：内建驱动也可绑定设备；模块加载只是“代码可用”，不是“设备就绪”。  
- 关联：device/driver/bus、sysfs、platform/i2c/spi/usb/pci。  
- 来源：docs.kernel.org driver-model/binding。  
- 如何验证：构造“加载成功但不匹配”的实验，观察 `probe` 未触发与 sysfs 设备节点。

3) Device Tree 不是驱动，且非一切皆 Platform  
- 问题：DTS 节点存在是否等价于驱动就绪？  
- 机制：DT 仅提供描述（地址/中断/连线/属性），驱动仍需匹配并获取资源。I2C/SPI/PCIe 等有各自总线；Platform 主要承载不可自枚举外设。  
- 边界/代价：节点不当或缺资源会导致 `probe` 失败；`compatible` 只是匹配线索，不代表实现细节。  
- 关联：`of_property_*`、`devm_*`、regmap、GPIO/IRQ 获取。  
- 来源：docs.kernel.org devicetree 指南与 driver-api platform。  
- 如何验证：在已有 DTS 节点上做最小 `probe`，并测试缺资源时报错路径。

4) 资源生命周期与 devm  
- 问题：资源泄漏/在途任务如何安全回收？  
- 机制：`devm_*` 自动回收“与 device 生命周期绑定”的资源，但不能替代对 workqueue/tasklet/irq 的显式管理；错误路径需逐步回滚。  
- 边界/代价：卸载时未取消在途工作/未禁用中断会造成 use-after-free 或崩溃。  
- 关联：`devm_add_action_or_reset`、`flush_work`、`synchronize_irq`。  
- 来源：docs.kernel.org core-api、driver-api。  
- 如何验证：在 `probe` 途中注入失败并重复加载/卸载，检查资源是否一致释放。

5) 事件到用户态：IRQ → 延后处理 → 唤醒 → `read/poll`  
- 问题：为何中断里通常不做重活？用户态如何被唤醒？  
- 机制：硬中断尽快退出；延后处理（tasklet/work）更新共享条件并 `wake_up` 等待队列；`poll`/`select/epoll` 根据条件变化返回。  
- 边界/代价：唤醒只是“条件变化通知”，用户态仍需复查；错误地在中断上下文睡眠会死机。  
- 关联：wait queues、`fasync`、non-blocking I/O。  
- 来源：docs.kernel.org core-api（waitqueue、workqueue）。  
- 如何验证：字符设备实验里实现阻塞/非阻塞与 `poll`，配合用户态双线程演示一次唤醒。

6) GPIO 逻辑值与 pinctrl  
- 问题：逻辑 1/0 与物理高低电平为何可能“相反”？  
- 机制：GPIO descriptor 支持 active-low 等语义；pinctrl 负责复用/上下拉/驱动能力等电气配置。  
- 边界/代价：QEMU 无法证明电气连接正确；真实板需核对原理图与引脚复用。  
- 关联：`gpiod_get*`、`GPIO_ACTIVE_LOW`、pinctrl state。  
- 来源：docs.kernel.org gpio/consumer 与 pinctrl 文档。  
- 如何验证：板上读取/驱动一个 active-low 设备，核对逻辑与电平。

7) I2C 控制器 vs 设备，优先标准 ABI  
- 问题：为 I2C 传感器写驱动时，应该暴露怎样的接口？  
- 机制：控制器驱动负责总线传输；客户端驱动解释寄存器并优先挂 IIO/hwmon/input 等标准 ABI；扫描到地址不代表功能正确。  
- 边界/代价：随意写私有 `ioctl` 造成维护与兼容困难。  
- 关联：`i2c_client`、regmap、IIO/hwmon。  
- 来源：docs.kernel.org i2c、iio、hwmon。  
- 如何验证：为常见传感器完成最小 IIO 通路（无器件时仅完成 `probe` 与失败路径，并标注“待器件验证”）。

8) 薄用户态应用：短读/超时/错误恢复  
- 问题：为何 `read` 可能短读？如何设计最小守护进程？  
- 机制：内核可能分段提供数据；非阻塞与超时需要事件循环（`epoll`/定时器）；错误码和撤销策略要清晰。  
- 边界/代价：不能以 `chmod 777` 粗暴放权；日志与限流要考虑长期运行。  
- 关联：POSIX I/O、`poll`/`epoll`、CMake/Make 构建。  
- 来源：`man 2 read`、各子系统 UAPI 文档。  
- 如何验证：Week 7 的最小用户态示例中增加超时与错误处理。

9) BSP 是交付集合，不是“运行时下一层”  
- 问题：BSP 与驱动/内核的层级是什么？  
- 机制：BSP 打包 Boot/Kernel/Drivers/Configs/SDK 与文档，服务具体 SoC/板型交付；运行时层级仍以“应用→ABI→子系统→驱动→硬件”为准。  
- 边界/代价：不同 BSP 间移植需重评接口差异；“能在 BSP 跑通”不代表“已主线”。  
- 关联：Yocto/Buildroot/厂商 SDK、UAPI。  
- 来源：厂商文档；docs.kernel.org UAPI。  
- 如何验证：记录 BSP 版本/板型/内核版本，并以最小功能在上游推荐子系统再做一遍。

