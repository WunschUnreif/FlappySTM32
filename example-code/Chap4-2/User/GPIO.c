#include "GPIO.h"

void PinsInit() {
    GPIO_InitTypeDef gpioInitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    gpioInitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    gpioInitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
    gpioInitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &gpioInitStruct);

    gpioInitStruct.GPIO_Mode = GPIO_Mode_IPD;
    gpioInitStruct.GPIO_Pin = GPIO_Pin_2;
    GPIO_Init(GPIOA, &gpioInitStruct);

    gpioInitStruct.GPIO_Mode = GPIO_Mode_IPU;
    gpioInitStruct.GPIO_Pin = GPIO_Pin_3;
    GPIO_Init(GPIOA, &gpioInitStruct);
}

void LED1Operation(u8 on) {
    if(on) {
        GPIO_ResetBits(GPIOA, GPIO_Pin_0);
    } else {
        GPIO_SetBits(GPIOA, GPIO_Pin_0);
    }
}

void LED2Operation(u8 on) {
    GPIO_WriteBit(GPIOA, GPIO_Pin_1, on ? Bit_RESET : Bit_SET);
}

static void delay(volatile uint32_t ms) {
    volatile uint32_t i, j;
    for(i = 0; i < 6000; ++i) {
        for(j = 0; j < ms; ++j);
    }
}

u8 Button1Pressing() {
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == Bit_SET) {
        delay(50);
        return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == Bit_SET;
    } else return 0;
}

u8 Button2Pressing() {
    if(GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == Bit_RESET) {
        delay(50);
        return GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == Bit_RESET;
    } else return 0;
}
