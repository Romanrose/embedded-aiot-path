# 嵌入式 Linux 驱动知识库（第一版）

定位与作用
- 主线：Linux BSP/驱动 + 薄 C/C++ 用户态，兼容原厂 BSP/SDK；MCU/RTOS 为邻域补充；端侧 AI 作为可选拓展。
- 解决三个“常迷糊”的问题：是什么（概念与边界）、为什么（设计依据/权衡）、去哪查（官方一手与维护者入口），并指向“如何验证”（课程与 lab）。
- 本知识库补充“解释与查证凭据”；12 周路线仍负责“何时做什么、具体实验怎么做”。两者通过 README 互联，不互相覆盖。

阅读顺序（建议）
1) 综合导读（地图与两条关系线）→ 2) 核心机制与邻域关系 → 3) 课程与 lab → 4) 官方原始文献/设计依据 → 5) 分层教材 → 6) 机构/维护者/讨论入口  
任何条目均给出：问题→机制→边界/代价→来源→如何验证。

目录
- 综合导读与地图：`overview.md`
- 发展脉络：`history.md`
- 核心机制与邻域关系（≥8 条）：`core-mechanisms.md`
- 课程与 lab：`courses-labs.md`
- 官方原始文献/设计依据：`official-sources.md`
- 分层教材：`textbooks.md`
- 机构/维护者/讲义讨论入口：`institutions.md`
- 概念地图·分歧与权衡：`concepts-map.md`
- 十道情境理解题（题面不含答案）：`exam-questions.md`
- 评分参考（独立页）：`exam-scoring.md`
- 工程实验导航（复用本仓路线与示例）：`lab-navigation.md`
- 学习证据模板：`evidence-template.md`
- 来源账本（精确 URL/版本/访问日期/核验范围/许可边界）：`sources-ledger.md`

与本仓其他入口
- 12 周路线：`../roadmap.md`（本库解释“是什么/为什么/去哪查”，路线负责“何时做什么”）  
- 驱动实验导航：`../..//tracks/driver/README.md`（本库的 lab 导航会直接复用，不另造重复目录）  
- Week 1 可执行指南与示例：`../weeks/week01.md` 与 `../../samples/week01/`（如已存在于 main）

