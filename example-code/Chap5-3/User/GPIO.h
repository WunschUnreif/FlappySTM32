#ifndef __GPIO_H__
#define __GPIO_H__

#include "stm32f10x.h" 
#include "stm32f10x_conf.h" 

void PinsInit();
void LED1Operation(u8 on);
void LED2Operation(u8 on);
u8 Button1Pressing();
u8 Button2Pressing();

#endif