# user-hello（教学示例）

最小 C 程序：打印一行问候与当前内核版本，用于核对工具链与运行环境。

## 编译

```bash
make        # 或：gcc -O2 -Wall -Wextra hello.c -o hello
```

## 运行

```bash
./hello
# 预期输出（示例）：
# hello, userspace! kernel=6.1.0-... arch=x86_64
```

将真实输出与 `file ./hello` 的架构信息贴入 `experiments/` 的周度记录中。

