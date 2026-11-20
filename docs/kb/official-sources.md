# 官方原始文献/设计依据（首批）

- 设备模型与匹配  
  - docs.kernel.org：Driver binding 与设备模型  
    - 链接：`https://docs.kernel.org/driver-api/driver-model/binding.html`  
    - 用途：设备/驱动/总线的注册、匹配、`probe/remove`、sysfs 关系；解释“模块≠设备”。  
    - 验证：在字符设备与 Platform 驱动实验中对照 `probe` 与 sysfs。

- Device Tree（DT）  
  - docs.kernel.org：devicetree 指南与规范  
    - 链接：`https://docs.kernel.org/devicetree/`  
    - 用途：不可自枚举外设的硬件描述；`compatible` 匹配、资源属性。  
    - 验证：选择已有节点完成一次最小 `probe`，并测试缺资源时报错路径。

- GPIO（descriptor-based consumer API）  
  - docs.kernel.org：GPIO consumer  
    - 链接：`https://docs.kernel.org/driver-api/gpio/consumer.html`  
    - 用途：使用 descriptor API 访问 GPIO，处理 active-low 等语义。  
    - 验证：板上完成一次输入/输出与中断计数。

- I2C 与标准子系统  
  - docs.kernel.org：I2C、IIO、hwmon  
    - 链接：`https://docs.kernel.org/i2c/index.html`、`https://docs.kernel.org/iio/index.html`、`https://docs.kernel.org/hwmon/`  
    - 用途：区分控制器与设备；优先接入标准 ABI。  
    - 验证：为一款传感器完成 IIO/hwmon 最小读取（或仅 `probe` + 标注待器件验证）。

- 其他（参考）  
  - LDD3（历史概念参考，API 过时）  
    - 链接：`https://lwn.net/Kernel/LDD3/`  
    - 用途：补充历史背景；示例代码勿直接移植到 5.10/6.x。  
    - 验证：仅对照概念，不做编译承诺。

