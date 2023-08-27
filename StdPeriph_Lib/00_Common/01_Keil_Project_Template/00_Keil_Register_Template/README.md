# Folder Structure

```
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
        main.crf                        /* 交叉引用文件,记录函数和全局变量的引用信息 */
        main.d                          /* 预处理信息文件,包含了预处理后的宏和条件编译信息 */
        main.o                          /* 对象文件,包含目标代码 */
        startup_stm32f10x_hd.d
        startup_stm32f10x_hd.o
        Template-REG.axf                /* keil download: keil 下载文件 */
        Template-REG.build_log.htm      /* 编译日志文件,包含了编译过程的详细日志 */
        Template-REG.hex                /* serial download：串口下载文件 */
        Template-REG.htm
        Template-REG.lnp                /* 链接映射文件,展示链接后代码在目标芯片的布局信息 */
        Template-REG.sct                /* Scatter-Load Description File */
```
