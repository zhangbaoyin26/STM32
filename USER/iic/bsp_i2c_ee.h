// #ifndef __I2C_EE_H
// #define	__I2C_EE_H

// #include "stm32f10x.h"
// #include "stm32f10x_gpio.h"
// #include "stm32f10x_exti.h"
// #include "led\led.h"


// // 本次iic通信中scl的高电平时间维持100us

// #define     GPIOA_POTR  GPIOA
// #define     SCL         GPIO_Pin_6
// #define     SDA         GPIO_Pin_7
// #define     EXIT
// #define     scl(a)      if(a) GPIO_SetBits(GPIOA_POTR, SCL); \
//                         else  GPIO_ResetBits(GPIOA_POTR, SCL);
// #define     sda(a)      if(a) GPIO_SetBits(GPIOA_POTR, SDA); \
//                         else  GPIO_ResetBits(GPIOA_POTR, SDA);

// void GPIO_INIT();

// // 作为接收端
// uint8_t is_start();
// uint16_t rec();
// void ack();
// void check(uint8_t dat);

// void EXTI_GPIO_Conf();
// void EXTI0_IRQHandler();

// #endif /* __I2C_EE_H */



#ifndef __I2C_EE_H
#define	__I2C_EE_H


#include "stm32f10x.h"
#include "stm32f10x_exti.h"
#include "led\led.h"
#include "oled\oled.h"
#include "delay\delay.h"

static uint8_t dat = 0;
static uint32_t count = 0;
static uint8_t str[] = {'c','o','u','n','t',':', '0', '0', '0'};

//?????¨??
#define KEY1_INT_GPIO_PORT         GPIOA
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_0
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY1_INT_EXTI_LINE         EXTI_Line0
#define KEY1_INT_EXTI_IRQ          EXTI0_IRQn

#define KEY1_IRQHandler            EXTI0_IRQHandler


// #define KEY2_INT_GPIO_PORT         GPIOC
// #define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
// #define KEY2_INT_GPIO_PIN          GPIO_Pin_13
// #define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
// #define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource13
// #define KEY2_INT_EXTI_LINE         EXTI_Line13
// #define KEY2_INT_EXTI_IRQ          EXTI15_10_IRQn

#define KEY2_IRQHandler            EXTI15_10_IRQHandler

void EXTI_Key_Config(void);


#endif /* __I2C_EE_H */