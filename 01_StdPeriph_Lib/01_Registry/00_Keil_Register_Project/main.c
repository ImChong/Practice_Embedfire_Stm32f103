/*
 * @File: main.c
 * @Created Date: 2023-08-28 9:50:16 pm
 * @Author: Chong Liu
 * @Brief: 主程序
 * =================================================================================
 * Copyright (c) 2023 Chong Liu
 * =================================================================================
 * Last Modified: Chong Liu - 2023-08-30 10:27:27 pm
 */
// #include "stm32f10x.h"          /* 实现寄存器定义 */
#include "stm32f10x_gpio.h"     /* 自定义 gpio 函数 */

#define SECTION_ADDRESS_EN 0                    /* 用地址直接操作 GPIO PB0 */
#define SECTION_MACRO_EN 0                      /* 用寄存器宏操作 GPIO PB0 */
#define SECTION_STRUCT_EN 0                     /* 用结构体操作 GPIO PB0 */
#define SECTION_FUNCTION_EN 0                   /* 用函数操作 GPIO PB0 */
#define SECTION_GPIO_STRUCTURE_SECTION_EN 1     /* 用结构体初始化 GPIO PB0 */

/* SystemInit()
 *  Functionality: 系统初始化函数
 *  Arguments: void
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void SystemInit(void) {
    /* 函数为空，为了让编译器不报错 */
}

/* Delay()
 *  Functionality: 延迟函数
 *  Arguments: __IO uint32_t nCount
 *  Return: void
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
void Delay(__IO uint32_t nCount) {
    for (; nCount != 0; nCount--);
}

/* main()
 *  Functionality: 主程序入口
 *  Arguments: void
 *  Return: int
 *  References: document/website...
 ***********************************************************************************
 *  IMPORTANT NOTICE FOR READER
 */
int main(void) {
#if SECTION_ADDRESS_EN
    /* NOTE: 用地址直接操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    *(unsigned int *)0x40021018 |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    *(unsigned int *)0x40010C00 &= ~(0x0f << (4 * 0));      /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    *(unsigned int *)0x40010C00 |= (5 << (4 * 0));          /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    *(unsigned int *)0x40010C0C &= ~(1 << (1 * 0));         /* 设置为0，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_MACRO_EN
    /* NOTE: 用寄存器宏操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC_APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB_CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB_CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIOB_ODR &= ~(1 << (1 * 0));           /* 设置为0，1位为一组，向左移动0位 */   /* 取决与硬件原理图：输出 0 点亮 LED 灯*/
    GPIOB_ODR |= (1 << (1 * 0));            /* 设置为1，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_STRUCT_EN
    /* NOTE: 用结构体操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB->CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB->CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIOB->ODR &= ~(1 << (1 * 0));           /* 设置为0，1位为一组，向左移动0位 */   /* 取决与硬件原理图：输出 0 点亮 LED 灯*/
    GPIOB->ODR |= (1 << (1 * 0));            /* 设置为1，1位为一组，向左移动0位 */

    return 0;

#elif SECTION_FUNCTION_EN
    /* NOTE: 用函数操作 GPIO PB0 */
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOB_CRL 配置 PB0 清零 */
    GPIOB->CRL &= ~(0x0f << (4 * 0));        /* 设置为0x0f，4位为一组，向左移动0位 */
    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    /* 1 = 0001 - CNF0：00：通用推挽输出模式 - MODE0：01：输出模式，最大速度10MHz */
    GPIOB->CRL |= (1 << (4 * 0));            /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);

    return 0;

#elif SECTION_GPIO_STRUCTURE_SECTION_EN
    /* NOTE: 用结构体初始化 GPIO PB0 */
    /* GPIO 端口初始化j结构体 */
    GPIO_InitTypeDef GPIO_InitStructure;

    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    RCC->APB2ENR |= (1 << (1 * 3));          /* 设置为1，1位为一组，向左移动3位 */

    /* 选择要控制的GPIO 引脚*/
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    /* 设置引脚的输出类型为推挽输出*/
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    /* 设置输出速率为 50MHZ */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    /* 调用库函数，初始化 GPIO 引脚 */
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    /* 使引脚输出低电平, 点亮 LED1 */
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);

    while (1) {
        /* 使引脚输出低电平, 点亮 LED */
        GPIO_ResetBits(GPIOB, GPIO_Pin_0);

        /* 延时一段时间 */
        Delay(0xFFFFF);

        /* 使引脚输出高电平，关闭 LED1*/
        GPIO_SetBits(GPIOB,GPIO_Pin_0);

        /* 延时一段时间 */
        Delay(0xFFFFF);
    }

#endif
}
