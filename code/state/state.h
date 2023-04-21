/*
 * state.h
 *
 *  Created on: 2023Äê4ÔÂ13ÈÕ
 *      Author: 44176
 */

#ifndef CODE_STATE_STATE_H_
#define CODE_STATE_STATE_H_

#include "zf_common_headfile.h"

enum MOTION_STATE {
    RUN, STOP,
};

extern int16 motion_state;

// latitude && longitude && bearing
extern double start_latitude;
extern double start_longitude;
extern double target_latitude;
extern double target_longitude;
extern double target_bearing;

extern double current_latitude;
extern double current_longitude;

#endif /* CODE_STATE_STATE_H_ */
