/*
 * init.c
 *
 *  Created on: 2022��11��8��
 *      Author: 44176
 */

#include "init.h"

int16 encoder3 = 0;
int16 encoder4 = 0;

int16 steer_duty = 0;
int16 mid_duty   = 754;
int16 left_duty  = 834;
int16 right_duty = 670;

uint8 virsco_data[10];

void all_init(void) {
    ips114_init();  // ��ʼ��IPS��Ļ
    mt9v03x_init(); // ��ʼ������ͷ

    gtm_pwm_init(Steer_Pin, 50, mid_duty); // ���

    // ��������ʼ��
    gpt12_init(GPT12_T5, GPT12_T5INB_P10_3, GPT12_T5EUDB_P10_1);
    gpt12_init(GPT12_T6, GPT12_T6INA_P20_3, GPT12_T6EUDA_P20_0);

    //��ʼ��PWM����
    gtm_pwm_init(MOTOR1_PWM, 17000, 0);
    gtm_pwm_init(MOTOR2_PWM, 17000, 0);

    gpio_init(MOTOR1_DIR, GPO, 0, PUSHPULL);
    gpio_init(MOTOR2_DIR, GPO, 0, PUSHPULL);

    // PID ��ʼ��
    PID_init(&PIDl);
    PID_init(&PIDr);

    // �жϳ�ʼ��
    pit_interrupt_ms(CCU6_0, PIT_CH0, 5);
}
// ��ȡ��ǰ�����µİ���
int get_key(int mode) {
    static int key_up = 1; // �����ɿ���־
    if (key_up && ((0 == gpio_get(KEY1)) || (0 == gpio_get(KEY2))|| (0 == gpio_get(KEY3))|| (0 == gpio_get(KEY4))))
    {
        systick_delay_ms(STM0, 10); // ����
        if(mode == SINGLE_CLICK )
            key_up = 0;
        if(mode == DOUBLE_CLICK )
            key_up = 1;
        if (gpio_get(KEY1) == 0)
        {
            return 1;
        }
        else if (gpio_get(KEY2) == 0)
        {
            return 2;
        }
        else if (gpio_get(KEY3) == 0)
        {
            return 3;
        }
        else if (gpio_get(KEY4) == 0)
        {
            return 4;
        }
    }
    if (mode == SINGLE_CLICK && 1 == gpio_get(KEY1) && 1 == gpio_get(KEY2) && 1 == gpio_get(KEY3) && 1 == gpio_get(KEY4))
    {
        key_up = 1;
    }
    return 0; //�ް�������
}
