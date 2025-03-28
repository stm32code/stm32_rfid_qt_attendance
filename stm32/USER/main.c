#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "rfid.h"
#include "oled.h"
#include "msg.h"
#include "lock.h"

void initSystem(){
	
	delay_init(); //��ʼ��ʱ�ӣ���Ҫʹ���ӳٺ���
	
	USART_Config(); //��ʼ������ stm32�͵���ͨ��
//	I2C_Configuration();  //��ʼ��IIC  I2C   oledģ��ʹ��
//	OLED_Init();  //��ʼ��OLEDģ��
	msgInit(); //��ʼ��������
	lockInit();//��ʼ��LED  ģ������
 
}




int main( void )
{



initSystem();




	while ( 1 )
	{
		RC522_Handel();

	}
}


