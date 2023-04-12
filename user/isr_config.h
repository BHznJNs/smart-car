/*********************************************************************************************************************
* TC377 Opensourec Library ����TC377 ��Դ�⣩��һ�����ڹٷ� SDK �ӿڵĵ�������Դ��
* Copyright (c) 2022 SEEKFREE ��ɿƼ�
*
* ���ļ��� TC377 ��Դ���һ����
*
* TC377 ��Դ�� ���������
* �����Ը���������������ᷢ���� GPL��GNU General Public License���� GNUͨ�ù�������֤��������
* �� GPL �ĵ�3�棨�� GPL3.0������ѡ��ģ��κκ����İ汾�����·�����/���޸���
*
* ����Դ��ķ�����ϣ�����ܷ������ã�����δ�������κεı�֤
* ����û�������������Ի��ʺ��ض���;�ı�֤
* ����ϸ����μ� GPL
*
* ��Ӧ�����յ�����Դ���ͬʱ�յ�һ�� GPL �ĸ���
* ���û�У������<https://www.gnu.org/licenses/>
*
* ����ע����
* ����Դ��ʹ�� GPL3.0 ��Դ����֤Э�� ������������Ϊ���İ汾
* ��������Ӣ�İ��� libraries/doc �ļ����µ� GPL3_permission_statement.txt �ļ���
* ����֤������ libraries �ļ����� �����ļ����µ� LICENSE �ļ�
* ��ӭ��λʹ�ò����������� ���޸�����ʱ���뱣����ɿƼ��İ�Ȩ����������������
*
* �ļ�����          isr_config
* ��˾����          �ɶ���ɿƼ����޹�˾
* �汾��Ϣ          �鿴 libraries/doc �ļ����� version �ļ� �汾˵��
* ��������          ADS v1.8.0
* ����ƽ̨          TC377TP
* ��������          https://seekfree.taobao.com/
*
* �޸ļ�¼
* ����              ����                ��ע
* 2022-11-03       pudding            first version
********************************************************************************************************************/

#ifndef _isr_config_h
#define _isr_config_h



//======================================================�ر�ע��====================================================
// �ж����ȼ���������Ϊ��ֵͬ�������ж����ȼ�����������Ϊ��һ����ֵ
//======================================================�ر�ע��====================================================
//======================================================�ر�ע��====================================================
// �ж����ȼ���������Ϊ��ֵͬ�������ж����ȼ�����������Ϊ��һ����ֵ
//======================================================�ر�ע��====================================================
//======================================================�ر�ע��====================================================
// �ж����ȼ���������Ϊ��ֵͬ�������ж����ȼ�����������Ϊ��һ����ֵ
//======================================================�ر�ע��====================================================
//ISR_PRIORITY�� TC377����255���ж����ȼ��������� 1-255��0���ȼ���ʾ�������жϣ�255Ϊ������ȼ�

//INT_SERVICE��    �궨������ж���˭������Ҳ��Ϊ�����ṩ�ߣ���TC377�У��жϱ��������񣩣������÷�ΧIfxSrc_Tos_cpu0 IfxSrc_Tos_cpu1 IfxSrc_Tos_cpu2 IfxSrc_Tos_dma  ��������Ϊ����ֵ


//���INT_SERVICE����ΪIfxSrc_Tos_dma�Ļ���ISR_PRIORITY�Ŀ����÷�Χ����0-127��


//================================================PIT�жϲ�����ض���===============================================
#define CCU6_0_CH0_INT_SERVICE  IfxSrc_Tos_cpu0     // ����CCU6_0 PITͨ��0�жϷ������ͣ����ж�����˭��Ӧ���� IfxSrc_Tos_cpu0 IfxSrc_Tos_cpu1 IfxSrc_Tos_cpu2 IfxSrc_Tos_dma  ��������Ϊ����ֵ
#define CCU6_0_CH0_ISR_PRIORITY 30                  // ����CCU6_0 PITͨ��0�ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��

#define CCU6_0_CH1_INT_SERVICE  IfxSrc_Tos_cpu0
#define CCU6_0_CH1_ISR_PRIORITY 31

#define CCU6_1_CH0_INT_SERVICE  IfxSrc_Tos_cpu0
#define CCU6_1_CH0_ISR_PRIORITY 32

#define CCU6_1_CH1_INT_SERVICE  IfxSrc_Tos_cpu0
#define CCU6_1_CH1_ISR_PRIORITY 33



//================================================GPIO�жϲ�����ض���===============================================
// ͨ��0��ͨ��4�ǹ���һ���жϺ��� ���ж��ڲ�ͨ����־λ�ж���˭�������ж�
#define EXTI_CH0_CH4_INT_SERVICE IfxSrc_Tos_cpu0    // ����ERUͨ��0��ͨ��4�жϷ������ͣ����ж�����˭��Ӧ���� IfxSrc_Tos_cpu0 IfxSrc_Tos_cpu1 IfxSrc_Tos_cpu2 IfxSrc_Tos_dma  ��������Ϊ����ֵ
#define EXTI_CH0_CH4_INT_PRIO   40                  // ����ERUͨ��0��ͨ��4�ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��

// ͨ��1��ͨ��5�ǹ���һ���жϺ��� ���ж��ڲ�ͨ����־λ �ж���˭�������ж�
#define EXTI_CH1_CH5_INT_SERVICE IfxSrc_Tos_cpu0    // ����ERUͨ��1��ͨ��5�жϷ������ͣ�ͬ��
#define EXTI_CH1_CH5_INT_PRIO   41                  // ����ERUͨ��1��ͨ��5�ж����ȼ� ͬ��

// ͨ��2��ͨ��6�ǹ���һ���жϺ��� ���ж��ڲ�ͨ����־λ �ж���˭�������ж�
#define EXTI_CH2_CH6_INT_SERVICE IfxSrc_Tos_dma     // ����ERUͨ��2��ͨ��6�жϷ������ͣ�ͬ��
#define EXTI_CH2_CH6_INT_PRIO   5                   // ����ERUͨ��2��ͨ��6�ж����ȼ� �����÷�ΧΪ0-127

// ͨ��3��ͨ��7�ǹ���һ���жϺ��� ���ж��ڲ�ͨ����־λ �ж���˭�������ж�
#define EXTI_CH3_CH7_INT_SERVICE IfxSrc_Tos_cpu0    // ����ERUͨ��3��ͨ��7�жϷ������ͣ�ͬ��
#define EXTI_CH3_CH7_INT_PRIO   43                  // ����ERUͨ��3��ͨ��7�ж����ȼ� ͬ��


//===================================================DMA�жϲ�����ض���===============================================
#define DMA_INT_SERVICE         IfxSrc_Tos_cpu0     // ERU����DMA�жϷ������ͣ����ж�����˭��Ӧ���� IfxSrc_Tos_cpu0 IfxSrc_Tos_cpu1 IfxSrc_Tos_cpu2 IfxSrc_Tos_dma  ��������Ϊ����ֵ
#define DMA_INT_PRIO            60                  // ERU����DMA�ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��


//===================================================�����жϲ�����ض���===============================================
#define UART0_INT_SERVICE       IfxSrc_Tos_cpu0     // ���崮��0�жϷ������ͣ����ж�����˭��Ӧ����  IfxSrc_Tos_cpu0 IfxSrc_Tos_cpu1 IfxSrc_Tos_cpu2 IfxSrc_Tos_dma  ��������Ϊ����ֵ
#define UART0_TX_INT_PRIO       11                  // ���崮��0�����ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��
#define UART0_RX_INT_PRIO       10                  // ���崮��0�����ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��
#define UART0_ER_INT_PRIO       12                  // ���崮��0�����ж����ȼ� ���ȼ���Χ1-255 Խ�����ȼ�Խ�� ��ƽʱʹ�õĵ�Ƭ����һ��

#define UART1_INT_SERVICE       IfxSrc_Tos_cpu0
#define UART1_TX_INT_PRIO       13
#define UART1_RX_INT_PRIO       14
#define UART1_ER_INT_PRIO       15

#define UART2_INT_SERVICE       IfxSrc_Tos_cpu0
#define UART2_TX_INT_PRIO       16
#define UART2_RX_INT_PRIO       17
#define UART2_ER_INT_PRIO       18

#define UART3_INT_SERVICE       IfxSrc_Tos_cpu0
#define UART3_TX_INT_PRIO       19
#define UART3_RX_INT_PRIO       20
#define UART3_ER_INT_PRIO       21







//------------�ж�������ѡ�񣨲������޸ģ�------------
#define CCU6_0_CH0_INT_VECTAB_NUM  (int)CCU6_0_CH0_INT_SERVICE  > 0 ? (int)CCU6_0_CH0_INT_SERVICE  - 1 : (int)CCU6_0_CH0_INT_SERVICE
#define CCU6_0_CH1_INT_VECTAB_NUM  (int)CCU6_0_CH1_INT_SERVICE  > 0 ? (int)CCU6_0_CH1_INT_SERVICE  - 1 : (int)CCU6_0_CH1_INT_SERVICE
#define CCU6_1_CH0_INT_VECTAB_NUM  (int)CCU6_1_CH0_INT_SERVICE  > 0 ? (int)CCU6_1_CH0_INT_SERVICE  - 1 : (int)CCU6_1_CH0_INT_SERVICE
#define CCU6_1_CH1_INT_VECTAB_NUM  (int)CCU6_1_CH1_INT_SERVICE  > 0 ? (int)CCU6_1_CH1_INT_SERVICE  - 1 : (int)CCU6_1_CH1_INT_SERVICE

#define ERU_CH0_CH4_INT_VECTAB_NUM (int)ERU_CH0_CH4_INT_SERVICE > 0 ? (int)ERU_CH0_CH4_INT_SERVICE - 1 : (int)ERU_CH0_CH4_INT_SERVICE
#define ERU_CH1_CH5_INT_VECTAB_NUM (int)ERU_CH1_CH5_INT_SERVICE > 0 ? (int)ERU_CH1_CH5_INT_SERVICE - 1 : (int)ERU_CH1_CH5_INT_SERVICE
#define ERU_CH2_CH6_INT_VECTAB_NUM (int)ERU_CH2_CH6_INT_SERVICE > 0 ? (int)ERU_CH2_CH6_INT_SERVICE - 1 : (int)ERU_CH2_CH6_INT_SERVICE
#define ERU_CH3_CH7_INT_VECTAB_NUM (int)ERU_CH3_CH7_INT_SERVICE > 0 ? (int)ERU_CH3_CH7_INT_SERVICE - 1 : (int)ERU_CH3_CH7_INT_SERVICE

#define ERU_DMA_INT_VECTAB_NUM     (int)ERU_DMA_INT_SERVICE     > 0 ? (int)ERU_DMA_INT_SERVICE     - 1 : (int)ERU_DMA_INT_SERVICE

#define UART0_INT_VECTAB_NUM       (int)UART0_INT_SERVICE       > 0 ? (int)UART0_INT_SERVICE       - 1 : (int)UART0_INT_SERVICE
#define UART1_INT_VECTAB_NUM       (int)UART1_INT_SERVICE       > 0 ? (int)UART1_INT_SERVICE       - 1 : (int)UART1_INT_SERVICE
#define UART2_INT_VECTAB_NUM       (int)UART2_INT_SERVICE       > 0 ? (int)UART2_INT_SERVICE       - 1 : (int)UART2_INT_SERVICE
#define UART3_INT_VECTAB_NUM       (int)UART3_INT_SERVICE       > 0 ? (int)UART3_INT_SERVICE       - 1 : (int)UART3_INT_SERVICE

#endif