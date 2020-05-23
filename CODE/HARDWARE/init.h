/*
*	�ļ���:	    init.h
*	�ο�:		����������
*	�汾		V1.00
*	ʱ��:		2014-5-29
*/

#ifndef __INIT_H__
#define __INIT_H__

#include "stm32f10x.h"
#include "delay.h"
#include "typedefs.h"

#define LED_FLOW_EN                                 ( 1 )


#define ON  0
#define OFF 1
															 
/*#define LED1(a)	if (a)	\
					GPIO_SetBits(GPIOF,GPIO_Pin_6);\
					else		\
					GPIO_ResetBits(GPIOF,GPIO_Pin_6)

#define LED2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_4);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_4)

#define LED3(a) if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_5);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_5);*/

/*								   	*
*		����Ϊinit.c�ĺ�������	  	*
*									*/	
																	
void SPI2_Configuration(void);		                                                        //����LED��GPIO,����ѡ�ö˿�,���ģʽ,ʱ��
void SPI2GPIO_Configuration(void);
void USART3_Configuration(void);
void SysTick_Configuration(void);
void RCC_Configuration(void);
//void LED_AllOFF(void);				                                                        //�ر�����LED��
//void LED_AllON(void);			                                                            //������LED
void delay(__IO uint32_t Count);	                                                        //��ʱ����
//void LED_Display(void);				                                                        //LED��ˮ��
//void GPIO_TurnOverBit(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin);
//void LED_StatShow(FStat Stat);
                    
                    
                    
#endif		  //init.h�ļ�


/****************************�ļ�����*****************************/
