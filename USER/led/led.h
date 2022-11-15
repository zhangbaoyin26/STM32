#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"
#include "stm32f10x_rcc.h"

//位带操作
#define GPIOB_ODR_Addr      (GPIOB_BASE+0x0C)
#define PBout(n)    *(unsigned int*)((GPIOB_ODR_Addr&0xF0000000) + 0x02000000 + ((GPIOB_ODR_Addr&0x00FFFFFF)<<5) + (n<<2))
//固件库编程
#define LED_GPIO_PIN    GPIO_Pin_13
#define LED_GPIO_PORT   GPIOC
#define LED_GPIO_CLK    RCC_APB2Periph_GPIOC
#define     ON          1
#define     OFF         0
#define     LED_ON(a)    if(a) \
                            GPIO_ResetBits(LED_GPIO_PORT, LED_GPIO_PIN); \
                        else \
                            GPIO_SetBits(LED_GPIO_PORT, LED_GPIO_PIN);
#define LED_BLINK       {LED_GPIO_PORT->ODR ^= GPIO_Pin_13;}

void LED_GPIO_CONF(void);


#endif
