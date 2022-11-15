// #include "bsp_i2c_ee.h"

// void GPIO_INIT(){
// 	GPIO_InitTypeDef GPIO_InitSCL, GPIO_InitSDA;
//     RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
//     GPIO_InitSCL.GPIO_Pin = SCL;
//     GPIO_InitSCL.GPIO_Mode = GPIO_Mode_IPD;		// ����SCLΪ����ģʽ
//     GPIO_InitSCL.GPIO_Speed = GPIO_Speed_10MHz;
// 	GPIO_InitSDA.GPIO_Pin = SCL;
//     GPIO_InitSDA.GPIO_Mode = GPIO_Mode_IPD;		// ����SDAΪ����ģʽ
//     GPIO_InitSDA.GPIO_Speed = GPIO_Speed_10MHz;
//     GPIO_Init(GPIOA_POTR, &GPIO_InitSCL);
// 	GPIO_Init(GPIOA_POTR, &GPIO_InitSDA);
// }

// uint8_t is_start(){
// 	uint16_t count;
// 	if(GPIO_ReadInputDataBit(GPIOA_POTR, SCL))
// 		if(GPIO_ReadInputDataBit(GPIOA_POTR, SDA))
// 			while((count<=0xFFFF) && (GPIO_ReadInputDataBit(GPIOA_POTR, SDA)))
// 				++count;
// 	if (GPIO_ReadInputDataBit(GPIOA_POTR, SDA) == 0)
// 		return 1;
// 	else 
// 		return 0;
// }

// uint16_t rec(){
// 	uint8_t i = 0;
// 	uint8_t dat1, dat2;
// 	uint16_t rec = 0;
// 	// �жϵ�һλ�Ƿ�Ϊstop�ź�
// 	if (GPIO_ReadInputDataBit(GPIOA_POTR, SCL) == 1){
// 		delay_us(10);
// 		dat1 = GPIO_ReadInputDataBit(GPIOA_POTR, SDA);
// 		delay_us(60);
// 		dat2 = GPIO_ReadInputDataBit(GPIOA_POTR, SDA);
// 		if (dat1==0 && dat2==1)
// 			rec |= 0x80;
// 	}
// 	// ����stop�ź�
// 	if (rec&0x80 == 0){
// 		while (i < 8){
// 			if (GPIO_ReadInputDataBit(GPIOA_POTR, SCL) == 1){
// 				delay_us(10);
// 				rec |= GPIO_ReadInputDataBit(GPIOA_POTR, SDA)<<i;
// 				++i;
// 			}
// 		}
// 	}
// 	return rec;
// }

// void ack(){
// 	GPIO_InitTypeDef GPIO_InitSCL, GPIO_InitSDA;
//     GPIO_InitSCL.GPIO_Pin = SCL;
//     GPIO_InitSCL.GPIO_Mode = GPIO_Mode_Out_PP;		// ����SCLΪ���ģʽ
//     GPIO_InitSCL.GPIO_Speed = GPIO_Speed_10MHz;
// 	GPIO_InitSDA.GPIO_Pin = SCL;
//     GPIO_InitSDA.GPIO_Mode = GPIO_Mode_Out_PP;		// ����SDAΪ���ģʽ
//     GPIO_InitSDA.GPIO_Speed = GPIO_Speed_10MHz;
//     GPIO_Init(GPIOA_POTR, &GPIO_InitSCL);
// 	GPIO_Init(GPIOA_POTR, &GPIO_InitSDA);

// 	sda(1);
// 	scl(1);
// 	delay_us(10);
// 	sda(0);
// 	delay_us(60);
// 	sda(1);
// 	delay_us(10);
// 	scl(0);

//     GPIO_InitSCL.GPIO_Pin = SCL;
//     GPIO_InitSCL.GPIO_Mode = GPIO_Mode_IPD;		// ����SCLΪ����ģʽ
//     GPIO_InitSCL.GPIO_Speed = GPIO_Speed_10MHz;
// 	GPIO_InitSDA.GPIO_Pin = SCL;
//     GPIO_InitSDA.GPIO_Mode = GPIO_Mode_IPD;		// ����SDAΪ����ģʽ
//     GPIO_InitSDA.GPIO_Speed = GPIO_Speed_10MHz;
//     GPIO_Init(GPIOA_POTR, &GPIO_InitSCL);
// 	GPIO_Init(GPIOA_POTR, &GPIO_InitSDA);
// }

// void check(uint8_t dat){

// }





// void EXTI_NVIC_Conf(){
// 	NVIC_InitTypeDef NVIC_InitSCL;
	
// 	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

// 	NVIC_InitSCL.NVIC_IRQChannel = EXTI0_IRQn;	// ��stm32f10x.h L231
// 	NVIC_InitSCL.NVIC_IRQChannelPreemptionPriority = 1;
// 	NVIC_InitSCL.NVIC_IRQChannelSubPriority = 1;
// 	NVIC_InitSCL.NVIC_IRQChannelCmd = ENABLE;		//�����ж�

// 	NVIC_Init(&NVIC_InitSCL);
// }


// void EXTI_GPIO_Conf(){
// 	GPIO_InitTypeDef GPIO_InitSCL;
// 	EXTI_InitTypeDef EXTI_InitSCL;

// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

// 	// �����ж����ȼ�
// 	void EXTI_NVIC_Conf();

// 	// ��ʼ��gpio
//     GPIO_InitSCL.GPIO_Pin = GPIO_Pin_0;
//     GPIO_InitSCL.GPIO_Mode = GPIO_Mode_IN_FLOATING;		// ����SCLΪ����ģʽ
//     GPIO_InitSCL.GPIO_Speed = GPIO_Speed_50MHz;
// 	GPIO_Init(GPIOA_POTR, &GPIO_InitSCL);

// 	// ��extiʱ����
// 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

// 	// ��ʼ��exti������
// 	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0);

// 	EXTI_InitSCL.EXTI_Line = EXTI_Line0;
// 	EXTI_InitSCL.EXTI_Mode = EXTI_Mode_Interrupt;
// 	EXTI_InitSCL.EXTI_Trigger = EXTI_Trigger_Rising;
// 	EXTI_InitSCL.EXTI_LineCmd = ENABLE;

// 	EXTI_Init(&EXTI_InitSCL);
// }


// // �жϷ�����EXTI9_5_IRQHandler ����startup L253
// void EXTI0_IRQHandler(void){
// 	// static u8 count = 0;
// 	if (EXTI_GetITStatus(EXTI_Line0) != RESET){
// 		LED_ON(0);
// 	}
// 	EXTI_ClearITPendingBit(EXTI_Line0);		//����жϱ�־λ
// }



#include "iic\bsp_i2c_ee.h"


// void delay_us(uint32_t us){
// 	uint32_t i;
// 	for (i = 0; i < us; ++i);
// }

void GPIO_SDA_INIT(){
	GPIO_InitTypeDef GPIO_InitSDA;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitSDA.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitSDA.GPIO_Mode = GPIO_Mode_IPD;		// ����SDAΪ����ģʽ
    GPIO_InitSDA.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitSDA);
}

static void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
  /* ����NVICΪ���ȼ���1 */
	/* ��ʾ NVIC_PriorityGroupConfig() ����������ֻ��Ҫ����һ�����������ȼ�����*/
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
  
  /* �����ж�Դ������1 */
  NVIC_InitStructure.NVIC_IRQChannel = KEY1_INT_EXTI_IRQ;
  /* ������ռ���ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  /* ���������ȼ� */
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  /* ʹ���ж�ͨ�� */
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Key_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure; 
	EXTI_InitTypeDef EXTI_InitStructure;

	/*��������GPIO�ڵ�ʱ��*/
	RCC_APB2PeriphClockCmd(KEY1_INT_GPIO_CLK,ENABLE);
												
	/* ���� NVIC �ж�*/
	NVIC_Configuration();
	

	/* ѡ�񰴼��õ���GPIO */	
  GPIO_InitStructure.GPIO_Pin = KEY1_INT_GPIO_PIN;
  /* ����Ϊ�������� */	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(KEY1_INT_GPIO_PORT, &GPIO_InitStructure);

	/* ѡ��EXTI���ź�Դ */
  GPIO_EXTILineConfig(KEY1_INT_EXTI_PORTSOURCE, KEY1_INT_EXTI_PINSOURCE); 
  EXTI_InitStructure.EXTI_Line = KEY1_INT_EXTI_LINE;
	
	/* EXTIΪ�ж�ģʽ */
  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	/* �������ж� */
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
  /* ʹ���ж� */	
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);
}

// �жϷ�����EXTI9_5_IRQHandler ����startup L253
void EXTI0_IRQHandler(void){
	if ( EXTI_GetITStatus(EXTI_Line0)!=RESET ){
    LED_BLINK
    ++count;
    str[8] = '0' + count%10;
    str[7] = '0' + (count/10)%10;
    str[6] = '0' + (count/100)%10;
    OLED_ShowString(16, 2, str, 16);
	}
	EXTI_ClearITPendingBit(EXTI_Line0);		//����жϱ�־λ
}