#include "./BSP/OTHER/other.h"

uint8_t LED_Compare(uint8_t get_led,uint8_t target_led)
{
    if(get_led<target_led)
    {
        return 1;
    }
    else if(get_led>target_led)
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
