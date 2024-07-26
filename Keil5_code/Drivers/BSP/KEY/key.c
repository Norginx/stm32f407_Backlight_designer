/**
 ****************************************************************************************************
 * @file        key.c
 * @author      ����ԭ���Ŷ�(ALIENTEK)
 * @version     V1.0
 * @date        2020-04-20
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
 * V1.0 20200420
 * ��һ�η���
 *
 ****************************************************************************************************
 */

#include "./BSP/KEY/key.h"
#include "./SYSTEM/delay/delay.h"
#include "./BSP/MENU/menu.h"
#include "./BSP/OLED/oled.h"

uint8_t Encoder_Site=1;
uint8_t Encoder_Count=0;
uint8_t inNum=0,flag;
uint8_t Encoder_R_Count[9]={0};
uint8_t Encoder_G_Count[9]={0};
uint8_t Encoder_B_Count[9]={0};
/**
 * @brief       ������ʼ������
 * @param       ��
 * @retval      ��
 */
void key_init(void)
{
    GPIO_InitTypeDef gpio_init_struct;
    Encoder_KEY_GPIO_CLK_ENABLE();                                     /* KEY2ʱ��ʹ�� */
    
    gpio_init_struct.Pin = Encoder_KEY_GPIO_PIN;                       /* KEY2���� */
    gpio_init_struct.Mode = GPIO_MODE_INPUT;                    /* ���� */
    gpio_init_struct.Pull = GPIO_PULLUP;                        /* ���� */
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;              /* ���� */
    HAL_GPIO_Init(Encoder_Port, &gpio_init_struct);           /* KEY2����ģʽ����,�������� */
    
    
    

}

/**
 * @brief       ����ɨ�躯��
 * @note        �ú�������Ӧ���ȼ�(ͬʱ���¶������): WK_UP > KEY2 > KEY1 > KEY0!!
 * @param       mode:0 / 1, ���庬������:
 *   @arg       0,  ��֧��������(���������²���ʱ, ֻ�е�һ�ε��û᷵�ؼ�ֵ,
 *                  �����ɿ��Ժ�, �ٴΰ��²Ż᷵��������ֵ)
 *   @arg       1,  ֧��������(���������²���ʱ, ÿ�ε��øú������᷵�ؼ�ֵ)
 * @retval      ��ֵ, ��������:
 *              KEY0_PRES, 1, KEY0����
 *              KEY1_PRES, 2, KEY1����
 *              KEY2_PRES, 3, KEY2����
 *              WKUP_PRES, 4, WKUP����
 */
uint8_t key_scan(uint8_t mode)
{
    static uint8_t key_up = 1;  /* �������ɿ���־ */
    uint8_t keyval = 0;

    if (mode) key_up = 1;       /* ֧������ */

    if (key_up && (Encoder_KEY == 0))  /* �����ɿ���־Ϊ1, ��������һ������������ */
    {
        delay_ms(10);           /* ȥ���� */
        key_up = 0;
        
        if (Encoder_KEY == 0)  keyval = Encoder_KEY_PRES;
    }
    else if ( Encoder_KEY == 1 ) /* û���κΰ�������, ��ǰ����ɿ� */
    {
        key_up = 1;
    }

    return keyval;              /* ���ؼ�ֵ */
}





void Encoder_Init()
{
    Encoder_CLK_ENABLE();
    GPIO_InitTypeDef gpio_init_struct;
    gpio_init_struct.Pull = GPIO_PULLUP;
    gpio_init_struct.Mode = GPIO_MODE_IT_RISING_FALLING;
    gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;
    gpio_init_struct.Pin = Encoder_GPIOA;
    HAL_GPIO_Init(Encoder_Port,&gpio_init_struct);
    
    gpio_init_struct.Mode = GPIO_MODE_INPUT;
    gpio_init_struct.Pin = Encoder_GPIOB;
    HAL_GPIO_Init(Encoder_Port,&gpio_init_struct);

    HAL_NVIC_SetPriority(EXTI1_IRQn,3,0);
    HAL_NVIC_EnableIRQ(EXTI1_IRQn);
}

void Encoder_Check()
{
     if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                
                if(Encoder_Count!=0)
                {
                    Encoder_Count-=1;
                }
                else
                {
                    Encoder_Count=0;
                }
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                
                if(Encoder_Count<100)
                {
                    Encoder_Count+=1;
                }
                else
                {
                    Encoder_Count = 100;
                }
            }
            inNum=0;
        }
}

void Site_Check()
{
     if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                
                if(Encoder_Site!=1)
                {
                    Encoder_Site-=1;
                }
                else
                {
                    Encoder_Site=1;
                }
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                
                if(Encoder_Site>10)
                {
                    
                    Encoder_Site = 9;
                }
                else
                {
                    Encoder_Site+=1;
                }
            }
            inNum=0;
        }
}


void Switch_Check()
{
     if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                Auto_Light_Switch = 0;
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                Auto_Light_Switch = 1;
            }
            inNum=0;
        }
}


void Gary_Check()
{
     if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                Gery_change = 0;
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                Gery_change = 1;
            }
            inNum=0;
        }
}




void Check_Auto()
{
    if(Auto_Light_Switch)
    {
        Auto_Light_Switch = 0;
        OLED_ShowString(48,16,"OFF",8,1);
    }
    if(Gery_change)
    {
        Gery_change = 0;
        OLED_ShowString(56,24,"OFF",8,1);
    }
}


void R_Check()
{
    
         if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                
                if(Encoder_R_Count[Encoder_Site-1]!=0)
                {
                    Encoder_R_Count[Encoder_Site-1]-=1;
                }
                else
                {
                    Encoder_R_Count[Encoder_Site-1]=0;
                }
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                
                if(Encoder_R_Count[Encoder_Site-1]<100)
                {
                    Encoder_R_Count[Encoder_Site-1]+=1;
                }
                else
                {
                    Encoder_R_Count[Encoder_Site-1] = 100;
                }
            }
            inNum=0;
        }
}

void G_Check()
{
    
         if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                
                if(Encoder_G_Count[Encoder_Site-1]!=0)
                {
                    Encoder_G_Count[Encoder_Site-1]-=1;
                }
                else
                {
                    Encoder_G_Count[Encoder_Site-1]=0;
                }
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                
                if(Encoder_G_Count[Encoder_Site-1]<100)
                {
                    Encoder_G_Count[Encoder_Site-1]+=1;
                }
                else
                {
                    Encoder_G_Count[Encoder_Site-1] = 100;
                }
            }
            inNum=0;
        }
}


void B_Check()
{
    
         if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==0&&inNum == 0)
        {
            flag=0;
            if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOB)==1)
            {
                flag = 1;
            }
            inNum = 1;
        }
        if(HAL_GPIO_ReadPin(Encoder_Port,Encoder_GPIOA)==1&&inNum==1)
        {
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 0 ) 
            {
                
                if(Encoder_B_Count[Encoder_Site-1]!=0)
                {
                    Encoder_B_Count[Encoder_Site-1]-=1;
                }
                else
                {
                    Encoder_B_Count[Encoder_Site-1]=0;
                }
            }
            if(HAL_GPIO_ReadPin(Encoder_Port, Encoder_GPIOB) == 1) 
            {
                
                if(Encoder_B_Count[Encoder_Site-1]<100)
                {
                    Encoder_B_Count[Encoder_Site-1]+=1;
                }
                else
                {
                    Encoder_B_Count[Encoder_Site-1] = 100;
                }
            }
            inNum=0;
        }
}



void EXTI1_IRQHandler(void)
{
    HAL_GPIO_EXTI_IRQHandler(Encoder_GPIOA);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == Encoder_GPIOA)
    {
        switch(Temp_Menu_State)
        {
            case 0:Switch_Check();break;
            case 1:Gary_Check();break;
//            case 1:Check_Auto();Encoder_Check();break;
            case 2:Check_Auto();Site_Check();break;
            case 3:Check_Auto();R_Check();break;
            case 4:Check_Auto();G_Check();break;
            case 5:Check_Auto();B_Check();break;

            {
                
            }
        }
        
    }
    
}












