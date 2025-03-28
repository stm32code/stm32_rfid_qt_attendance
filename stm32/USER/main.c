#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "rfid.h"
#include "oled.h"
#include "msg.h"
#include "lock.h"

void initSystem(){
	
	delay_init(); //初始化时钟，主要使用延迟函数
	
	USART_Config(); //初始化串口 stm32和电脑通信
//	I2C_Configuration();  //初始化IIC  I2C   oled模块使用
//	OLED_Init();  //初始化OLED模块
	msgInit(); //初始化蜂鸣器
	lockInit();//初始化LED  模拟锁的
 
}




int main( void )
{



initSystem();




	while ( 1 )
	{
		RC522_Handel();

	}
}


