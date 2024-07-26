#include "./BSP/OLED/oled.h"
#include "./BSP/OLED/font.h"
#include "./BSP/OLED/bmp.h"
#include "./SYSTEM/delay/delay.h"
uint8_t oled_gram[128][8];





void GPIO_Init()
{
    GPIO_InitTypeDef GPIO_Init_Struct ;
    __HAL_RCC_GPIOG_CLK_ENABLE();
    GPIO_Init_Struct.Pin = GPIO_PIN_3;
    GPIO_Init_Struct.Mode = GPIO_MODE_OUTPUT_OD;
    GPIO_Init_Struct.Pull = GPIO_PULLUP;
    GPIO_Init_Struct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
    
    GPIO_Init_Struct.Pin = GPIO_PIN_4;
    HAL_GPIO_Init(GPIOG,&GPIO_Init_Struct);
    
    oled_write(0xAE,CMD);//--turn off oled panel
    oled_write(0x00,CMD);//---set low column address
    oled_write(0x10,CMD);//---set high column address
    oled_write(0x40,CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
    oled_write(0x81,CMD);//--set contrast control register
    oled_write(0xCF,CMD);// Set SEG Output Current Brightness
    oled_write(0xA1,CMD);//--Set SEG/Column Mapping     0xa0���ҷ��� 0xa1����
    oled_write(0xC8,CMD);//Set COM/Row Scan Direction   0xc0���·��� 0xc8����
    oled_write(0xA6,CMD);//--set normal display
    oled_write(0xA8,CMD);//--set multiplex ratio(1 to 64)
    oled_write(0x3f,CMD);//--1/64 duty
    oled_write(0xD3,CMD);//-set display offset    Shift Mapping RAM Counter (0x00~0x3F)
    oled_write(0x00,CMD);//-not offset
    oled_write(0xd5,CMD);//--set display clock divide ratio/oscillator frequency
    oled_write(0x80,CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
    oled_write(0xD9,CMD);//--set pre-charge period
    oled_write(0xF1,CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
    oled_write(0xDA,CMD);//--set com pins hardware configuration
    oled_write(0x12,CMD);
    oled_write(0xDB,CMD);//--set vcomh
    oled_write(0x40,CMD);//Set VCOM Deselect Level
    oled_write(0x20,CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
    oled_write(0x02,CMD);//
    oled_write(0x8D,CMD);//--set Charge Pump enable/disable
    oled_write(0x14,CMD);//--set(0x10) disable
    oled_write(0xA4,CMD);// Disable Entire Display On (0xa4/0xa5)
    oled_write(0xA6,CMD);// Disable Inverse Display On (0xa6/a7) 
    oled_clear();
    oled_write(0xAF,CMD);
    
}


void IIC_delay(void)
{
    uint8_t t=3;
    while(t--);
}


void SCL(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_3,GPIO_PIN_SET);
    }
}


void SDA(uint8_t x)
{
    if(x==0)
    {
         HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_RESET);
    }
    else
    {
        HAL_GPIO_WritePin(GPIOG,GPIO_PIN_4,GPIO_PIN_SET);
    }
}

void IIC_Start()
{

    SCL(1);
    SDA(1);
    IIC_delay();
    SDA(0);
    IIC_delay();
    SCL(0);
    IIC_delay();
}

void IIC_Stop()
{

    SDA(0);
    SCL(1);
    IIC_delay();
    SDA(1);
}

uint8_t Wait_ACK()
{
    uint8_t ucErrTime = 0;

    SDA(1);
    delay_us(2);
    SCL(1);
    delay_us(2);
    while(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_4))
    {
        ucErrTime++;
        if(ucErrTime>250)
        {
            IIC_Stop();
            return 1;
        }
    }
        SCL(0);
        return 0;
}


void ACK()
{
    SCL(0);

    SDA(0);
    IIC_delay();
    SCL(1);
    IIC_delay();
    SCL(0);
}

void NACK()
{

    SDA(1);
    IIC_delay();
    SCL(1);
    IIC_delay();
    SCL(0);
    IIC_delay();
    
}

void sent_byte(uint8_t byte)
{
    uint8_t i ;

    for(i=0;i<8;i++)
    {
        if(byte&0x80)
        {
            SDA(1);
        }
        else
        {
            SDA(0);
        }
        IIC_delay();
        SCL(1);
        IIC_delay();
        SCL(0);
        byte = byte<<1;
        
    }
}
uint8_t read_byte(uint8_t ack)
{
    	uint8_t i,receive=0;
    for(i=0;i<8;i++ )
	{
        SCL(0); 
        delay_us(2);
		SCL(1);
        receive<<=1;
        if(HAL_GPIO_ReadPin(GPIOG,GPIO_PIN_4))receive++;   
		delay_us(1); 
    }					 
    if (!ack)
        NACK();
    else
        ACK(); 
    return receive;

}

void oled_write(uint8_t data ,uint8_t mode)
{
    IIC_Start();
    sent_byte(0x78);
    NACK();
    if(mode)
    {
        sent_byte(0x40);
    }
    else
    {
        sent_byte(0x00);
    }
    NACK();
    sent_byte(data);
    NACK();
    IIC_Stop();
}

void oled_display_on()
{
    oled_write(0x8D,CMD);
    oled_write(0x14,CMD);
    oled_write(0xAF,CMD);
}

void oled_display_off()
{
    oled_write(0x8D,CMD);
    oled_write(0x10,CMD);
    oled_write(0xAE,CMD);
}

void oled_refresh()
{
    uint8_t i ,n;
    for(i=0;i<8;i++)
    {
        oled_write(0xB0+i,CMD);
        oled_write(0x00,CMD);
        oled_write(0x10,CMD);
        IIC_Start();
        sent_byte(0X78);
        NACK();
        sent_byte(0X40);
        NACK();
        for(n=0;n<128;n++)
        {
            sent_byte(oled_gram[n][i]);
            NACK();
        }
        IIC_Stop();
    }
    
}

void oled_clear()
{
    uint8_t i,j;
    for(i=0;i<8;i++)
    {
        for(j=0;j<128;j++)
        {
            oled_gram[j][i] = 0;
        }
    }
    oled_refresh();
}

void oled_drawpoint(uint8_t x,uint8_t y,uint8_t t)
{
    uint8_t m,line,page;
    page = y/8;
    line = y%8;
    m=1<<line;
    if(t)
    {
        oled_gram[x][page] |=m;
    }
    else
    {
        oled_gram[x][page] = ~oled_gram[x][page];
        oled_gram[x][page]|=m;
        oled_gram[x][page] = ~oled_gram[x][page];
    }
}


uint32_t OLED_Pow(uint8_t m,uint8_t n)
{
	uint32_t result=1;
	while(n--)
	{
	  result*=m;
	}
	return result;
}


void OLED_ShowNum(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size1,uint8_t mode)
{
    uint8_t t,temp,m=0;
    if(size1==8)m=2;
    for(t=0;t<len;t++)
    {
        temp=(num/OLED_Pow(10,len-t-1))%10;
            if(temp==0)
            {
                OLED_ShowChar(x+(size1/2+m)*t,y,'0',size1,mode);
      }
            else 
            {
              OLED_ShowChar(x+(size1/2+m)*t,y,temp+'0',size1,mode);
            }
  }
}


void OLED_ShowPicture(uint8_t x,uint8_t y,uint8_t sizex,uint8_t sizey,uint8_t BMP[],uint8_t mode)//��ʾһ��ͼ������
{
    uint16_t j=0;
    uint8_t i,n,temp,m;
    uint8_t x0=x,y0=y;
    sizey=sizey/8+((sizey%8)?1:0);
    for(n=0;n<sizey;n++)
   {
        for(i=0;i<sizex;i++)
        {
                temp=BMP[j];
                j++;
                for(m=0;m<8;m++)
                {
                    if(temp&0x01)oled_drawpoint(x,y,mode);
                    else oled_drawpoint(x,y,!mode);
                    temp>>=1;
                    y++;
                }
                x++;
                if((x-x0)==sizex)
                {
                    x=x0;
                    y0=y0+8;
                }
                y=y0;
     }
     }
}


void OLED_ShowChinese(uint8_t x,uint8_t y,uint8_t num,uint8_t size1,uint8_t mode)//��ʾһ�������ֺ���
{
    uint8_t m,temp;
    uint8_t x0=x,y0=y;
    uint16_t i,size3=(size1/8+((size1%8)?1:0))*size1;  //�õ�����һ���ַ���Ӧ������ռ���ֽ���
    for(i=0;i<size3;i++)
    {
        if(size1==16)
                {temp=Hzk1[num][i];}//����16*16����
        else if(size1==24)
                {temp=Hzk2[num][i];}//����24*24����
        else if(size1==32)       
                {temp=Hzk3[num][i];}//����32*32����
        else if(size1==64)
                {temp=Hzk4[num][i];}//����64*64����
        else return;
        for(m=0;m<8;m++)
        {
            if(temp&0x01)oled_drawpoint(x,y,mode);
            else oled_drawpoint(x,y,!mode);
            temp>>=1;
            y++;
        }
        x++;
        if((x-x0)==size1)
        {x=x0;y0=y0+8;}
        y=y0;
    }
}





void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t size1,uint8_t mode)//��ʾһ���ַ�����
{
    uint8_t i,m,temp,size2,chr1;
    uint8_t x0=x,y0=y;
    if(size1==8)size2=6;
    else size2=(size1/8+((size1%8)?1:0))*(size1/2);  //�õ�����һ���ַ���Ӧ������ռ���ֽ���
    chr1=chr-' ';  //����ƫ�ƺ��ֵ
    for(i=0;i<size2;i++)
    {
        if(size1==8)
              {temp=asc2_0806[chr1][i];} //����0806����
        else if(size1==12)
        {temp=asc2_1206[chr1][i];} //����1206����
        else if(size1==16)
        {temp=asc2_1608[chr1][i];} //����1608����
        else if(size1==24)
        {temp=asc2_2412[chr1][i];} //����2412����
        else return;
        for(m=0;m<8;m++)
        {
            if(temp&0x01)oled_drawpoint(x,y,mode);
            else oled_drawpoint(x,y,!mode);
            temp>>=1;
            y++;
        }
        x++;
        if((size1!=8)&&((x-x0)==size1/2))
        {x=x0;y0=y0+8;}
        y=y0;
  }
}

void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t size1,uint8_t mode)
{
    while((*chr>=' ')&&(*chr<='~'))//�ж��ǲ��ǷǷ��ַ�!
    {
        OLED_ShowChar(x,y,*chr,size1,mode);
        if(size1==8)x+=6;
        else x+=size1/2;
        chr++;
  }
}




void OLED_Clean_Area(uint8_t x,uint8_t y,uint8_t size1)
{
    uint8_t y0 = y,x0 = x;
    uint8_t m,i,size3=(size1/8+((size1%8)?1:0))*size1;
    for(i=0;i<size3;i++)
    {
        for(m=0;m<8;m++)
            {
                oled_drawpoint(x,y,0);
                y++;
            }
        x++;
        if((x-x0)==size1)
        {x=x0;y0=y0+8;}
        y=y0;
    }
}












