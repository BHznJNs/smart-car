/*
 * init.c
 *
 *  Created on: 2023年4月10日
 *      Author: 44176
 */

#include "zf_common_headfile.h"

#define IPS200_TYPE     (IPS200_TYPE_PARALLEL8)
#define Steer_Pin ATOM1_CH1_P33_9 // 舵机接口

void all_init(void) {
    gps_init();
    ips200_init(IPS200_TYPE);

    pwm_init(Steer_Pin, 50, 750); // 舵机
    // 初始化电机引脚
    pwm_init(ATOM1_CH5_P02_5, 1000, 0);
    gpio_init(P33_7, GPO, 0, GPO_PUSH_PULL);
}
