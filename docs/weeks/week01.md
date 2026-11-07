# Week 1 · 环境与最小内核模块（hello）

本周目标：建立安全可控的学习环境，完成最小内核模块的构建与加载/卸载（仅在教学 VM/QEMU 或实验机），并理解内核版本/headers 匹配、Kbuild 基础与交叉编译概念；写一个最小的用户态 C 程序用于环境核对。字符设备与更复杂接口放到第 2 周。

安全说明（强制）：
- 不在日常工作/生产主机内核上尝试加载自编模块；优先使用教学 VM 或 Linux Kernel Labs/QEMU 路线。
- 有板时，加载操作仅在实验板的内核上进行，严格匹配 headers 与内核版本；无板时，不做真实板载加载。
- Mac/Apple Silicon：请用 Linux 教学 VM（UTM/VirtualBox/VMware 等），不要在 macOS 上尝试 Linux 内核模块。

推荐资料（本周用到）：
- Kbuild · Modules（官方）: https://docs.kernel.org/kbuild/modules.html
- Kbuild 总览（官方）: https://docs.kernel.org/kbuild/kbuild.html
- Kernel 文档首页（官方）: https://docs.kernel.org/
- Linux Kernel Labs（总入口；含 Device Drivers 实验与 VM 说明）: https://linux-kernel-labs.github.io/ （在站内检索“virtual machine / VM setup / device drivers”）
- Bootlin 培训材料（免费部分；嵌入式 Linux 含 QEMU 实验，驱动课需要真实板）: https://bootlin.com/doc/training/embedded-linux/ 、https://bootlin.com/training/kernel/
- C 语言手册（标准库/语法，查缺补漏用）: https://en.cppreference.com/w/c
- GNU make 手册: https://www.gnu.org/software/make/manual/make.html

交付物（本周验收证据，任一环境达成即可）：
- 一次“仅编译验证”的 hello 模块（生成 `.ko`）
- 在教学 VM/QEMU 或实验机内核上成功 `insmod`/`rmmod` 一次（dmesg 日志截取）
- 最小用户态 C 程序输出（含 `uname -r`）
- 每次 session 的简短复盘（卡点/下一步）

目录索引：
- 示例源码：`samples/week01/kernel-module-hello/` 与 `samples/week01/user-hello/`
- 本周说明：`docs/weeks/week01.md`（本文件）
- 路线总览：`docs/roadmap.md`（Week 1 处有入口）

---

## Session 1/6 · 先修与环境策略（60–90 分钟）
目标
- 了解本仓安全边界与本周范围
- 补齐“C 指针最小心智 + Makefile 最小用法”
- 确定本周采用的运行/测试环境（教学 VM/QEMU 或实验板）

资源
- C 语言手册（只查指针/数组/函数指针基础）: https://en.cppreference.com/w/c
- GNU make 手册（变量/目标/规则基础）: https://www.gnu.org/software/make/manual/make.html

步骤
1) 选择环境路径：
   - 无板：使用 Linux 教学 VM 或 Linux Kernel Labs 提供的 QEMU/VM 路线做后续加载测试
   - 有板：确认厂商 SDK/交叉工具链版本，并记录目标内核版本（例如 `/boot/config-*`、`uname -r` 与 kernel sources/headers tag）
2) 阅读本仓的安全边界，决定“编译仅验证 vs 在 VM/板上加载测试”的本周目标
3) 为后续 session 预建一个工作目录（建议与本仓分开），避免污染宿主机系统目录

常见报错与提示
- 在宿主 x86_64 编译出的 `.ko` 不能在 ARM 板上加载（架构不匹配）
- 没有内核 headers 时无法构建模块；仅做“编译验证”也需要对应 headers 或完整源码树

验收
- 记录选用环境（VM/QEMU/板）与核对到的目标内核版本（未定则写“未定，仅做编译验证”）

---

## Session 2/6 · 内核/headers/交叉编译概念（60 分钟）
目标
- 理解“目标内核版本/配置 与 headers”的匹配关系
- 搭建仅编译所需的最小 Kbuild 环境变量

资源
- Modules（Kbuild）: https://docs.kernel.org/kbuild/modules.html
- Kbuild 概览: https://docs.kernel.org/kbuild/kbuild.html

步骤
1) 阅读上面两篇官方文档，明确 out-of-tree 模块常用构建入口：`make -C <kernel-build-dir> M=$PWD modules`
2) 准备 `KDIR`：
   - 仅编译验证（宿主 Linux）：`KDIR=/lib/modules/$(uname -r)/build`（不进行加载）
   - 目标是 VM/QEMU 或板：将 `KDIR` 指向对应内核源码的构建目录（确保与将要加载的 kernel 版本一致）
3) 了解交叉编译变量（概念即可，本周可不实际使用）：
   - `ARCH=<arm|arm64|x86|...>`，`CROSS_COMPILE=<gcc 前缀>`

常见报错与提示
- `No rule to make target modules`：`KDIR` 指向的不是已配置/已构建过的内核构建目录
- `fatal error: linux/...: No such file or directory`：缺少 headers

验收
- 在你的笔记中写下本机会使用的 `KDIR` 与是否需要 `ARCH/CROSS_COMPILE`

---

## Session 3/6 · 教学 VM / QEMU 路线占坑（60–120 分钟）
目标
- 选定并记录一条可复现实验内核的 VM/QEMU 路线，用于后续加载测试

推荐（任选其一，按官方任务书执行，不在此处自创命令）：
- Linux Kernel Labs 站点（总入口）: https://linux-kernel-labs.github.io/  
  - 在站内查找 “Device Drivers” 与 “Virtual Machine / VM setup” 相关实验页面并按其步骤准备 VM/QEMU 环境
- Bootlin 嵌入式 Linux 公开材料（含 QEMU 实验；偏系统构建）: https://bootlin.com/doc/training/embedded-linux/

提示
- 我们不在此文档重复具体命令，以官方教材为准，避免版本漂移
- 记录下你所使用的 kernel 版本、QEMU 命令行或 VM 配置快照，后续复现实验需要

验收
- 成功启动一次教学 VM/QEMU 并能登录 shell（截取 boot 日志或 `uname -a`）
- 若本周只做“编译验证”，记录“加载测试待 VM/板到位”

---

## Session 4/6 · 最小 hello 模块（60–90 分钟）
目标
- 写并编译一个最小内核模块，支持可读参数与基础日志

源码位置
- `samples/week01/kernel-module-hello/`

关键点
- `obj-m := hello.o` 的 Kbuild Makefile
- `module_param` / `MODULE_PARM_DESC`  
- `pr_info/pr_warn` 与 `__init/__exit`

编译
- 仅编译验证（不加载）：`make KDIR=/lib/modules/$(uname -r)/build`（或导出同名环境变量）
- 针对 VM/QEMU/板：`make KDIR=<对应 kernel 构建目录> ARCH=<目标架构> CROSS_COMPILE=<前缀>`（示例变量，按你的环境决定是否需要）

常见报错与提示
- `Unknown symbol`：加载时常见；本周若仅编译验证可先不处理
- `taints kernel`：加载非 GPL 模块的提示；示例使用 GPL 许可证避免该提示

验收
- 生成 `hello.ko`（截图 `ls -l`）

---

## Session 5/6 · 加载/卸载与参数日志（30–60 分钟）
目标
- 在教学 VM/QEMU 或实验机上完成一次 `insmod` / `rmmod`，并观测参数与日志

步骤（在 VM/QEMU 或实验机内进行）
1) `scp` 或共享目录方式将 `hello.ko` 置于目标系统
2) `sudo insmod ./hello.ko name=Alice`（参数名以示例源码为准）
3) `dmesg | tail -n 50` 观察 `pr_info` 输出；`cat /proc/modules | head` 确认模块在列
4) `sudo rmmod hello` 并再次 `dmesg` 观察卸载日志

常见报错与提示
- `invalid module format`：构建用的 headers 与运行内核不匹配；回 Session 2 重新匹配 `KDIR`
- 权限/SELinux/AppArmor：按目标系统安全策略处理；教学 VM 一般默认允许

验收
- `dmesg` 中包含带参数的问候语与卸载提示两段日志

---

## Session 6/6 · 用户态最小 C 程序与复盘（30–60 分钟）
目标
- 写一个最小 C 程序并在目标系统运行，用于核对工具链与内核版本，准备后续第 2 周用户态实验

源码位置
- `samples/week01/user-hello/`

步骤
1) 在本机或 VM/板上编译：`make`（或直接 `gcc -O2 -Wall hello.c -o hello`）
2) 运行：`./hello`，输出一行问候与 `uname -r`
3) 将本周 6 次 session 的要点写入 `experiments/2026-11-xx-w01-hello/README.md`（时间与目录名按模板）

常见报错与提示
- 交叉编译到板：需要目标交叉工具链与 sysroot；本周可先在 VM/目标板原生编译

验收
- 贴出程序输出与 `file hello` 的架构信息（例如 `ELF 64-bit LSB pie x86-64`）

---

## 本周复盘模板（复制到你的实验目录）

```markdown
# Week 1 复盘

- 路径：仅编译验证 | VM/QEMU 加载 | 板上加载
- 目标内核版本：<uname -r> / <kernel tag> / <未知>
- KDIR：<path or N/A>；ARCH/CROSS_COMPILE：<值或 N/A>
- 成果：
  - [ ] hello.ko 编译成功（截图）
  - [ ] VM/QEMU/板上 insmod/rmmod（dmesg 截图）
  - [ ] 用户态 hello 输出与 uname -r（截图）
- 卡点与解决：
- 下周计划（Week 2 预告：字符/杂项设备 + read/write + poll 设计）
```

备注
- 示例源码仅用于教学；未在你的实际环境中运行前，不可声称“已通过”；`experiments/` 只记录真实执行过的步骤与结果。

