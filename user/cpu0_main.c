#include <utils/sc_math.h>
#include "init.h"
#include "state.h"
#include "isr_config.h"
#include "zf_common_headfile.h"

#pragma section all "cpu0_dsram"

#define FLASH_SECTION_INDEX       (0)  // 存储数据用的扇区
#define FLASH_PAGE_INDEX          (11) // 存储数据用的页码 倒数第一个页码

double points[10][3] = {
    {1, 2, 3}
};

int core0_main(void) {
    clock_init();
    debug_init();

    all_init();

    pit_ms_init(CCU60_CH0, 5);
    cpu_wait_event_ready();

    target_latitude  = points[0][0];
    target_longitude = points[0][1];
    target_bearing   = points[0][2];

    while (TRUE)
    {
        if(gps_tau1201_flag)
        {
            gps_tau1201_flag = 0;

            gps_data_parse(); //开始解析数据

            ips200_show_float(  0, 16*0, gps_tau1201.latitude, 4, 6);
            ips200_show_float(120, 16*0, gps_tau1201.longitude, 4, 6);

            ips200_show_float(  0, 16*2, start_latitude   , 4, 6);
            ips200_show_float(120, 16*2, start_longitude  , 4, 6);
            ips200_show_float(  0, 16*3, target_latitude  , 4, 6);
            ips200_show_float(120, 16*3, target_longitude , 4, 6);

            current_latitude  = gps_tau1201.latitude;
            current_longitude = gps_tau1201.longitude;
            double diff_latitude  = abs_f(current_latitude  - target_latitude);
            double diff_longitude = abs_f(current_longitude - target_longitude);
            if (diff_latitude <= 0.00001 && diff_longitude <= 0.00001) {
                motion_state = STOP;
            }

            double current_bearing = get_two_points_azimuth(current_latitude, current_longitude, target_latitude, target_longitude);
            double diff_bearing = target_bearing - current_bearing;
            steer_control(diff_bearing);
            ips200_show_float(  0, 16*5 , current_bearing, 4, 6);
            ips200_show_float(120, 16*5 , target_bearing , 4, 6);
            ips200_show_float(  0, 16*6 , diff_bearing   , 4, 6);
            ips200_show_int  (  0, 16*8 , (int32)resolved_steer, 10);
            ips200_show_int  (120, 16*8 , (int32)actual_steer  , 10);
            ips200_show_int  (  0, 16*10, (int32)icm20602_gyro_z, 10);
        }

        // key1 -> run
        if (get_key(SINGLE_CLICK) == 1) {
            motion_state = RUN;
        }
        // key2 -> get start point
        if (get_key(SINGLE_CLICK) == 2) {
            start_latitude  = gps_tau1201.latitude;
            start_longitude = gps_tau1201.longitude;
            target_bearing   = get_two_points_azimuth(start_latitude, start_longitude, target_latitude, target_longitude);
        }
        // key3 -> get target point
        if (get_key(SINGLE_CLICK) == 3) {
            target_latitude  = gps_tau1201.latitude;
            target_longitude = gps_tau1201.longitude;
            target_bearing   = get_two_points_azimuth(start_latitude, start_longitude, target_latitude, target_longitude);
        }

        if (motion_state == RUN) {
            run(1500);
        }
    }
}

#pragma section all restore
