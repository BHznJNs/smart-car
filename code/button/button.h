/*
 * button.h
 *
 *  Created on: 2023��4��13��
 *      Author: 44176
 */

#ifndef CODE_BUTTON_BUTTON_H_
#define CODE_BUTTON_BUTTON_H_

#include "zf_common_headfile.h"

#define SINGLE_CLICK 1
#define DOUBLE_CLICK 2

// �ĸ�����
#define KEY1 P22_0
#define KEY2 P22_1
#define KEY3 P22_2
#define KEY4 P22_3

int get_key(int mode);

#endif /* CODE_BUTTON_BUTTON_H_ */
