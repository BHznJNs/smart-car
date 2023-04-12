#include "init.h"
#include "zf_common_headfile.h"

#pragma section all "cpu0_dsram"

int core0_main(void)
{
    clock_init();
    debug_init();

    all_init();

    cpu_wait_event_ready();
    while (TRUE)
    {
        if(gps_tau1201_flag)
        {
            gps_tau1201_flag = 0;

            gps_data_parse();           //开始解析数据

            ips200_show_uint(   0, 16*0, gps_tau1201.time.year, 4);
            ips200_show_uint(  80, 16*0, gps_tau1201.time.month, 2);
            ips200_show_uint( 160, 16*0, gps_tau1201.time.day, 2);
            ips200_show_uint(   0, 16*1, gps_tau1201.time.hour, 2);
            ips200_show_uint(  80, 16*1, gps_tau1201.time.minute, 2);
            ips200_show_uint( 160, 16*1, gps_tau1201.time.second, 2);

            ips200_show_uint(   0, 16*2, gps_tau1201.state, 5);
            ips200_show_float(120, 16*2, gps_tau1201.latitude, 4, 6);
            ips200_show_float(  0, 16*3, gps_tau1201.longitude, 4, 6);
            ips200_show_float(120, 16*3, gps_tau1201.speed, 4, 6);
            ips200_show_float(  0, 16*4, gps_tau1201.direction, 4, 6);
            ips200_show_uint( 120, 16*4, gps_tau1201.satellite_used, 5);
            ips200_show_float(  0, 16*5, gps_tau1201.height, 4, 6);
        }
//        system_delay_ms(1000);//这里延时主要目的是为了降低输出速度，便于在串口助手中观察数据，实际使用的时候不需要这样去延时
    }
}

#pragma section all restore
