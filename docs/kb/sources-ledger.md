# 来源账本（首版）

规则
- 仅收录“已访问且记录范围”的来源；每条注明 URL、组织/作者、版本或页面注记、访问日期（UTC）、核验范围（读正文/读目录/仅 200）、许可边界（公开/需账号/付费）、与本库条目关联。  
- 不能下载或再分发的材料不上传到仓库。滚动文档注意版本风险。

首批记录（2026-11-20，UTC）

1) docs.kernel.org — Driver binding / device model  
- URL：`https://docs.kernel.org/driver-api/driver-model/binding.html`  
- 组织：Linux kernel 文档  
- 版本/注记：滚动页面  
- 访问日期：2026-11-20  
- 核验范围：读正文  
- 许可：公开  
- 关联：`core-mechanisms.md`（模块≠设备；match/probe 路径）、`official-sources.md`

2) docs.kernel.org — devicetree  
- URL：`https://docs.kernel.org/devicetree/`  
- 组织：Linux kernel 文档  
- 版本/注记：滚动页面  
- 访问日期：2026-11-20  
- 核验范围：读正文与索引  
- 许可：公开  
- 关联：`core-mechanisms.md`（DT 不是驱动；并非一切皆 Platform）、`official-sources.md`

3) docs.kernel.org — gpio consumer / i2c / iio / hwmon  
- URL：`https://docs.kernel.org/driver-api/gpio/consumer.html`、`https://docs.kernel.org/i2c/index.html`、`https://docs.kernel.org/iio/index.html`、`https://docs.kernel.org/hwmon/`  
- 组织：Linux kernel 文档  
- 访问日期：2026-11-20  
- 核验范围：读正文  
- 许可：公开  
- 关联：`core-mechanisms.md`（GPIO/pinctrl、I2C 控制器 vs 设备、标准 ABI 优先）

4) Linux Kernel Labs — Device Drivers lab  
- URL：`https://linux-kernel-labs.github.io/refs/heads/master/labs/device_drivers.html`  
- 组织：UPB / Linux Kernel Labs  
- 版本/注记：站点基于 5.10.14（页脚注）  
- 访问日期：2026-11-20  
- 核验范围：读正文  
- 许可：公开  
- 关联：`courses-labs.md`、`lab-navigation.md`

5) Bootlin — Linux Kernel training materials  
- URL：`https://bootlin.com/doc/training/linux-kernel/`  
- 组织：Bootlin  
- 访问日期：2026-11-20  
- 核验范围：读目录与部分 slides/labs 索引（未逐个实验 PDF）  
- 许可：slides/data 公开，授课收费  
- 关联：`courses-labs.md`、`textbooks.md`

6) LubanCat RK 系列驱动文档（示例板商）  
- URL：`https://doc.embedfire.com/linux/rk356x/driver/zh/latest/`  
- 组织：EmbedFire/野火  
- 访问日期：2026-11-20  
- 核验范围：读目录与若干章节片段（未逐项跑实验）  
- 许可：在线文档公开  
- 关联：`courses-labs.md`、`textbooks.md`

7) LDD3（历史概念参考）  
- URL：`https://lwn.net/Kernel/LDD3/`  
- 组织：LWN  
- 访问日期：2026-11-20  
- 核验范围：读目录与部分章节（注意过时）  
- 许可：公开  
- 关联：`official-sources.md`、`textbooks.md`

备注：若某来源只得到 200 或被 403 拦截，将标注“仅状态码/无法验证正文”，不据此声称“已核正文”。

