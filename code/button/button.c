/*
 * button.c
 *
 *  Created on: 2023年4月13日
 *      Author: 44176
 */

#include "button.h"

// 获取当前被按下的按键
int get_key(int mode) {
    static int key_up = 1; // 按键松开标志
    if (key_up && ((0 == gpio_get_level(KEY1)) || (0 == gpio_get_level(KEY2))|| (0 == gpio_get_level(KEY3))|| (0 == gpio_get_level(KEY4))))
    {
        if(mode == SINGLE_CLICK)
            key_up = 0;
        if(mode == DOUBLE_CLICK)
            key_up = 1;
        if (gpio_get_level(KEY1) == 0)
        {
            return 1;
        }
        else if (gpio_get_level(KEY2) == 0)
        {
            return 2;
        }
        else if (gpio_get_level(KEY3) == 0)
        {
            return 3;
        }
        else if (gpio_get_level(KEY4) == 0)
        {
            return 4;
        }
    }
    if (mode == SINGLE_CLICK && 1 == gpio_get_level(KEY1) && 1 == gpio_get_level(KEY2) && 1 == gpio_get_level(KEY3) && 1 == gpio_get_level(KEY4))
    {
        key_up = 1;
    }
    return 0; //无按键按下
}


