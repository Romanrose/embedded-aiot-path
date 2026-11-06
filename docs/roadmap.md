# 12 周学习路线 · Linux BSP/驱动 + 薄用户态（端侧 AI 可选进阶）

定位：服务于「国产芯片原厂 BSP/驱动/SDK」与「终端嵌入式 Linux 驱动+应用」岗位。端侧 AI 与 V4L2/DRM 为选修，放在基础完成后。

总说明：
- 规划强度：每周约 15–20 小时（仅为规划假设，非你的承诺）  
- 时间不足时的「最小路径」已在每周列出  
- 早期可用 QEMU/x86 做模块/字符设备/`poll` 语义；GPIO/pinctrl/I2C 必须在真实板验证  
- 内核 API 以 `docs.kernel.org` 与目标内核源码为准；LDD3 仅作概念参考

依赖与建议：
- 目标板候选：RK3568（示例多、资料全）；不强制购买或指定板型  
- 交叉编译：以板卡 SDK/Yocto/Buildroot 或官方工具链为准  
- 用户态示例建议用 C/C++11，编译用 CMake 或 Make 皆可

---

## 第 1 月：模块 / 字符设备 / Platform + DTS（含 Kernel Labs 练习）

### Week 1 · 模块开发与内核构建入门
- 目标
  - 能在本机或 QEMU/x86 上编译并加载最小内核模块（`insmod/rmmod`，`dmesg` 验证）
  - 熟悉 out-of-tree Kbuild、内核源码目录结构与 symbols 查询
- 资源
  - docs.kernel.org：kernel-hacking、core-api、driver-api 模块相关章节  
  - Linux Kernel Labs：vm setup、device drivers 开篇（内核版本提示：站点基于 5.10.14）
- 实验与验收
  - 写一个 `hello` 模块与一个导出 `procfs`/`debugfs` 信息的模块（任选其一）  
  - 证据：`dmesg` 截图 + 模块源码与 `Makefile`（放入 `experiments/`）
- 最小路径
  - 仅完成 `hello` 模块与 `insmod/rmmod`/`modinfo` 基操

### Week 2 · 字符/杂项设备：`open/read/write` 与 `ioctl`
- 目标
  - 基于 `misc` 或字符设备框架实现最小设备，支持 `open/read/write`，可选 `ioctl`
  - 了解 udev 创建设备节点
- 资源
  - docs.kernel.org：driver-api char/misc  
  - Linux Kernel Labs：character device labs（注意与现代 API 差异）  
- 实验与验收
  - 用户态用 `cat/echo` 或一段 C 程序访问 `/dev/yourdev`，观察数据路径  
  - 证据：最小用户态程序、`dmesg`、设备节点截图
- 最小路径
  - `misc` 设备 + `read/write` 即可

### Week 3 · `poll`/同步与缓冲设计
- 目标
  - 在 Week 2 设备上增加阻塞/非阻塞与 `poll`/`select` 行为  
  - 设计一个简易环形缓冲，理解并发与 wakeup
- 资源
  - docs.kernel.org：poll/select、wait queues、memory-barriers（阅后即止）  
  - Linux Kernel Labs：deferred work/同步相关章节
- 实验与验收
  - 两个用户态线程：生产/消费，验证 `poll` 能被事件唤醒  
  - 证据：用户态日志 + 内核 `pr_info` 片段
- 最小路径
  - 仅实现 `poll` 和一次成功的阻塞唤醒

### Week 4 · Platform 总线与 Device Tree（DTS/overlay）
- 目标
  - 写一个最小 Platform 驱动（`probe/remove`），用 DTS/overlay 绑定到虚拟/真实设备  
  - 会读简化后的 `compatible`/资源映射，理解 `of_match_table`
- 资源
  - docs.kernel.org：devicetree 与 driver-api platform  
  - Bootlin training materials：device tree 与 platform 入门（免费 slides/labs）
- 实验与验收
  - 在 QEMU ARM 或真实板上加载 overlay 使驱动 `probe` 成功  
  - 证据：`/sys/bus/platform/drivers/.../` 绑定关系截图 + `dmesg`
- 最小路径
  - 不做 overlay，也可用现成 DTS 节点绑定一次成功的 `probe`

---

## 第 2 月：GPIO/IRQ/I2C + 小项目（板级验证）

### Week 5 · 现代 gpiod + IRQ
- 目标
  - 仅使用 **descriptor-based** GPIO consumer API（`gpiod_get*` 等），避免旧 `gpio_*` API  
  - 完成一个外部按键或中断源的中断服务（上/下降沿）
- 资源
  - docs.kernel.org：gpio 与 `gpio/consumer.rst`  
  - libgpiod（用户态对照理解，内核实验仍在驱动内完成）
- 实验与验收（需真实板）
  - 内核驱动中统计中断次数；用户态读取统计值或通过 netlink/char 设备读到  
  - 证据：接线/引脚表 + 真实中断计数变化日志
- 最小路径
  - 无合适中断源时先做输出口 `gpiod_set_value_cansleep` 闪烁与 sysfs 只读状态

### Week 6 · I2C 设备驱动：挂接到 IIO 或 hwmon
- 目标
  - 为一个常见 I2C 传感器（或 EEPROM）写最小 client 驱动  
  - 将数据接入 IIO（首选）或 hwmon 子系统，出现在 `/sys/bus/iio/devices/...` 或 `/sys/class/hwmon/...`
- 资源
  - docs.kernel.org：i2c、iio、hwmon  
  - Bootlin materials：I2C labs 与示例代码（按板挑选）  
  - 厂商 SDK 的现成驱动可作为参考，但请核对内核版本与 API
- 实验与验收（需真实板）
  - 使用 `i2cdetect`/`i2cget`（对照）与子系统导出的 sysfs 节点读取一次有效数据  
  - 证据：器件地址扫描 + sysfs 读数（或明确「板上无器件，仅完成驱动框架」）
- 最小路径
  - 若缺实物器件：完成 `probe`/`remove` + 地址探测与失败路径，标注「待器件验证」

### Week 7 · 用户态 C/C++ 程序：与驱动配合
- 目标
  - 用 C/C++ 写一个最小守护进程式程序，读取 IIO/hwmon/字符设备数据，做一次本地落盘或打印  
  - 熟悉 `epoll` 事件循环与简单错误恢复
- 资源
  - `man epoll`、`poll`、`select`；CMake/Make 任选；`libsensors`（可选）
- 实验与验收
  - 在目标板上交叉编译并运行，展示 1 分钟的稳定读数/日志  
  - 证据：编译命令、二进制尺寸、运行日志
- 最小路径
  - 单线程 `read()` 拉取 + 定时器，无 `epoll`

### Week 8 · 小项目联通与移植到板卡 SDK
- 目标
  - 将 Week 5–7 串成一条小链路：中断事件 → 触发一次 I2C 读取 → 用户态记录  
  - 学会用目标板 SDK/交叉工具链完成 out-of-tree 构建与部署（可用 DKMS 作为 PC 辅助）
- 资源
  - 板厂 SDK 文档（如 RK、NXP 等）；docs.kernel.org：kbuild/out-of-tree
- 实验与验收
  - 在目标板冷启动后，手动加载驱动并运行用户态，演示 1 次端到端事件  
  - 证据：完整步骤清单 + 真实终端录屏/截图（若不便录屏则详细日志）
- 最小路径
  - 本机构建 + 板上 `scp`/`adb` 部署，不做系统镜像裁剪

---

## 第 3 月：稳定性 / 故障恢复 / 复盘面试（选修：V4L2 或 DRM）

### Week 9 · 稳定性与错误路径
- 目标
  - 覆盖 `probe` 失败、`remove`、并发竞争（简单场景）等错误路径  
  - 了解 `lockdep`、`CONFIG_DEBUG_*`、内核 fault-injection
- 实验与验收
  - 用 debugfs 或内核参数触发一次可控错误并恢复  
  - 证据：`dmesg`/`trace` 片段与「如何恢复」说明
- 最小路径
  - 仅覆盖 `probe` 失败与资源释放正确性

### Week 10 · 压测与长期运行
- 目标
  - 写最小的压力脚本（反复 `open/read/close` 或重复中断触发），观察内存泄漏与 log 抑制  
  - 记录「1 小时稳定运行」的日志要点与资源占用
- 实验与验收
  - 证据：脚本、`/proc/meminfo` 变化、内核日志关键行
- 最小路径
  - 10 分钟短压测

### Week 11 · 复盘与面试准备
- 目标
  - 对照 `resources/interview.md` 勾选，准备可展示的链路图与踩坑总结  
  - 编写一页 README：你的板卡、驱动、用户态、稳定性方法
- 实验与验收
  - 复盘文档进仓；检查所有实验是否可复现（按 `experiments/README.md`）
- 最小路径
  - 仅完成链路图与勾选单

### Week 12 · 选修：V4L2 或 DRM（二选一）
- 目标
  - V4L2：走通「I2C sensor → MIPI CSI → ISP → /dev/videoX」的最小采集（无 ISP/调参亦可，或使用 UVC 摄像头做框架理解）  
  - DRM：理解 KMS 基本对象，跑通 plane/connector 的最小显示（板厂 demo 可做对照）
- 资源
  - docs.kernel.org：media 与 drm 子系统  
  - 板厂/社区示例（注意版本与 SoC 限制）
- 实验与验收
  - 证据：`media-ctl`/`v4l2-ctl` 或 `modetest` 的运行输出，链路图
- 最小路径
  - 仅完成 UVC 采集或用 `modetest` 点亮显示，不自写 sensor/ISP

---

## 端侧 AI（可选扩展，主线完成后）
- 参见 `tracks/edge/`（已标为选修）：ONNX Runtime / TensorRT / RKNN / QNN  
- 只列公开资料与免费入口；需付费/账号的部分以官网为准  
- 结合本仓的小项目，在用户态用 ORT/RKNN 做一次最小前后处理集成（非必做）

---

## 每周交付清单（统一）
- 一页实验说明（环境/步骤/结果/下一步）放入 `experiments/YYYY-MM-DD-wNN-.../README.md`  
- 关键日志与配置最小副本  
- 外链均验证可达；403 标注「无法验证」即可；404 直接剔除或改为「自行检索」

更新总览表时同步改根目录 [`README.md`](../README.md) 的进度占位。
