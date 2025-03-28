#include "lock.h"




void lockInit(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //使能时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;				 //PB8
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 //GPIOB
	
	
 GPIO_ResetBits(GPIOB,GPIO_Pin_12);						 //PB8输出低


}
