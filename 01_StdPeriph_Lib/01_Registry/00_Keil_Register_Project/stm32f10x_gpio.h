#ifndef __STM32F10X_GPIO_H  /* 防止重复包含头文件 */
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"

/*GPIO 引脚号定义 */
#define GPIO_Pin_0      ((uint16_t)0x0001)      /*!< 选择 Pin0 (1<<0) */
#define GPIO_Pin_1      ((uint16_t)0x0002)      /*!< 选择 Pin1 (1<<1)*/
#define GPIO_Pin_2      ((uint16_t)0x0004)      /*!< 选择 Pin2 (1<<2)*/
#define GPIO_Pin_3      ((uint16_t)0x0008)      /*!< 选择 Pin3 (1<<3)*/
#define GPIO_Pin_4      ((uint16_t)0x0010)      /*!< 选择 Pin4 */
#define GPIO_Pin_5      ((uint16_t)0x0020)      /*!< 选择 Pin5 */
#define GPIO_Pin_6      ((uint16_t)0x0040)      /*!< 选择 Pin6 */
#define GPIO_Pin_7      ((uint16_t)0x0080)      /*!< 选择 Pin7 */
#define GPIO_Pin_8      ((uint16_t)0x0100)      /*!< 选择 Pin8 */
#define GPIO_Pin_9      ((uint16_t)0x0200)      /*!< 选择 Pin9 */
#define GPIO_Pin_10     ((uint16_t)0x0400)      /*!< 选择 Pin10 */
#define GPIO_Pin_11     ((uint16_t)0x0800)      /*!< 选择 Pin11 */
#define GPIO_Pin_12     ((uint16_t)0x1000)      /*!< 选择 Pin12 */
#define GPIO_Pin_13     ((uint16_t)0x2000)      /*!< 选择 Pin13 */
#define GPIO_Pin_14     ((uint16_t)0x4000)      /*!< 选择 Pin14 */
#define GPIO_Pin_15     ((uint16_t)0x8000)      /*!< 选择 Pin15 */
#define GPIO_Pin_All    ((uint16_t)0xFFFF)      /*!< 选择全部引脚 */

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);

#endif  /* __STM32F10X_GPIO_H */
