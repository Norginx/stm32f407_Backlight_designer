/**
 ****************************************************************************************************
 * @file        main.c
 * @author      正点原子团队(ALIENTEK)
 * @version     V1.0
 * @date        2021-10-14
 * @brief       串口通信 实验
 * @license     Copyright (c) 2020-2032, 广州市星翼电子科技有限公司
 ****************************************************************************************************
 * @attention
 *
 * 实验平台:正点原子 探索者 F407开发板
 * 在线视频:www.yuanzige.com
 * 技术论坛:www.openedv.com
 * 公司网址:www.alientek.com
 * 购买地址:openedv.taobao.com
 *
 ****************************************************************************************************
 */

#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/LED/led.h"
#include "./BSP/OLED/oled.h"
#include "./BSP/KEY/key.h"
#include "./BSP/MENU/menu.h"
#include "./BSP/PCA9685/pca9685.h"
#include "stdio.h"
int main(void)
{

    
    HAL_Init();                             /* 初始化HAL库 */
    sys_stm32_clock_init(336, 8, 2, 7);     /* 设置时钟,168Mhz */
    delay_init(168);                        /* 延时初始化 */
    usart_init(115200);                     /* 串口初始化为115200 */
    Usart4_Init(115200);
    led_init();                             /* 初始化LED */
    GPIO_Init();
    Encoder_Init();
    key_init();
    PCA9685_Init(1000);
    menu1();

    while(1)
    {

//           printf("%d\n",Useful_Light[8]);
//           printf("%d\n",Useful_Light[9]);
//           printf("%d\n",Useful_Light[10]);
//            delay_ms(500);
    }
}

