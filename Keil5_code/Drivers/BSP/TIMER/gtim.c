//#include "./BSP/TIMER/gtim.h"
//TIM_HandleTypeDef g_timx_pwm1_chy_handle;
//TIM_HandleTypeDef g_timx_pwm2_chy_handle;
//TIM_HandleTypeDef g_timx_pwm3_chy_handle;
//TIM_HandleTypeDef g_timx_pwm4_chy_handle;
//TIM_HandleTypeDef g_timx_pwm5_chy_handle;
//TIM_HandleTypeDef g_timx_pwm9_chy_handle;
//TIM_HandleTypeDef g_timx_pwm10_chy_handle;
//TIM_HandleTypeDef g_timx_pwm11_chy_handle;
//TIM_HandleTypeDef g_timx_pwm12_chy_handle;
//TIM_HandleTypeDef g_timx_pwm13_chy_handle;
//TIM_HandleTypeDef g_timx_pwm14_chy_handle;



//void gtim_tim1_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm1_chy_handle.Instance = TIM1;                     /* 定时器x */
//    g_timx_pwm1_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm1_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm1_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm1_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm1_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm1_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm1_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm1_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm1_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_3); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm1_chy_handle, TIM_CHANNEL_3);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm1_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_4); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm1_chy_handle, TIM_CHANNEL_4);       /* 开启对应PWM通道 */

//}

//void gtim_tim2_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm2_chy_handle.Instance = TIM2;                     /* 定时器x */
//    g_timx_pwm2_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm2_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm2_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm2_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm2_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm2_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm2_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm2_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm2_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_3); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm2_chy_handle, TIM_CHANNEL_3);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm2_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_4); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm2_chy_handle, TIM_CHANNEL_4);       /* 开启对应PWM通道 */

//}


//void gtim_tim3_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm3_chy_handle.Instance = TIM3;                     /* 定时器x */
//    g_timx_pwm3_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm3_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm3_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm3_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm3_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm3_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm3_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm3_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm3_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_3); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm3_chy_handle, TIM_CHANNEL_3);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm3_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_4); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm3_chy_handle, TIM_CHANNEL_4);       /* 开启对应PWM通道 */

//}



//void gtim_tim4_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm4_chy_handle.Instance = TIM4;                     /* 定时器x */
//    g_timx_pwm4_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm4_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm4_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm4_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm4_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm4_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm4_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm4_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm4_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_3); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm4_chy_handle, TIM_CHANNEL_3);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm4_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_4); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm4_chy_handle, TIM_CHANNEL_4);       /* 开启对应PWM通道 */

//}




//void gtim_tim5_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm5_chy_handle.Instance = TIM5;                     /* 定时器x */
//    g_timx_pwm5_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm5_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm5_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm5_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm5_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm5_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm5_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm5_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm5_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_3); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm5_chy_handle, TIM_CHANNEL_3);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm5_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_4); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm5_chy_handle, TIM_CHANNEL_4);       /* 开启对应PWM通道 */

//}

//void gtim_tim9_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm9_chy_handle.Instance = TIM9;                     /* 定时器x */
//    g_timx_pwm9_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm9_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm9_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm9_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm9_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm9_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm9_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_2); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm9_chy_handle, TIM_CHANNEL_2);       /* 开启对应PWM通道 */

//}

//void gtim_tim10_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm10_chy_handle.Instance = TIM10;                     /* 定时器x */
//    g_timx_pwm10_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm10_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm10_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm10_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm10_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm10_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */


//}

//void gtim_tim11_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm11_chy_handle.Instance = TIM11;                     /* 定时器x */
//    g_timx_pwm11_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm11_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm11_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm11_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm11_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm11_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */


//}


//void gtim_tim12_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm12_chy_handle.Instance = TIM12;                     /* 定时器x */
//    g_timx_pwm12_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm12_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm12_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm12_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm12_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm12_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */


//}

//void gtim_tim13_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm13_chy_handle.Instance = TIM13;                     /* 定时器x */
//    g_timx_pwm13_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm13_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm13_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm13_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm13_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm13_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */


//}

//void gtim_tim14_pwm_chy_init(uint16_t psc,uint16_t arr)
//{
//    TIM_OC_InitTypeDef timx_oc_pwm_chy  = {0};                          /* 定时器PWM输出配置 */

//    g_timx_pwm14_chy_handle.Instance = TIM13;                     /* 定时器x */
//    g_timx_pwm14_chy_handle.Init.Prescaler = psc;                         /* 定时器分频 */
//    g_timx_pwm14_chy_handle.Init.CounterMode = TIM_COUNTERMODE_UP;        /* 递增计数模式 */
//    g_timx_pwm14_chy_handle.Init.Period = arr;                            /* 自动重装载值 */
//    HAL_TIM_PWM_Init(&g_timx_pwm14_chy_handle);                           /* 初始化PWM */

//    timx_oc_pwm_chy.OCMode = TIM_OCMODE_PWM1;                           /* 模式选择PWM1 */
//    timx_oc_pwm_chy.Pulse = 0;                                    /* 设置比较值,此值用来确定占空比 */
//                                                                        /* 默认比较值为自动重装载值的一半,即占空比为50% */
//    timx_oc_pwm_chy.OCPolarity = TIM_OCPOLARITY_HIGH;                    /* 输出比较极性为低 */
//    HAL_TIM_PWM_ConfigChannel(&g_timx_pwm14_chy_handle, &timx_oc_pwm_chy, TIM_CHANNEL_1); /* 配置TIMx通道y */
//    HAL_TIM_PWM_Start(&g_timx_pwm14_chy_handle, TIM_CHANNEL_1);       /* 开启对应PWM通道 */


//}



//void HAL_TIM_PWM_MspInit(TIM_HandleTypeDef *htim)
//{
//    if(htim->Instance == TIM1)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOA_CLK_ENABLE();               /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM1_CLK_ENABLE();
//        __HAL_RCC_GPIOE_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_11; /* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF1_TIM1;
//        HAL_GPIO_Init(GPIOA, &gpio_init_struct);
//        gpio_init_struct.Pin = GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13;
//        HAL_GPIO_Init(GPIOE, &gpio_init_struct);
//    }        
//        
//    
//    
//    else if (htim->Instance == TIM2)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOA_CLK_ENABLE();               /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_GPIOB_CLK_ENABLE();
//        __HAL_RCC_TIM2_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_3|GPIO_PIN_10|GPIO_PIN_11; /* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF1_TIM2;
//        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
//        gpio_init_struct.Pin = GPIO_PIN_5;
//        HAL_GPIO_Init(GPIOA, &gpio_init_struct);
//    }
//    
//    
//    
//    else if (htim->Instance == TIM3)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOA_CLK_ENABLE();               /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_GPIOB_CLK_ENABLE(); 
//        __HAL_RCC_TIM3_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_6|GPIO_PIN_7;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF2_TIM3;
//        HAL_GPIO_Init(GPIOA, &gpio_init_struct);
//        gpio_init_struct.Pin = GPIO_PIN_0|GPIO_PIN_1;
//        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
//    }
//    
//    else if (htim->Instance == TIM4)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOB_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM4_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF2_TIM4;
//        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
//    }
//    
//    
//    else if (htim->Instance == TIM5)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOB_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM5_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF2_TIM4;
//        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM9)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOE_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM9_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_5|GPIO_PIN_6;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF3_TIM9;
//        HAL_GPIO_Init(GPIOE, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM10)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOF_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM10_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_6;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF3_TIM10;
//        HAL_GPIO_Init(GPIOF, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM11)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOF_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM11_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_7;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF3_TIM11;
//        HAL_GPIO_Init(GPIOF, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM12)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOB_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM12_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_14;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF9_TIM12;
//        HAL_GPIO_Init(GPIOB, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM13)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOF_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM13_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_8;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF9_TIM13;
//        HAL_GPIO_Init(GPIOF, &gpio_init_struct);
//    }
//    
//     else if (htim->Instance == TIM14)
//    {
//        GPIO_InitTypeDef gpio_init_struct;
//        __HAL_RCC_GPIOF_CLK_ENABLE();                /* 开启通道y的CPIO时钟 */
//        __HAL_RCC_TIM14_CLK_ENABLE();

//        gpio_init_struct.Pin = GPIO_PIN_9;/* 通道y的CPIO口 */
//        gpio_init_struct.Mode = GPIO_MODE_AF_PP;           /* 复用推完输出 */
//        gpio_init_struct.Pull = GPIO_PULLUP;               /* 上拉 */
//        gpio_init_struct.Speed = GPIO_SPEED_FREQ_HIGH;     /* 高速 */
//        gpio_init_struct.Alternate = GPIO_AF9_TIM14;
//        HAL_GPIO_Init(GPIOF, &gpio_init_struct);
//    }
//    
//}

//void Init_All_PWM()
//{
//    gtim_tim1_pwm_chy_init(168-1,500);
//    gtim_tim2_pwm_chy_init(84-1,500);
//    gtim_tim3_pwm_chy_init(84-1,500);
//    gtim_tim4_pwm_chy_init(84-1,500);
//    gtim_tim5_pwm_chy_init(84-1,500);
//    gtim_tim9_pwm_chy_init(168-1,500);
//    gtim_tim10_pwm_chy_init(168-1,500);
//    gtim_tim11_pwm_chy_init(168-1,500);
//    gtim_tim12_pwm_chy_init(84-1,500);
//    gtim_tim13_pwm_chy_init(84-1,500);
//    gtim_tim14_pwm_chy_init(84-1,500);
//}

//void PWM_Set(uint8_t site ,uint8_t count)
//{
//    switch(site)
//    {
//        case 1:__HAL_TIM_SET_COMPARE(&g_timx_pwm2_chy_handle,TIM_CHANNEL_1,count);break;
//        case 2:__HAL_TIM_SET_COMPARE(&g_timx_pwm2_chy_handle,TIM_CHANNEL_2,count);break;
//        case 3:__HAL_TIM_SET_COMPARE(&g_timx_pwm2_chy_handle,TIM_CHANNEL_3,count);break;
//        case 4:__HAL_TIM_SET_COMPARE(&g_timx_pwm2_chy_handle,TIM_CHANNEL_4,count);break;
//        case 5:__HAL_TIM_SET_COMPARE(&g_timx_pwm3_chy_handle,TIM_CHANNEL_1,count);break;
//        case 6:__HAL_TIM_SET_COMPARE(&g_timx_pwm3_chy_handle,TIM_CHANNEL_2,count);break;
//        case 7:__HAL_TIM_SET_COMPARE(&g_timx_pwm3_chy_handle,TIM_CHANNEL_3,count);break;
//        case 8:__HAL_TIM_SET_COMPARE(&g_timx_pwm3_chy_handle,TIM_CHANNEL_4,count);break;
//        case 9:__HAL_TIM_SET_COMPARE(&g_timx_pwm4_chy_handle,TIM_CHANNEL_1,count);break;
//        
//        case 10:__HAL_TIM_SET_COMPARE(&g_timx_pwm4_chy_handle,TIM_CHANNEL_2,count);break;
//        case 11:__HAL_TIM_SET_COMPARE(&g_timx_pwm4_chy_handle,TIM_CHANNEL_3,count);break;
//        case 12:__HAL_TIM_SET_COMPARE(&g_timx_pwm4_chy_handle,TIM_CHANNEL_4,count);break;
//        case 13:__HAL_TIM_SET_COMPARE(&g_timx_pwm5_chy_handle,TIM_CHANNEL_1,count);break;
//        case 14:__HAL_TIM_SET_COMPARE(&g_timx_pwm5_chy_handle,TIM_CHANNEL_2,count);break;
//        case 15:__HAL_TIM_SET_COMPARE(&g_timx_pwm5_chy_handle,TIM_CHANNEL_3,count);break;
//        case 16:__HAL_TIM_SET_COMPARE(&g_timx_pwm5_chy_handle,TIM_CHANNEL_4,count);break;
//        case 17:__HAL_TIM_SET_COMPARE(&g_timx_pwm9_chy_handle,TIM_CHANNEL_1,count);break;
//        case 18:__HAL_TIM_SET_COMPARE(&g_timx_pwm9_chy_handle,TIM_CHANNEL_2,count);break;
//            
//        case 19:__HAL_TIM_SET_COMPARE(&g_timx_pwm10_chy_handle,TIM_CHANNEL_1,count);break;
//        case 20:__HAL_TIM_SET_COMPARE(&g_timx_pwm11_chy_handle,TIM_CHANNEL_1,count);break;
//        case 21:__HAL_TIM_SET_COMPARE(&g_timx_pwm12_chy_handle,TIM_CHANNEL_1,count);break;
//        case 22:__HAL_TIM_SET_COMPARE(&g_timx_pwm13_chy_handle,TIM_CHANNEL_1,count);break;
//        case 23:__HAL_TIM_SET_COMPARE(&g_timx_pwm14_chy_handle,TIM_CHANNEL_1,count);break;
//        case 24:__HAL_TIM_SET_COMPARE(&g_timx_pwm1_chy_handle,TIM_CHANNEL_1,count);break;
//        case 25:__HAL_TIM_SET_COMPARE(&g_timx_pwm1_chy_handle,TIM_CHANNEL_2,count);break;
//        case 26:__HAL_TIM_SET_COMPARE(&g_timx_pwm1_chy_handle,TIM_CHANNEL_3,count);break;
//        case 27:__HAL_TIM_SET_COMPARE(&g_timx_pwm1_chy_handle,TIM_CHANNEL_4,count);break;
//    }
//}
