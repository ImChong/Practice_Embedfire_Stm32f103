#include "stm32f10x.h"  /* 实现寄存器定义 */

#define SECTION_ADDRESS_EN 0    /* 用地址直接操作 GPIO PB0 */
#define SECTION_MACRO_EN 0      /* 用寄存器宏操作 GPIO PB0 */
#define SECTION_STRUCT_EN 1     /* 用结构体操作 GPIO PB0 */

void SystemInit(void) {
    /* 函数为空，为了让编译器不报错 */
}

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
    // GPIOB->ODR |= (1 << (1 * 0));            /* 设置为1，1位为一组，向左移动0位 */

#endif

    return 0;
}
