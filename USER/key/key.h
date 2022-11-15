#ifndef _KEY_H
#define _KEY_H

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

#define KEY_GPIO_PORT   GPIOB
#define KEY_GPIO_PIN    GPIO_Pin_12
#define KEY_GPIO_CLK    RCC_APB2Periph_GPIOB
#define     KEY_ON          1
#define     KEY_OFF         0

void KEY_GPIO_CONF(void);
static u8 Botton_Up = 1;
uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
extern void delay(u32 time);

#endif
