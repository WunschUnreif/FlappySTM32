#include "SysTick.h"

volatile uint32_t millis = 0;
static volatile uint32_t timerForDelay = 0;

void SysTickInit() {
    if(SysTick_Config(SystemCoreClock / 1000)) {
        while(1);
    }
}

void DelayUsingSysTick(uint32_t ms) {
    timerForDelay = ms;
    while(timerForDelay);
}

void OnSysTick() {
    ++millis;
    if(timerForDelay) timerForDelay--;
}
