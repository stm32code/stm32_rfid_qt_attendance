/**
  ******************************************************************************
  * @file    GPIO/IOToggle/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and peripherals
  *          interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h" 
#include "oled.h"
#include "usart.h"
#include "delay.h"

extern u8 num[9];
// ´®¿ÚÖÐ¶Ï·þÎñº¯Êý
void DEBUG_USART_IRQHandler(void)
{
  uint8_t ucTemp;
	if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE)!=RESET)
	{		
		ucTemp = USART_ReceiveData(DEBUG_USARTx);
//		printf("ReceiveData: %d \r\n",ucTemp);
//    USART_SendData(DEBUG_USARTx,ucTemp);  

//		//Õý³£
//		if(ucTemp == 1){

//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"open",2);				//²âÊÔ8*16×Ö·û
//			OLED_ShowStr(0,4,num,2);				//²âÊÔ8*16×Ö·û
//			GPIO_ResetBits(GPIOB,GPIO_Pin_9);
//			GPIO_SetBits(GPIOB,GPIO_Pin_8);	
//			delay_ms(1000);
//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"run",2);				//²âÊÔ8*16×Ö·û
//			GPIO_ResetBits(GPIOB,GPIO_Pin_8);	
//		}
//		//Î´×¢²á
//		if(ucTemp == 2){

//			//oledÏÔÊ¾ÐÅÏ¢
//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"no register",2);				//²âÊÔ8*16×Ö·û
//			OLED_ShowStr(0,4,num,2);				//²âÊÔ8*16×Ö·û
//			
//			//¹Ø·äÃùÆ÷
//			GPIO_ResetBits(GPIOB,GPIO_Pin_9);
//			delay_ms(1000);
//			
//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"run",2);				//²âÊÔ8*16×Ö·û
//		}
//		//×¢²á³¬Ê±
//		if(ucTemp == 3){

//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"timeout",2);				//²âÊÔ8*16×Ö·û
//			OLED_ShowStr(0,4,num,2);				//²âÊÔ8*16×Ö·û
//			GPIO_ResetBits(GPIOB,GPIO_Pin_9);
//			delay_ms(1000);
//			OLED_Fill(0x00);//È«ÆÁÃð
//			OLED_ShowStr(0,2,"run",2);				//²âÊÔ8*16×Ö·û
//		}
		
	}	 
}
 
void NMI_Handler(void)
{
}
 
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}
 
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

 
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}
 
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}
 
void SVC_Handler(void)
{
}
 
void DebugMon_Handler(void)
{
}
 
void PendSV_Handler(void)
{
}
 
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
