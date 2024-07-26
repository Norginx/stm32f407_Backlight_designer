#ifndef _GTIME_H
#define _GTIME_H
#include "./SYSTEM/sys/sys.h"

#define TIM1_TIM2_PORT                   GPIOA
#define TIM1_CH1_GPIO                  GPIO_PIN_5
#define TIM1_CH2_GPIO                  GPIO_PIN_5
#define TIM1_CH3_GPIO                  GPIO_PIN_5
#define TIM1_CH4_GPIO                  GPIO_PIN_5

#define TIM2_CH1_GPIO                  GPIO_PIN_5
#define TIM2_CH2_GPIO                  GPIO_PIN_1
#define TIM2_CH3_GPIO                  GPIO_PIN_2
#define TIM2_CH4_GPIO                  GPIO_PIN_5

#define TIM3_CH1_2_PORT                  GPIOA
#define TIM3_CH3_4_PORT                  GPIOB
#define TIM3_CH1_GPIO                  GPIO_PIN_5
#define TIM3_CH2_GPIO                  GPIO_PIN_5
#define TIM3_CH3_GPIO                  GPIO_PIN_5
#define TIM3_CH4_GPIO                  GPIO_PIN_5

#define TIM4_PORT                        GPIOB
#define TIM4_CH1_GPIO                  GPIO_PIN_5
#define TIM4_CH2_GPIO                  GPIO_PIN_5
#define TIM4_CH3_GPIO                  GPIO_PIN_5
#define TIM4_CH4_GPIO                  GPIO_PIN_5





#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8
#define R9 9

#define G1 10
#define G2 11
#define G3 12
#define G4 13
#define G5 14
#define G6 15
#define G7 16
#define G8 17
#define G9 18

#define B1 19
#define B2 20
#define B3 21
#define B4 22
#define B5 23
#define B6 24
#define B7 25
#define B8 26
#define B9 27
void Init_All_PWM(void);
void gtim_tim2_pwm_chy_init(uint16_t psc,uint16_t arr);
extern TIM_HandleTypeDef g_timx_pwm2_chy_handle;
void PWM_Set(uint8_t site ,uint8_t count);
#endif

