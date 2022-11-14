#include "init.h"
#include <stdlib.h>

PID PIDl;
PID PIDr;

const int16 sum_error_UP = 1000;

void PID_init(PID* vPID) {
    vPID->target = 30;
    vPID->kp = 30;
    vPID->ki = 5;
    vPID->kd = 5;

    vPID->current_error = 0;
    vPID->sum_error = 0;

    vPID->result = 0;
}

void PID_calcL(PID* vPID) {
    int16 target = vPID->target;

    int16 speed_left = gpt12_get(GPT12_T5);
    gpt12_clear(GPT12_T5);

    vPID->current_error = target - speed_left;
    vPID->sum_error += vPID->current_error;

    // 限制积分
    vPID->sum_error = (vPID->sum_error >  sum_error_UP ?  sum_error_UP : vPID->sum_error);
    vPID->sum_error = (vPID->sum_error < -sum_error_UP ? -sum_error_UP : vPID->sum_error);

    vPID->result = vPID->kp * vPID->current_error + vPID->ki * vPID->sum_error;
    vPID->result = (vPID->result >  3000 ?  3000 : vPID->result);
    vPID->result = (vPID->result < -3000 ? -3000 : vPID->result);

    if (vPID->result > 0) {
        pwm_duty(ATOM0_CH0_P21_2,vPID->result);
        gpio_set(P21_3,0);
    } else if (vPID->result <= 0){
        vPID->result = -vPID->result;
        pwm_duty(ATOM0_CH0_P21_2,-vPID->result);
        gpio_set(P21_3,0);
    }
}
void PID_calcR(PID* vPID) {
    int16 target = vPID->target;

    int16 speed_left = -gpt12_get(GPT12_T6);
    gpt12_clear(GPT12_T6);

    vPID->current_error = target - speed_left;
    vPID->sum_error += vPID->current_error;

    // 限制积分
    vPID->sum_error = (vPID->sum_error >  sum_error_UP ?  sum_error_UP : vPID->sum_error);
    vPID->sum_error = (vPID->sum_error < -sum_error_UP ? -sum_error_UP : vPID->sum_error);

    vPID->result = vPID->kp * vPID->current_error + vPID->ki * vPID->sum_error;
    vPID->result = (vPID->result >  3000 ?  3000 : vPID->result);
    vPID->result = (vPID->result < -3000 ? -3000 : vPID->result);

    if (vPID->result > 0) {
        pwm_duty(ATOM0_CH2_P21_4, vPID->result);
        gpio_set(P21_5, 0);
    } else if (vPID->result <= 0){
        vPID->result = -vPID->result;
        pwm_duty(ATOM0_CH2_P21_4, -vPID->result);
        gpio_set(P21_5, 0);
    }
}
