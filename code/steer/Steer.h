/*
 * Steer.h
 *
 *  Created on: 2022Äê11ÔÂ20ÈÕ
 *      Author: 44176
 */

#ifndef CODE_STEER_H_
#define CODE_STEER_H_

#include "zf_common_headfile.h"

extern int16 resolved_steer;
extern int16 actual_steer;

void steer_control(double angle);

#endif /* CODE_STEER_H_ */
