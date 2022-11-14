/*
 * PID.h
 *
 *  Created on: 2022年11月13日
 *      Author: 44176
 */

#ifndef CODE_PID_H_
#define CODE_PID_H_

#include "headfile.h"

typedef struct {
    int16 target; // 目标 编码器 值

    int16 kp;
    int16 ki;
    int16 kd;

    int16 current_error; // 现在的误差
    int16 sum_error; // 误差总和

    int16 result; // 计算结果
} PID;

extern PID PIDl;
extern PID PIDr;

void PID_init(PID* vPID);
void PID_calcL(PID* vPID);
void PID_calcR(PID* vPID);

#endif /* CODE_PID_H_ */
