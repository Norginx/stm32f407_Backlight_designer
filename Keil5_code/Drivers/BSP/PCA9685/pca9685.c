#include "./BSP/PCA9685/pca9685.h"
#include "./SYSTEM/delay/delay.h"
#include <math.h>


void PCA9685_IIC_Init()
{
    GPIO_InitTypeDef GPIO_Init_Struct ;
    __HAL_RCC_GPIOG_CLK_ENABLE();
    GPIO_Init_Struct.Pin = GPIO_PIN_5;
    GPIO_Init_Struct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_Init_Struct.Pull = GPIO_PULLUP;
    GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
    
    GPIO_Init_Struct.Pin = GPIO_PIN_6;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
    
    
    
    GPIO_Init_Struct.Pin = GPIO_PIN_7;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
    
    GPIO_Init_Struct.Pin = GPIO_PIN_8;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
}


void PCA9685_delay(void)
{
    uint8_t t=3;
    while(t--);
}


void PCA9685_1_SCL(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_5,GPIO_PIN_SET);
    }
}

void PCA9685_1_SDA(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_SET);
    }
}

void PCA9685_1_Start()
{

    PCA9685_1_SCL(1);
    PCA9685_1_SDA(1);
    PCA9685_delay();
    PCA9685_1_SDA(0);
    PCA9685_delay();
    PCA9685_1_SCL(0);
    PCA9685_delay();
}

void PCA9685_1_Stop()
{

    PCA9685_1_SDA(0);
    PCA9685_1_SCL(1);
    PCA9685_delay();
    PCA9685_1_SDA(1);
}

uint8_t PCA9685_1_Wait_ACK()
{
    uint8_t ucErrTime = 0;

    PCA9685_1_SDA(1);
    delay_us(2);
    PCA9685_1_SCL(1);
    delay_us(2);
    while(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_6))
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            PCA9685_1_Stop();
            return 1;
        }
    }
        PCA9685_1_SCL(0);
        return 0;
}

void PCA9685_1_ACK()
{
    PCA9685_1_SCL(0);

    PCA9685_1_SDA(0);
    PCA9685_delay();
    PCA9685_1_SCL(1);
    PCA9685_delay();
    PCA9685_1_SCL(0);
}

void PCA9685_1_NACK()
{

    PCA9685_1_SDA(1);
    PCA9685_delay();
    PCA9685_1_SCL(1);
    PCA9685_delay();
    PCA9685_1_SCL(0);
    PCA9685_delay();
    
}

void PCA9685_1_sent_byte(uint8_t byte)
{
    uint8_t i ;

    for(i=0;i<8;i++)
    {
        if(byte&0x80)
        {
            PCA9685_1_SDA(1);
        }
        else
        {
            PCA9685_1_SDA(0);
        }
        PCA9685_delay();
        PCA9685_1_SCL(1);
        PCA9685_delay();
        PCA9685_1_SCL(0);
        byte = byte<<1;
        
    }
}

uint8_t PCA9685_1_read_byte(uint8_t ack)
{
    	uint8_t i,receive=0;
    for(i=0;i<8;i++ )
	{
        PCA9685_1_SCL(0); 
        delay_us(2);
		PCA9685_1_SCL(1);
        receive<<=1;
        if(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_6))receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        PCA9685_1_NACK();
    else
        PCA9685_1_ACK(); 
    return receive;

}


uint8_t PCA9685_1_Read(uint8_t addr)
{
	uint8_t data;
	
	PCA9685_1_Start();
	
	PCA9685_1_sent_byte(PCA_Addr);
	PCA9685_1_NACK();
	
	PCA9685_1_sent_byte(addr);
	PCA9685_1_NACK();
	
	PCA9685_1_Stop();
	
	delay_us(10);

	
	PCA9685_1_Start();

	PCA9685_1_sent_byte(PCA_Addr|0x01);
	PCA9685_1_NACK();
	
	data = PCA9685_1_read_byte(0);
	
	PCA9685_1_Stop();
	
	return data;
	
}

void PCA9685_1_Write(uint8_t addr,uint8_t data)
{
	PCA9685_1_Start();
	
	PCA9685_1_sent_byte(PCA_Addr);
	PCA9685_1_NACK();
	
	PCA9685_1_sent_byte(addr);
	PCA9685_1_NACK();
	
	PCA9685_1_sent_byte(data);
	PCA9685_1_NACK();
	
	PCA9685_1_Stop();
	
	
}


void PCA9685_1_setFreq(float freq)
{
	uint8_t prescale,oldmode,newmode;
	
	double prescaleval;
	
	//freq *= 0.92;
	prescaleval = 25000000;
	prescaleval /= 4096;
	prescaleval /= freq;
	prescaleval -= 1;
	prescale = floor(prescaleval+0.5f);
	oldmode = PCA9685_1_Read(PCA_Model);
	
	newmode = (oldmode&0x7F)|0x10;
	PCA9685_1_Write(PCA_Model,newmode);
	PCA9685_1_Write(PCA_Pre,prescale);
	PCA9685_1_Write(PCA_Model,oldmode);
	delay_ms(5);
	PCA9685_1_Write(PCA_Model,oldmode|0xa1);
	
	
}


void PCA9685_1_setPWM(uint8_t num,uint32_t on,uint32_t off)
{
	PCA9685_1_Start();
	
	PCA9685_1_sent_byte(PCA_Addr);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_sent_byte(LED0_ON_L+4*num);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_sent_byte(on&0xFF);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_sent_byte(on>>8);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_sent_byte(off&0xFF);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_sent_byte(off>>8);
	PCA9685_1_Wait_ACK();
	
	PCA9685_1_Stop();
	
}









void PCA9685_2_SCL(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_SET);
    }
}

void PCA9685_2_SDA(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_8,GPIO_PIN_SET);
    }
}

void PCA9685_2_Start()
{

    PCA9685_2_SCL(1);
    PCA9685_2_SDA(1);
    PCA9685_delay();
    PCA9685_2_SDA(0);
    PCA9685_delay();
    PCA9685_2_SCL(0);
    PCA9685_delay();
}

void PCA9685_2_Stop()
{

    PCA9685_2_SDA(0);
    PCA9685_2_SCL(1);
    PCA9685_delay();
    PCA9685_2_SDA(1);
}

uint8_t PCA9685_2_Wait_ACK()
{
    uint8_t ucErrTime = 0;

    PCA9685_2_SDA(1);
    delay_us(2);
    PCA9685_2_SCL(1);
    delay_us(2);
    while(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_8))
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            PCA9685_2_Stop();
            return 1;
        }
    }
        PCA9685_2_SCL(0);
        return 0;
}

void PCA9685_2_ACK()
{
    PCA9685_2_SCL(0);

    PCA9685_2_SDA(0);
    PCA9685_delay();
    PCA9685_2_SCL(1);
    PCA9685_delay();
    PCA9685_2_SCL(0);
}

void PCA9685_2_NACK()
{

    PCA9685_2_SDA(1);
    PCA9685_delay();
    PCA9685_2_SCL(1);
    PCA9685_delay();
    PCA9685_2_SCL(0);
    PCA9685_delay();
    
}

void PCA9685_2_sent_byte(uint8_t byte)
{
    uint8_t i ;

    for(i=0;i<8;i++)
    {
        if(byte&0x80)
        {
            PCA9685_2_SDA(1);
        }
        else
        {
            PCA9685_2_SDA(0);
        }
        PCA9685_delay();
        PCA9685_2_SCL(1);
        PCA9685_delay();
        PCA9685_2_SCL(0);
        byte = byte<<1;
        
    }
}

uint8_t PCA9685_2_read_byte(uint8_t ack)
{
    	uint8_t i,receive=0;
    for(i=0;i<8;i++ )
	{
        PCA9685_2_SCL(0); 
        delay_us(2);
		PCA9685_2_SCL(1);
        receive<<=1;
        if(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_8))receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        PCA9685_2_NACK();
    else
        PCA9685_2_ACK(); 
    return receive;

}


uint8_t PCA9685_2_Read(uint8_t addr)
{
	uint8_t data;
	
	PCA9685_2_Start();
	
	PCA9685_2_sent_byte(PCA_Addr);
	PCA9685_2_NACK();
	
	PCA9685_2_sent_byte(addr);
	PCA9685_2_NACK();
	
	PCA9685_2_Stop();
	
	delay_us(10);

	
	PCA9685_2_Start();

	PCA9685_2_sent_byte(PCA_Addr|0x01);
	PCA9685_2_NACK();
	
	data = PCA9685_2_read_byte(0);
	
	PCA9685_2_Stop();
	
	return data;
	
}

void PCA9685_2_Write(uint8_t addr,uint8_t data)
{
	PCA9685_2_Start();
	
	PCA9685_2_sent_byte(PCA_Addr);
	PCA9685_2_NACK();
	
	PCA9685_2_sent_byte(addr);
	PCA9685_2_NACK();
	
	PCA9685_2_sent_byte(data);
	PCA9685_2_NACK();
	
	PCA9685_2_Stop();
	
	
}


void PCA9685_2_setFreq(float freq)
{
	uint8_t prescale,oldmode,newmode;
	
	double prescaleval;
	
	freq *= 0.92;
	prescaleval = 25000000;
	prescaleval /= 4096;
	prescaleval /= freq;
	prescaleval -= 1;
	prescale = floor(prescaleval+0.5f);
	oldmode = PCA9685_2_Read(PCA_Model);
	
	newmode = (oldmode&0x7F)|0x10;
	PCA9685_2_Write(PCA_Model,newmode);
	PCA9685_2_Write(PCA_Pre,prescale);
	PCA9685_2_Write(PCA_Model,oldmode);
	delay_ms(5);
	PCA9685_2_Write(PCA_Model,oldmode|0xa1);
	
	
}


void PCA9685_2_setPWM(uint8_t num,uint32_t on,uint32_t off)
{
	PCA9685_2_Start();
	
	PCA9685_2_sent_byte(PCA_Addr);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_sent_byte(LED0_ON_L+4*num);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_sent_byte(on&0xFF);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_sent_byte(on>>8);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_sent_byte(off&0xFF);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_sent_byte(off>>8);
	PCA9685_2_Wait_ACK();
	
	PCA9685_2_Stop();
	
}












void PCA9685_Init(float hz)
{
	uint32_t off = 0;
	PCA9685_IIC_Init();
	PCA9685_1_Write(PCA_Model,0x00);
	PCA9685_1_setFreq(hz);
	PCA9685_2_Write(PCA_Model,0x00);
	PCA9685_2_setFreq(hz);
	off =0;
	PCA9685_1_setPWM(0,0,off);
	PCA9685_1_setPWM(1,0,off);
	PCA9685_1_setPWM(2,0,off);
	PCA9685_1_setPWM(3,0,off);
	PCA9685_1_setPWM(4,0,off);
	PCA9685_1_setPWM(5,0,off);
	PCA9685_1_setPWM(6,0,off);
	PCA9685_1_setPWM(7,0,off);
	PCA9685_1_setPWM(8,0,off);
	PCA9685_1_setPWM(9,0,off);
	PCA9685_1_setPWM(10,0,off);
	PCA9685_1_setPWM(11,0,off);
	PCA9685_1_setPWM(12,0,off);
	PCA9685_1_setPWM(13,0,off);
	PCA9685_1_setPWM(14,0,off);
	PCA9685_1_setPWM(15,0,off);

	PCA9685_2_setPWM(0,0,off);
	PCA9685_2_setPWM(1,0,off);
	PCA9685_2_setPWM(2,0,off);
	PCA9685_2_setPWM(3,0,off);
	PCA9685_2_setPWM(4,0,off);
	PCA9685_2_setPWM(5,0,off);
	PCA9685_2_setPWM(6,0,off);
	PCA9685_2_setPWM(7,0,off);
	PCA9685_2_setPWM(8,0,off);
	PCA9685_2_setPWM(9,0,off);
	PCA9685_2_setPWM(10,0,off);
	PCA9685_2_setPWM(11,0,off);
	PCA9685_2_setPWM(12,0,off);
	PCA9685_2_setPWM(13,0,off);
	PCA9685_2_setPWM(14,0,off);
	PCA9685_2_setPWM(15,0,off);
	delay_ms(100);
	
}

void SET_PWM(uint8_t num,uint32_t on,uint32_t off)
{
    if(num>15)
    {
        PCA9685_2_setPWM(num-16,on,off);
    }
    else
    {
        PCA9685_1_setPWM(num,on,off);
    }
}




