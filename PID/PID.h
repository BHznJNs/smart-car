/*
 * PID.h
 *
 *  Created on: 2022��11��13��
 *      Author: 44176
 */

#ifndef CODE_PID_H_
#define CODE_PID_H_

#include "headfile.h"

typedef struct {
    int16 target; // Ŀ�� ������ ֵ

    int16 kp;
    int16 ki;
    int16 kd;

    int16 current_error; // ���ڵ����
    int16 sum_error; // ����ܺ�

    int16 result; // ������
} PID;

extern PID PIDl;
extern PID PIDr;

void PID_init(PID* vPID);
void PID_calcL(PID* vPID);
void PID_calcR(PID* vPID);

#endif /* CODE_PID_H_ */
