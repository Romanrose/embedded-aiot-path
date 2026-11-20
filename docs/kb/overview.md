# 综合导读（地图与关系线）

目标：在不写“大而全词典”的前提下，给出驱动开发中最容易混淆的关系与两条关键路径，说明“查哪里、怎么证实”。

两条主干关系线
1) 设备描述/枚举 → 设备对象(device) → 总线匹配(bus match) → 驱动绑定(probe) → 资源获取与子系统挂接  
   - 设备从何而来：固有可枚举（PCI/USB）与不可枚举（板级外设，以 Device Tree/ACPI 描述）路径不同  
   - probe 成功≠业务可用：还需拿到 GPIO/IRQ/I2C/regmap 等资源并正确接入 IIO/hwmon/input 等标准 ABI
2) 应用 → 系统调用/ABI → 子系统（IIO/hwmon/input/media/drm/…） → 设备驱动 → 控制器/硬件，事件再反向回传  
   - 典型链路：IRQ → 延后处理（tasklet/work）→ 更新共享条件 → 唤醒等待队列 → 用户态 `read/poll` 感知  
   - 工具链（交叉编译、打包、SDK）是构建/交付支撑，不属于运行时这一条链的“下一层”

常见混淆与边界
- “加载模块=设备就绪”是错误的：模块（代码单元）≠设备实例，对应关系由设备模型+总线匹配决定  
- “DT 就是驱动”是错误的：DT 仅描述硬件连接与属性，它既不执行寄存器访问，也不保证设备被实例化  
- “所有设备都是 Platform”是错误的：I2C/SPI/PCIe/USB 等各有总线，Platform 只是不可自枚举设备的一类承载  
- `uname -r` 相同不保证 `.ko` 可加载：还受内核配置、符号版本、编译器、导出符号等影响（内核内部 ABI 无稳定承诺）  
- QEMU 能演练模块/字符设备/同步语义，但不能代替板上 GPIO/pinctrl/电气连接与真实外设行为的验证

推荐查证顺序
1) 官方文档优先：docs.kernel.org（driver model、devicetree、gpio consumer、i2c、iio、hwmon…）  
2) 结构化课程：Linux Kernel Labs（QEMU 侧 device driver 练习）、Bootlin kernel training（slides + 指定实板）  
3) 厂商 BSP/教程：对照 SoC/板型/内核版本（示例多、细节近），但不等价于上游标准做法  
4) 源码与 MAINTAINERS：确认子系统与接口的“当下做法”与维护者  
5) 再做实验：从模块→字符/`poll`→DT/Platform→GPIO/IRQ→I2C→用户态

如何在本仓落地
- 查“是什么/为什么/去哪查”：本知识库  
- 决定“何时做什么”：`../roadmap.md`  
- “如何验证”：`lab-navigation.md`（调用本仓已有 Week1 与 tracks/driver）与 `../../experiments/` 模板

