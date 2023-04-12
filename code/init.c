/*
 * init.c
 *
 *  Created on: 2023��4��10��
 *      Author: 44176
 */

#include "zf_common_headfile.h"

#define IPS200_TYPE     (IPS200_TYPE_PARALLEL8)
#define Steer_Pin ATOM1_CH1_P33_9 // ����ӿ�

void all_init(void) {
    gps_init();
    ips200_init(IPS200_TYPE);

    pwm_init(Steer_Pin, 50, 750); // ���
    // ��ʼ���������
    pwm_init(ATOM1_CH5_P02_5, 1000, 0);
    gpio_init(P33_7, GPO, 0, GPO_PUSH_PULL);
}
