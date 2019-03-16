#ifndef __SYSTICK__H__
#define __SYSTICK__H__

#include "stm32f10x.h" 
#include "stm32f10x_conf.h" 

void SysTickInit();
void DelayUsingSysTick(uint32_t ms);
void OnSysTick();

extern volatile uint32_t millis;

#endif