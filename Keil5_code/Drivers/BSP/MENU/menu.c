#include "./BSP/MENU/menu.h"
#include "./BSP/OLED/oled.h"
#include "./BSP/KEY/key.h"
#include "./BSP/TIMER/gtim.h"
#include "./BSP/PCA9685/pca9685.h"
#include "./SYSTEM/usart/usart.h"


#define  half 0.05
#define  quarter 0.025




float RGB_R;
float RGB_G;
float RGB_B;
uint8_t Menu_State;
_Bool Light_Switch;
volatile uint8_t Temp_Menu_State;
volatile _Bool Auto_Light_Switch;
uint8_t Gery_change = 0;
uint8_t safe_site()
{
    if(Encoder_Site>9)
    {Encoder_Site = 9;return 9;}
    else 
    {return Encoder_Site;}
        
}



void set_max_t_pwm(uint8_t max,float R,float G,float B,float RGB0,float RGB1,float RGB2,float RGB3,float RGB4,float RGB5,float RGB6,float RGB7,float RGB8)
{
    SET_PWM(R0,0,max*max*R*RGB0);
    SET_PWM(G0,0,max*max*G*RGB0);
    SET_PWM(B0,0,max*max*B*RGB0);
    
    SET_PWM(R1,0,max*max*R*RGB1);
    SET_PWM(G1,0,max*max*G*RGB1);
    SET_PWM(B1,0,max*max*B*RGB1);
    
    SET_PWM(R2,0,max*max*R*RGB2);
    SET_PWM(G2,0,max*max*G*RGB2);
    SET_PWM(B2,0,max*max*B*RGB2);
    
    SET_PWM(R3,0,max*max*R*RGB3);
    SET_PWM(G3,0,max*max*G*RGB3);
    SET_PWM(B3,0,max*max*B*RGB3);
    
    SET_PWM(R4,0,max*max*R*RGB4);
    SET_PWM(G4,0,max*max*G*RGB4);
    SET_PWM(B4,0,max*max*B*RGB4);
    
    SET_PWM(R5,0,max*max*R*RGB5);
    SET_PWM(G5,0,max*max*G*RGB5);
    SET_PWM(B5,0,max*max*B*RGB5);
    
    SET_PWM(R6,0,max*max*R*RGB6);
    SET_PWM(G6,0,max*max*G*RGB6);
    SET_PWM(B6,0,max*max*B*RGB6);
    
    SET_PWM(R7,0,max*max*R*RGB7);
    SET_PWM(G7,0,max*max*G*RGB7);
    SET_PWM(B7,0,max*max*B*RGB7);
    
    SET_PWM(R8,0,max*max*R*RGB8);
    SET_PWM(G8,0,max*max*G*RGB8);
    SET_PWM(B8,0,max*max*B*RGB8);
    
}




void menu1()
{
    Auto_Light_Switch = 0;
    uint8_t Menu_State = 0;
    uint8_t key = 0;
    /*显示光标*/
    OLED_ShowChar(0,16, '*', 8,1);
    /**/
    OLED_ShowString(51,0,"Lingt",8,1);
    OLED_ShowString(0,8,"Lum:",8,1);
    OLED_ShowNum(24,8,100,3,8,1);
    /**/
    OLED_ShowString(8,16,"Auto:",8,1);
    OLED_ShowString(48,16,"OFF",8,1);
    OLED_ShowString(8,24,"Grays:",8,1);
    OLED_ShowString(56,24,"OFF",8,1);
    /**/
    OLED_ShowString(8,32,"Site:",8,1);
    OLED_ShowNum(48,32,1,1,8,1);
    
    OLED_ShowString(8,40,"R",8,1);
    OLED_ShowNum(16,40,100,3,8,1);/*R值*/
    OLED_ShowString(48,40,"G",8,1);
    OLED_ShowNum(56,40,100,3,8,1);/*G值*/
    OLED_ShowString(88,40,"B",8,1);
    OLED_ShowNum(96,40,100,3,8,1);/*B值*/
    /*更新显示*/
    oled_refresh();
    while(1)
    {
        uint8_t Lum=0;
        for(uint8_t i=0;i<8;i++)
        {
            Lum += Useful_Light[i]/8;
            RGB_R = Useful_Light[8]/(Useful_Light[8]+Useful_Light[9]+Useful_Light[10]);
            RGB_G = Useful_Light[9]/(Useful_Light[8]+Useful_Light[9]+Useful_Light[10]);
            RGB_B = Useful_Light[10]/(Useful_Light[8]+Useful_Light[9]+Useful_Light[10]);
        }
        
        
        OLED_ShowNum(48,32,safe_site(),2,8,1);
        OLED_ShowNum(24,8,Lum,3,8,1);
        OLED_ShowNum(16,40,Encoder_R_Count[Encoder_Site-1],3,8,1);
        OLED_ShowNum(56,40,Encoder_G_Count[Encoder_Site-1],3,8,1);
        OLED_ShowNum(96,40,Encoder_B_Count[Encoder_Site-1],3,8,1);
        key=key_scan(0);

        if(key == Encoder_KEY_PRES)
        {
            Menu_State+=1;
            if(Menu_State==6)
            {
                Menu_State=0;
            }
        }
        if(Temp_Menu_State!=Menu_State)
        {
            Temp_Menu_State = Menu_State;
        }
        
        
            switch(Menu_State)
            {
                case 0:/*自动挡*/
                {
                    if(Auto_Light_Switch==0)
                    {
                        OLED_ShowString(48,16,"OFF",8,1);
                    }
                    else
                    {
                        OLED_ShowString(48,16,"ON ",8,1);
                    }
                    OLED_ShowChar(0,16, '*', 8,1);
                    OLED_ShowChar(0,24, ' ', 8,1);
                    OLED_ShowChar(0,32, ' ', 8,1);
                    OLED_ShowChar(0,40, ' ', 8,1);
                    OLED_ShowChar(40,40, ' ', 8,1);
                    OLED_ShowChar(80,40, ' ', 8,1);
                }break;
                
                case 1:/*灰阶过渡*/
                {
                    if(Gery_change==0)
                    {
                        OLED_ShowString(56,24,"OFF",8,1);
                    }
                    else
                    {
                        OLED_ShowString(56,24,"ON ",8,1);
                    }
                    OLED_ShowChar(0,16, ' ', 8,1);
                    OLED_ShowChar(0,24, '*', 8,1);
                    OLED_ShowChar(0,32, ' ', 8,1);
                    OLED_ShowChar(0,40, ' ', 8,1);
                    OLED_ShowChar(40,40, ' ', 8,1);
                    OLED_ShowChar(80,40, ' ', 8,1);
                    
                }break;
                
                case 2:/*选位置*/
                {
                    OLED_ShowChar(0,16, ' ', 8,1);
                    OLED_ShowChar(0,24, ' ', 8,1);
                    OLED_ShowChar(0,32, '*', 8,1);
                    OLED_ShowChar(0,40, ' ', 8,1);
                    OLED_ShowChar(40,40, ' ', 8,1);
                    OLED_ShowChar(80,40, ' ', 8,1);
                    
                }break;
                
                case 3:/*调R档位*/
                {
                    OLED_ShowChar(0,16, ' ', 8,1);
                    OLED_ShowChar(0,24, ' ', 8,1);
                    OLED_ShowChar(0,32, ' ', 8,1);
                    OLED_ShowChar(0,40, '*', 8,1);
                    OLED_ShowChar(40,40, ' ', 8,1);
                    OLED_ShowChar(80,40, ' ', 8,1);
                    
                }break;
                
                case 4:/*调G档位*/
                {
                    OLED_ShowChar(0,16, ' ', 8,1);
                    OLED_ShowChar(0,24, ' ', 8,1);
                    OLED_ShowChar(0,32, ' ', 8,1);
                    OLED_ShowChar(0,40, ' ', 8,1);
                    OLED_ShowChar(40,40, '*', 8,1);
                    OLED_ShowChar(80,40, ' ', 8,1);
                    
                }break;
                
                case 5:/*调B档位*/
                {
                    OLED_ShowChar(0,16, ' ', 8,1);
                    OLED_ShowChar(0,24, ' ', 8,1);
                    OLED_ShowChar(0,32, ' ', 8,1);
                    OLED_ShowChar(0,40, ' ', 8,1);
                    OLED_ShowChar(40,40, ' ', 8,1);
                    OLED_ShowChar(80,40, '*', 8,1);
                    
                }break;
            }
            oled_refresh();
            
           if(Auto_Light_Switch == 0)
           {
               uint8_t i = 0;
               for(i = R0;i<R0+9;i++)
               {
                   SET_PWM(i,0,Encoder_R_Count[i]*Encoder_R_Count[i]*0.4);
               }
               for(i = G0;i<G0+9;i++)
               {
                   SET_PWM(i,0,Encoder_G_Count[i-9]*Encoder_G_Count[i-9]*0.4);
               }
               for(i = B0;i<B0+9;i++)
               {
                   SET_PWM(i,0,Encoder_B_Count[i-18]*Encoder_B_Count[i-18]*0.4);
                   
               }
            
           }
           else if(Auto_Light_Switch == 1)
           {

                
               
               
               
                if(Gery_change==0)
                {

                    
                    uint8_t i = 0;
                    for(i = R0;i<R0+9;i++)
                    {
                        SET_PWM(i,0,RGB_R*Lum*16);
                    }
                    for(i = G0;i<G0+9;i++)
                    {
                        SET_PWM(i,0,RGB_G*Lum*16);
                    }
                    for(i = B0;i<B0+9;i++)
                    {
                        SET_PWM(i,0,RGB_B*Lum*16);
                    }
                }
                else if(Gery_change==1)
                {
                    uint8_t MAX_Flag = 0,MAX_Count = 0;
                    MAX_Count = Useful_Light[0];
                    for(uint8_t j;j<8;j++)
                    {
                        if(MAX_Count<Useful_Light[j])
                        {
                            MAX_Count=Useful_Light[j];
                            MAX_Flag = j;
                        }
                    }
                    RGB_R = 1;
                    RGB_G = 1;
                    RGB_B = 1;

                    
                    switch(MAX_Flag)
                    {
                        case 0:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,1,half,quarter,half,half,quarter,quarter,quarter,quarter);
                            break;
                        }
                        case 1:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,half,1,half,half,half,half,quarter,quarter,quarter);
                            break;
                        }
                        case 2:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,quarter,half,1,quarter,half,half,quarter,quarter,quarter);
                            break;
                        }
                        case 3:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,half,half,quarter,1,half,quarter,half,half,quarter);
                            break;
                        }
                        case 4:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,quarter,half,half,quarter,half,1,quarter,half,half);
                            break;
                        }
                        case 5:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,quarter,quarter,quarter,half,half,quarter,1,half,quarter);
                            break;
                        }
                        case 6:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,quarter,quarter,quarter,half,half,half,half,1,half);
                            break;
                        }
                        case 7:
                        {
                            set_max_t_pwm(Lum,RGB_R,RGB_G,RGB_B,quarter,quarter,quarter,quarter,half,half,quarter,half,1);
                            break;
                        }
                            
                    }
                }
                
        
           }
        
    }
}


