#include "stm32f10x.h"

void SystemInit(void) {
    /* 函数为空，为了让编译器不报错 */
}

int main(void) {
    /* 打开 GPIOB 端口的时钟 */
    *(unsigned int *)0x40021018 |= (1 << 3);

    /* 配置 IO 口为输出 */

    /* 控制 ODR 寄存器 */
    return 0;
}

