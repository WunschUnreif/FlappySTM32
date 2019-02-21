#include "GPIO.h"

static void InterruptInit() {
    EXTI_InitTypeDef extiInitStruct;
    NVIC_InitTypeDef nvicInitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource2);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);

    NVIC_SetPriorityGrouping(NVIC_PriorityGroup_1);

    extiInitStruct.EXTI_Line = EXTI_Line2 | EXTI_Line3;
    extiInitStruct.EXTI_LineCmd = ENABLE;
    extiInitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
    extiInitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_Init(&extiInitStruct);

    nvicInitStruct.NVIC_IRQChannel = EXTI2_IRQn;
    nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
    nvicInitStruct.NVIC_IRQChannelPreemptionPriority = 0;
    nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&nvicInitStruct);

    nvicInitStruct.NVIC_IRQChannel = EXTI3_IRQn;
    nvicInitStruct.NVIC_IRQChannelCmd = ENABLE;
    nvicInitStruct.NVIC_IRQChannelPreemptionPriority = 1;
    nvicInitStruct.NVIC_IRQChannelSubPriority = 0;
    NVIC_Init(&nvicInitStruct);
}

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

    InterruptInit();
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
