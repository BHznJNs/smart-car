/*
 * init.h
 *
 *  Created on: 2022年11月8日
 *      Author: 44176
 */

#ifndef CODE_INIT_H_
#define CODE_INIT_H_

#include "headfile.h"
#include "PID.h"

// 四个按键
#define KEY1 P22_0
#define KEY2 P22_1
#define KEY3 P22_2
#define KEY4 P22_3

// 电机
#define MOTOR1_PWM ATOM0_CH2_P21_4 // 速度
#define MOTOR2_PWM ATOM0_CH0_P21_2
#define MOTOR1_DIR P21_5 // 方向
#define MOTOR2_DIR P21_3

// 舵机接口
#define Steer_Pin ATOM1_CH1_P33_9

#define SINGLE_CLICK 1
#define DOUBLE_CLICK 2

extern int16 encoder3;
extern int16 encoder4;

// 舵机
extern int16 steer_duty;
extern int16 mid_duty;
extern int16 left_duty;
extern int16 right_duty;

// 示波器数据
extern uint8 virsco_data[10];

void all_init(void);
int get_key(int mode);

#endif /* CODE_INIT_H_ */
