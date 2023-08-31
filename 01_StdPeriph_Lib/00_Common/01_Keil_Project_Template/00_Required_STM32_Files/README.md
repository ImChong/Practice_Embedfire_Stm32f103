- [1. 汇编编写的启动文件](#1-汇编编写的启动文件)
- [2. 时钟配置文件](#2-时钟配置文件)
- [3. 外设相关的](#3-外设相关的)
- [4. 内核相关的](#4-内核相关的)
  - [4.1. CMSIS - Cortex 微控制器软件接口标准](#41-cmsis---cortex-微控制器软件接口标准)
  - [4.2. NVIC(嵌套向量中断控制器)、SysTick(系统滴答定时器)](#42-nvic嵌套向量中断控制器systick系统滴答定时器)
- [5. 头文件的配置文件](#5-头文件的配置文件)
- [6. 专门存放中断服务函数的C文件](#6-专门存放中断服务函数的c文件)
- [7. 主函数 main.c](#7-主函数-mainc)

# 1. 汇编编写的启动文件
startup_stm32f10x_hd.s：设置堆栈指针、设置PC指针、初始化中断向量表、配置系统时钟、对用C库函数_main最终去到C的世界

# 2. 时钟配置文件
system_stm32f10x.c：把外部时钟HSE=8M，经过PLL倍频为72M。

# 3. 外设相关的
stm32f10x.h：实现了内核之外的外设的寄存器映射, 将 stm32f10x.h 代码内的下列注释打开：
```c
#define STM32F10X_HD           /*!< STM32F10X_HD: STM32 High density devices */
```
stm32f10x_xxx.c：外设的驱动函数库文件

stm32f10x_xxx.h：存放外设的初始化结构体，外设初始化结构体成员的参数列表，外设固件库函数的声明

xxx：GPIO、USRAT、I2C、SPI、FSMC


# 4. 内核相关的
## 4.1. CMSIS - Cortex 微控制器软件接口标准
core_cm3.h：实现了内核里面外设的寄存器映射

core_cm3.c：内核外设的驱动固件库

## 4.2. NVIC(嵌套向量中断控制器)、SysTick(系统滴答定时器)
misc.h

misc.c

# 5. 头文件的配置文件
stm32f10x_conf.h：头文件的头文件
```c
//stm32f10x_usart.h
//stm32f10x_i2c.h
//stm32f10x_spi.h
//stm32f10x_adc.h
//stm32f10x_fsmc.h
......
```

# 6. 专门存放中断服务函数的C文件
stm32f10x_it.c

stm32f10x_it.h

中断服务函数你可以随意放在其他的地方，并不是一定要放在stm32f10x_it.c


# 7. 主函数 main.c
```c
#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>

int main(void)
{
	// 来到这里的时候，系统的时钟已经被配置成72M。
}
```