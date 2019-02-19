/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
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
#include "stm32f10x.h"
#include "stm32f10x_conf.h"
#include <stdio.h>

#include "GPIO.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

/* Private functions ---------------------------------------------------------*/
void delay(uint32_t ms);

// /**
//  * LED闪烁功能
//  */
// int main(void)
// {
//     PinsInit();
//     LED2Operation(0);
    
//     while(1) {
//         LED1Operation(1);
//         delay(500);
//         LED1Operation(0);
//         delay(500);
//     }
// }

/**
 * 流水灯功能
 */
int main(void)
{
    PinsInit();

    u8 on = 100;    
    while(1) {
        LED1Operation(on); LED2Operation(!on);
        delay(500);
        on = !on;
    }
}

// /**
//  * 按钮控制功能
//  */
// int main(void)
// {
//     PinsInit();
   
//     while(1) {
//         LED1Operation(Button1Pressing());
//         LED2Operation(Button2Pressing());
//     }
// }

void delay(volatile uint32_t ms) {
    volatile uint32_t i, j;
    for(i = 0; i < 6000; ++i) {
        for(j = 0; j < ms; ++j);
    }
}
/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
