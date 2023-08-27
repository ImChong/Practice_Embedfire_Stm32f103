#include "stm32f10x.h"  /* 实现寄存器定义 */

void SystemInit(void) {
    /* 函数为空，为了让编译器不报错 */
}

int main(void) {
    /* RCC_APB2ENR 打开 GPIOB 端口的时钟 */
    /* IOPBEN：设置为 1 */
    *(unsigned int *)0x40021018 |= (1 << (1 * 3));  /* 设置为1，1位为一组，向左移动3位 */

    /* GPIOx_CRL 配置 PB0 口为输出 */
    /* 5 = 0101 - CNF0：01：通用开漏输出模式 - MODE0：01：输出模式，最大速度10MHz */
    *(unsigned int *)0x40010C00 |= (5 << (4 * 0));  /* 设置为1，4位为一组，向左移动0位 */

    /* GPIOx_ODR 控制 ODR 寄存器 */
    /* ODR0：设置为 0 */
    *(unsigned int *)0x40010C0C &= ~(1 << (1 * 0)); /* 设置为0，1位为一组，向左移动0位 */
    return 0;
}

