# 工程实验导航（复用本仓路线）

说明：不重复造目录，统一复用本仓既有路线与示例；本页只做“做什么/用何证据”的索引。

基础（第 1 月）
- Week 1：环境与最小模块（hello）  
  - 入口：`../weeks/week01.md`（如已在 main 存在）与 `../../samples/week01/`  
  - 证据：`hello.ko` 构建快照；VM/实验机一次 `insmod/rmmod` 的 dmesg 截图；用户态 hello 输出（含 `uname -r`）
- Week 2：字符/杂项设备 + `read/write` + `poll`（在 VM/QEMU 或本机）  
  - 证据：阻塞/非阻塞与 `poll` 唤醒的用户态/内核对应日志
- Week 3：同步与缓冲设计（环形缓冲/等待队列/并发）  
  - 证据：并发访问日志、短读与超时路径说明
- Week 4：Platform + DTS（绑定/`of_match_table`/资源获取/错误回滚）  
  - 证据：`probe` 成功与缺资源失败各一次，sysfs 绑定关系与日志

板级（第 2 月）
- Week 5：GPIO + IRQ（descriptor API，active-low，计数）  
  - 证据：接线/引脚表、dmesg 与用户态读取统计值
- Week 6：I2C 设备驱动 → IIO/hwmon  
  - 证据：`i2cdetect`、sysfs 节点读数或“仅完成 `probe` + 待器件验证”的说明
- Week 7：用户态 C/C++ 守护进程（epoll/超时/错误处理）  
  - 证据：1 分钟稳定运行日志与二进制信息
- Week 8：小项目联通与 SDK 构建  
  - 证据：冷启动后端到端事件链路日志与步骤清单

稳定性（第 3 月）
- Week 9：错误路径与恢复  
- Week 10：压测与长期运行  
- Week 11：复盘与面试  
- Week 12（选修）：V4L2 或 DRM

统一安全边界
- 不在生产主机加载自编模块；QEMU/VM 先演练；GPIO/pinctrl/I2C 必须板级验证  
- 不混刷不同厂商固件；BSP/SDK/内核/板型/工具链需记录版本

