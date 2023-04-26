#include "steer.h"

const int16 mid_duty   = 750;
const int16 left_duty  = 1050;
const int16 right_duty = 450;

int16 resolved_steer = 750;
int16 actual_steer = 750;
double kp_angle = 15;    // 15
double kd_angle = 0.75;  // 0.75

double angle_resolve(double angle) {
    if (angle > 180) {
        return angle - 360;
    } else if (angle < -180) {
        return angle + 360;
    } else {
        return angle;
    }
}

// 0 <= angle <= 360
void steer_control(double angle) {
    angle = angle_resolve(angle);

    resolved_steer = mid_duty - kp_angle * (angle) + kd_angle * (0 - icm20602_gyro_z);
    actual_steer = resolved_steer;
    actual_steer = (actual_steer > left_duty ) ? left_duty  : actual_steer;
    actual_steer = (actual_steer < right_duty) ? right_duty : actual_steer;

    pwm_set_duty(ATOM1_CH1_P33_9, (uint32)actual_steer);
}
