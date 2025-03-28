#include "msg.h"



void msgInit(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //打开时钟

	//给结构体赋值
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;				 //PB8
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //GPIOB
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_9);						 //PB9输出低
}
