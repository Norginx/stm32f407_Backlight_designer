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

#ifndef __PCA9685_H
#define __PCA9685_H
#include "./SYSTEM/sys/sys.h"

#define PCA_Addr 0x80
#define PCA_Model 0x00
#define LED0_ON_L 0x06
#define LED0_ON_H 0x07
#define LED0_OFF_L 0x08
#define LED0_OFF_H 0x09
#define PCA_Pre 0xFE

void PCA9685_1_setFreq(float freq);
void PCA9685_1_setPWM(uint8_t num,uint32_t on,uint32_t off);
void PCA9685_2_setFreq(float freq);
void PCA9685_2_setPWM(uint8_t num,uint32_t on,uint32_t off);
void PCA9685_Init(float hz);
void SET_PWM(uint8_t num,uint32_t on,uint32_t off);



#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define R4 4
#define R5 5
#define R6 6
#define R7 7
#define R8 8

#define G0 9
#define G1 10
#define G2 11
#define G3 12
#define G4 13
#define G5 14
#define G6 15
#define G7 16
#define G8 17

#define B0 18
#define B1 19
#define B2 20
#define B3 21
#define B4 22
#define B5 23
#define B6 24
#define B7 25
#define B8 26



#endif
