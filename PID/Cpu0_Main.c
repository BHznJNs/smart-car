#include "Cpu0_Main.h"
#include "init.h"
#pragma section all "cpu0_dsram"

int core0_main(void)
{
    get_clk(); // ��ȡʱ��Ƶ��
    all_init();

    //�ȴ����к��ĳ�ʼ�����
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 0xFFFF);
    enableInterrupts();

    while (TRUE) {
        PID_calcL(&PIDl);
        PID_calcR(&PIDr);

        ips114_showint16(0, 0, PIDl.result);

        data_conversion(PIDl.result, 0, 0, 0,virsco_data);
        uart_putbuff(UART_0,virsco_data,10);  //���ߴ��ڷ���
    }
}

#pragma section all restore
