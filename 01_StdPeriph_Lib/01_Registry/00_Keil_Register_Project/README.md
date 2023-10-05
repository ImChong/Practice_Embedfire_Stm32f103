# Folder Structure

```shell
.
│  Embedfire_F103.uvguix.29142          /* 包含了 GUI 的个性化设置，这是最不重要的，也是最容易更改的 */
│  Embedfire_F103.uvoptx                /* 包含了更多个性化和可选的项目设置，主要用于调试 */
│  Embedfire_F103.uvprojx               /* keil 项目文件：包含了构建项目所需的所有核心信息 */
│  main.c                               /* 主函数 */
│  README.md
│  startup_stm32f10x_hd.s               /* 汇编编写的启动文件 */
│  stm32f10x.h                          /* 实现了内核之外的外设的寄存器映射 */
│
├─DebugConfig
│      Template-REG_STM32F103VE_1.0.0.dbgconf           /* 存储调试配置信息 */
│
├─Listings
│      startup_stm32f10x_hd.lst         /* 源代码与生成的汇编或机器代码之间的映射，以及其他关于编译过程的信息 */
│      Template-REG.map                 /* 描述程序的内存布局 */
│
└─Objects
        Embedfire_F103_Template-REG.dep /* 依赖关系文件,记录目标文件依赖的源文件信息 */
        main.crf                        /* 包含了源代码与其生成的目标代码之间的交叉引用信息。这通常用于更高级的代码分析或文档生成 */
        main.d                          /* 包含了源文件的依赖信息。它通常用于 GNU Make 或其他构建系统，在进行增量编译时确定哪些文件需要重新编译 */
        main.o                          /* 编译后生成的目标文件。这些 .o 文件会被链接器合并成一个可执行文件或库 */
        startup_stm32f10x_hd.d
        startup_stm32f10x_hd.o
        Template-REG.axf                /* keil download: keil 下载文件 */
        Template-REG.build_log.htm      /* 编译日志文件,包含了编译过程的详细日志 */
        Template-REG.hex                /* serial download：串口下载文件 */
        Template-REG.htm                /* 编译报告，提供了关于构建过程的各种统计信息，比如代码大小、数据段大小等 */
        Template-REG.lnp                /* 存储了链接器的设置信息，如内存布局、入口点等。它通常用于配置更复杂的链接行为 */
        Template-REG.sct                /* Scatter-Load Description File */
```
