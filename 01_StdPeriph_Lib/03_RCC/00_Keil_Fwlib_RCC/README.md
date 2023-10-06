# 使用固件库操作的项目模板

使用固件库操作的项目模板

```shell
.                                           # 项目根目录
│  keilkill.bat                                 # 清除 keil 生成的中间文件
│  README.md                                    # 本说明文件
│
├─.vscode                                   # VSCode 配置文件夹
│      c_cpp_properties.json                    # VSCode C/C++ 配置文件
│      keil-assistant.log                       # Keil Assistant 日志文件
│      uv4.log                                  # Keil 编译日志文件
│      uv4.log.lock                             # Keil 编译日志文件锁
│
├─Doc                                       # 文档
│      README.md                                # 项目文档
│
├─Libraries
│  ├─CMSIS                                  # CMSIS 标准库
│  │  │  core_cm3.c                             # CMSIS 核心库
│  │  │  core_cm3.h                             # CMSIS 核心库头文件
│  │  │  stm32f10x.h                            # stm32f103 的头文件：包含各寄存器的地址
│  │  │  system_stm32f10x.c                     # 系统初始化文件
│  │  │  system_stm32f10x.h                     # 系统初始化文件头文件
│  │  │
│  │  └─startup                             # 启动文件
│  │          startup_stm32f10x_cl.s
│  │          startup_stm32f10x_hd.s            # 本项目使用
│  │          startup_stm32f10x_hd_vl.s
│  │          startup_stm32f10x_ld.s
│  │          startup_stm32f10x_ld_vl.s
│  │          startup_stm32f10x_md.s
│  │          startup_stm32f10x_md_vl.s
│  │          startup_stm32f10x_xl.s
│  │
│  └─STM32F10x_StdPeriph_Driver             # STM32F10x 标准外设库
│      ├─inc                                    # 头文件
│      │      misc.h                                # 杂项
│      │      stm32f10x_adc.h                       # ADC
│      │      stm32f10x_bkp.h                       # 备份寄存器
│      │      stm32f10x_can.h                       # CAN (Controller Area Network)：CAN 控制器
│      │      stm32f10x_cec.h                       # CEC (Consumer Electronics Control)：消费电子控制
│      │      stm32f10x_crc.h                       # CRC (Cyclic Redundancy Check)：循环冗余校验
│      │      stm32f10x_dac.h                       # DAC (Digital-to-Analog Converter)：数模转换器
│      │      stm32f10x_dbgmcu.h                    # 调试
│      │      stm32f10x_dma.h                       # DMA (Direct Memory Access)：直接存储器访问控制器
│      │      stm32f10x_exti.h                      # 外部中断
│      │      stm32f10x_flash.h                     # FLASH：内部 FLASH
│      │      stm32f10x_fsmc.h                      # FSMC (Flexible Static Memory Controller)：外部 SRAM/NOR FLASH
│      │      stm32f10x_gpio.h                      # GPIO (General Purpose Input/Output)：通用输入输出
│      │      stm32f10x_i2c.h                       # I2C
│      │      stm32f10x_iwdg.h                      # 独立看门狗
│      │      stm32f10x_pwr.h                       # 电源
│      │      stm32f10x_rcc.h                       # RCC：时钟树
│      │      stm32f10x_rtc.h                       # RTC：实时时钟
│      │      stm32f10x_sdio.h                      # SDIO：SD 卡
│      │      stm32f10x_spi.h                       # SPI
│      │      stm32f10x_tim.h                       # TIM
│      │      stm32f10x_usart.h
│      │      stm32f10x_wwdg.h
│      │
│      └─src                                    # 源文件
│              misc.c
│              stm32f10x_adc.c
│              stm32f10x_bkp.c
│              stm32f10x_can.c
│              stm32f10x_cec.c
│              stm32f10x_crc.c
│              stm32f10x_dac.c
│              stm32f10x_dbgmcu.c
│              stm32f10x_dma.c
│              stm32f10x_exti.c
│              stm32f10x_flash.c
│              stm32f10x_fsmc.c
│              stm32f10x_gpio.c
│              stm32f10x_i2c.c
│              stm32f10x_iwdg.c
│              stm32f10x_pwr.c
│              stm32f10x_rcc.c
│              stm32f10x_rtc.c
│              stm32f10x_sdio.c
│              stm32f10x_spi.c
│              stm32f10x_tim.c
│              stm32f10x_usart.c
│              stm32f10x_wwdg.c
│
├─Project
│  │  Embedfire_F103_Fwlib_Template.uvguix.29142
│  │  Embedfire_F103_Fwlib_Template.uvoptx
│  │  Embedfire_F103_Fwlib_Template.uvprojx
│  │
│  ├─DebugConfig
│  │      Fwlib_Template_Rcc_Overclock_STM32F103VE_1.0.0.dbgconf
│  │      Fwlib_Template_STM32F103VE_1.0.0.dbgconf
│  │
│  ├─Listings
│  └─Objects
│          Embedfire_F103_Fwlib_Template.hex
│
└─User
    │  main.c
    │  stm32f10x_conf.h
    │  stm32f10x_it.c
    │  stm32f10x_it.h
    │
    ├─Led
    │      bsp_led.c
    │      bsp_led.h
    │
    └─RCC
            bsp_rccClkCfg.c
            bsp_rccClkCfg.h
```
