/*
 * state.c
 *
 *  Created on: 2023Äê4ÔÂ16ÈÕ
 *      Author: 44176
 */

#include "state.h"

int16 motion_state = STOP;

double start_latitude    = 0;
double start_longitude   = 0;
double target_latitude   = 0;
double target_longitude  = 0;
double target_bearing    = 0;

double current_latitude  = 0;
double current_longitude = 0;
