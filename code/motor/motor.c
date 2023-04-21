/*
 * motor.c
 *
 *  Created on: 2023Äê4ÔÂ13ÈÕ
 *      Author: 44176
 */

#include "motor.h";

void run(int32 pwm) {
    pwm_set_duty(ATOM1_CH5_P02_5, pwm);
    gpio_set_level(P33_7, 0);
}
