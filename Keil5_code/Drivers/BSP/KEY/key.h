/**
 ****************************************************************************************************
 * @file        key.h
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-19
 * @brief       按键输入 驱动代码
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 STM32F103开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 * 修改说明
 * V1.0 20200419
 * 第一次发布
 *
 ****************************************************************************************************
 */

#ifndef __KEY_H
#define __KEY_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* 引脚 定义 */
#define Encoder_Port                  GPIOG
#define Encoder_KEY_GPIO_PIN                   GPIO_PIN_0
#define Encoder_KEY_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOG_CLK_ENABLE(); }while(0)   /* PE口时钟使能 */





/******************************************************************************************/

#define Encoder_KEY       HAL_GPIO_ReadPin(Encoder_Port, Encoder_KEY_GPIO_PIN)     /* 读取WKUP引脚 */

#define KEY0_PRES    1              /* KEY0按下 */
#define KEY1_PRES    2              /* KEY1按下 */
#define Encoder_KEY_PRES    3              /* KEY2按下 */
#define WKUP_PRES    4              /* KEY_UP按下(即WK_UP) */
extern uint8_t Encoder_Count;
extern uint8_t Encoder_R_Count[9];
extern uint8_t Encoder_G_Count[9];
extern uint8_t Encoder_B_Count[9];
extern uint8_t Encoder_Site;
void key_init(void);                /* 按键初始化函数 */
uint8_t key_scan(uint8_t mode);     /* 按键扫描函数 */
void Encoder_Init(void);

#define Encoder_Port       GPIOG
#define Encoder_GPIOA      GPIO_PIN_1
#define Encoder_GPIOB      GPIO_PIN_2
#define Encoder_CLK_ENABLE()          do{ __HAL_RCC_GPIOG_CLK_ENABLE(); }while(0)
#endif


















