#include "Cpu0_Main.h"
#include "init.h"
#pragma section all "cpu0_dsram"

int core0_main(void)
{
    get_clk(); // 获取时钟频率
    all_init();

    //等待所有核心初始化完毕
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();

    while (TRUE) {
        PID_calcL(&PIDl);
        PID_calcR(&PIDr);

        ips114_showint16(0, 0, PIDl.result);

        data_conversion(PIDl.result, 0, 0, 0,virsco_data);
        uart_putbuff(UART_0,virsco_data,10);  //有线串口发送
    }
}

#pragma section all restore
