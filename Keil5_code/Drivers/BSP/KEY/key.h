/**
 ****************************************************************************************************
 * @file        key.h
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-19
 * @brief       �������� ��������
 * @license     Copyright (c) 2020-2032, ������������ӿƼ����޹�˾
 ****************************************************************************************************
 * @attention
 *
 * ʵ��ƽ̨:����ԭ�� STM32F103������
 * ������Ƶ:www.yuanzige.com
 * ������̳:www.openedv.com
 * ��˾��ַ:www.alientek.com
 * �����ַ:openedv.taobao.com
 *
 * �޸�˵��
 * V1.0 20200419
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#ifndef __KEY_H
#define __KEY_H

#include "./SYSTEM/sys/sys.h"

/******************************************************************************************/
/* ���� ���� */
#define Encoder_Port                  GPIOG
#define Encoder_KEY_GPIO_PIN                   GPIO_PIN_0
#define Encoder_KEY_GPIO_CLK_ENABLE()          do{ __HAL_RCC_GPIOG_CLK_ENABLE(); }while(0)   /* PE��ʱ��ʹ�� */





/******************************************************************************************/

#define Encoder_KEY       HAL_GPIO_ReadPin(Encoder_Port, Encoder_KEY_GPIO_PIN)     /* ��ȡWKUP���� */

#define KEY0_PRES    1              /* KEY0���� */
#define KEY1_PRES    2              /* KEY1���� */
#define Encoder_KEY_PRES    3              /* KEY2���� */
#define WKUP_PRES    4              /* KEY_UP����(��WK_UP) */
extern uint8_t Encoder_Count;
extern uint8_t Encoder_R_Count[9];
extern uint8_t Encoder_G_Count[9];
extern uint8_t Encoder_B_Count[9];
extern uint8_t Encoder_Site;
void key_init(void);                /* ������ʼ������ */
uint8_t key_scan(uint8_t mode);     /* ����ɨ�躯�� */
void Encoder_Init(void);

#define Encoder_Port       GPIOG
#define Encoder_GPIOA      GPIO_PIN_1
#define Encoder_GPIOB      GPIO_PIN_2
#define Encoder_CLK_ENABLE()          do{ __HAL_RCC_GPIOG_CLK_ENABLE(); }while(0)
#endif


















