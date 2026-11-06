# 驱动主线 · 实验导航（按链路组织）

定位：本目录提供「真实可执行」的实验任务与验收清单，按驱动链路推进：模块 → 字符/杂项设备（read/write/poll）→ Platform + DTS → 现代 gpiod GPIO + IRQ → I2C 设备驱动挂 IIO/hwmon → C/C++ 用户态程序 → 稳定性/故障恢复。选修结尾：V4L2 或 DRM。

配套周计划与资源请看：`docs/roadmap.md`。本导航聚焦「做什么、交付什么」。

## 0. 准备
- 目标内核版本与板卡 SDK 版本号记录在 `experiments/` 首次实验 README 中  
- 早期可用 QEMU/x86 练习模块/字符设备/`poll`；GPIO/IRQ/I2C 必须板上验证

## 1. 内核模块（Week 1）
- 任务
  - out-of-tree 模块：`hello` 与一个导出 `procfs`/`debugfs` 的模块（二选一）  
  - `insmod/rmmod`、`lsmod`、`modinfo`
- 验收
  - `dmesg` 中模块加载/卸载日志；源码与 `Makefile` 入 `experiments/`

## 2. 字符/杂项设备（Week 2）
- 任务
  - 用 `misc` 或字符设备框架实现 `open/read/write`，可选 `ioctl`  
  - udev 创建设备节点
- 验收
  - `/dev/yourdev` 可被 `cat/echo` 或最小 C 程序访问；`dmesg` 有访问日志

## 3. 同步与 `poll`（Week 3）
- 任务
  - 在 2 的设备上实现阻塞/非阻塞与 `poll`/`select`  
  - 简易环形缓冲并在唤醒点打印一行日志
- 验收
  - 两线程生产/消费演示一次阻塞唤醒；用户态与内核日志配对清晰

## 4. Platform + DTS（Week 4）
- 任务
  - 写最小 Platform 驱动（`probe/remove`），用 DTS 节点或 overlay 绑定  
  - 导出一个 sysfs 属性或 debugfs 条目
- 验收
  - `dmesg` 看到 `probe` 成功；`/sys/bus/platform/drivers/...` 有绑定关系

## 5. gpiod + IRQ（Week 5）
- 任务
  - 仅用 descriptor-based gpiod API 完成输入/输出之一  
  - 对输入：实现中断计数（上/下降沿）；对输出：周期闪烁并在 sysfs 只读一个状态
- 验收（需板）
  - 引脚表与接线图；中断计数/状态变化的真实日志

## 6. I2C 设备驱动 → IIO/hwmon（Week 6）
- 任务
  - 为板上可得 I2C 器件写最小 client（或参考 SDK 驱动做最小化），完成 `probe`/`remove`  
  - 接到 IIO（优先）或 hwmon，导出一个读数
- 验收（需板）
  - `i2cdetect` 截图；`/sys/bus/iio/devices/...` 或 `/sys/class/hwmon/...` 的真实读数  
  - 缺器件时：完成地址探测与失败路径，状态标「待器件验证」

## 7. 用户态 C/C++ 程序（Week 7）
- 任务
  - 用 C/C++ 写一个最小守护进程：读取 IIO/hwmon/字符设备数据，落盘或打印  
  - 可选：`epoll` 事件循环
- 验收
  - 交叉编译在板上运行 ≥1 分钟；提供日志与二进制尺寸

## 8. 小项目联通与 SDK 构建（Week 8）
- 任务
  - 串起：GPIO/IRQ 事件 → 触发 I2C 读取 → 用户态记录  
  - 学会用板卡 SDK/交叉工具链完成 out-of-tree 构建与部署
- 验收
  - 冷启动后手动加载与运行的完整步骤；一次端到端事件链路的日志

## 9–10. 稳定性与压测（Week 9–10）
- 任务
  - 错误路径（`probe` 失败、并发退出等）；短压测/长跑与日志抑制  
  - 了解 `lockdep`/fault-injection 并选做一次
- 验收
  - 触发一次可控错误并恢复的证据；压力脚本与资源占用对比

## 11. 复盘（Week 11）
- 任务
  - 汇总链路图、踩坑与面试勾选：见 `resources/interview.md`
- 验收
  - 一页公开可读的项目 README（不含隐私/内网信息）

## 12. 选修：V4L2 或 DRM（二选一，Week 12）
- V4L2：理解 pipeline，UVC 或板厂示例跑通最小采集  
- DRM：用 `modetest` 跑通最小显示，理解 KMS 基本对象  
- 验收：工具输出与链路图；不要求自写 sensor/ISP

## 可选扩展：端侧 AI
- 主线完成后，可在用户态用 ORT/RKNN/QNN 等做一次最小推理集成；详见 `tracks/edge/`

---

通用规则：只记录真实可复现实验；外链 404 直接剔除或标「自行检索」；403 备注「无法验证」即可。

