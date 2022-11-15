#include "key.h"


void KEY_GPIO_CONF(void){
    GPIO_InitTypeDef GPIO_InitStruct;
    RCC_APB2PeriphClockCmd(KEY_GPIO_CLK, ENABLE);
    GPIO_InitStruct.GPIO_Pin = KEY_GPIO_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(KEY_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t Key_Scan(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
    if (GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
        delay(0x8FFF);
        if (Botton_Up && GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
            Botton_Up = 0;
            return KEY_ON;
        }    
        else if (!Botton_Up && GPIO_ReadInputDataBit(GPIOx, GPIO_Pin) == KEY_ON){
            Botton_Up = 0;
            return KEY_OFF;
        }
    }
    else {
        Botton_Up = 1;
        return KEY_OFF;
    }
    return KEY_OFF;
}
