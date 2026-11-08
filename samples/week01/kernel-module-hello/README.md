# kernel-module-hello（教学示例）

用途：演示最小 out-of-tree 模块的构建与加载/卸载、参数与日志。请在教学 VM/QEMU 或实验机上加载；在日常宿主机可做“仅编译验证”，不要直接加载。

## 构建

仅编译验证（不加载）：

```bash
make KDIR=/lib/modules/$(uname -r)/build
```

针对 VM/QEMU/板（示例变量，按你的环境决定是否需要）：

```bash
make KDIR=<kernel build dir> ARCH=<arm64|x86|...> CROSS_COMPILE=<aarch64-linux-gnu-> 
```

生成产物：`hello.ko`

## 加载/卸载（在 VM/QEMU 或实验机）

```bash
sudo insmod ./hello.ko name=Alice
dmesg | tail -n 50
sudo rmmod hello
dmesg | tail -n 50
```

预期在 `dmesg` 看到：
- 加载：`hello: init, hello Alice`
- 卸载：`hello: exit, goodbye Alice`

## 清理

```bash
make clean
```

注意：本示例未在你的实际目标环境中运行前，不可声称“已通过”；请将真实执行记录写入 `experiments/`。

