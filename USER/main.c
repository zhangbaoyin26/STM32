#include "stm32f10x.h"
#include "led\led.h"
#include "key\key.h"
#include "iic\bsp_i2c_ee.h"
#include "oled\oled.h"

void delay(u32 time){
  for(; time!=0; --time);
}

int main(){
  LED_GPIO_CONF();
  LED_ON(1);
  EXTI_Key_Config();
    delay_init();         //延时函数初始化
    NVIC_Configuration(); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
    delay_ms(800);
    GPIO_Conf();
    OLED_Init(); //初始化OLED
    OLED_Clear();
    OLED_ShowString(16, 2, "count:000", 16);
  while(1){
    ;
  }
}

// void SystemInit(){
//   //
// }
