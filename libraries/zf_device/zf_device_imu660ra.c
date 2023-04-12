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
* �ļ�����          zf_device_imu660ra
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
/*********************************************************************************************************************
* ���߶��壺
*                   ------------------------------------
*                   ģ��ܽ�            ��Ƭ���ܽ�
*                   // Ӳ�� SPI ����
*                   SCL/SPC           �鿴 zf_device_imu660ra.h �� IMU660RA_SPC_PIN �궨��
*                   SDA/DSI           �鿴 zf_device_imu660ra.h �� IMU660RA_SDI_PIN �궨��
*                   SA0/SDO           �鿴 zf_device_imu660ra.h �� IMU660RA_SDO_PIN �궨��
*                   CS                �鿴 zf_device_imu660ra.h �� IMU660RA_CS_PIN �궨��
*                   VCC               3.3V��Դ
*                   GND               ��Դ��
*                   ������������
*
*                   // ���� IIC ����
*                   SCL/SPC           �鿴 zf_device_imu660ra.h �� IMU660RA_SCL_PIN �궨��
*                   SDA/DSI           �鿴 zf_device_imu660ra.h �� IMU660RA_SDA_PIN �궨��
*                   VCC               3.3V��Դ
*                   GND               ��Դ��
*                   ������������
*                   ------------------------------------
********************************************************************************************************************/

#include "zf_common_debug.h"
#include "zf_driver_delay.h"
#include "zf_driver_spi.h"
#include "zf_driver_gpio.h"
#include "zf_driver_soft_iic.h"
#include "zf_device_config.h"
#include "zf_device_imu660ra.h"

int16 imu660ra_gyro_x = 0, imu660ra_gyro_y = 0, imu660ra_gyro_z = 0;                           // ��������������      gyro (������)
int16 imu660ra_acc_x = 0, imu660ra_acc_y = 0, imu660ra_acc_z = 0;                              // ������ٶȼ�����     acc (accelerometer ���ٶȼ�)

#if IMU660RA_USE_SOFT_IIC
static soft_iic_info_struct imu660ra_iic_struct;

#define imu660ra_write_register(reg, data)        (soft_iic_write_8bit_register (&imu660ra_iic_struct, (reg), (data)))
#define imu660ra_write_registers(reg, data, len)  (soft_iic_write_8bit_registers(&imu660ra_iic_struct, (reg), (data), (len)))
#define imu660ra_read_register(reg)               (soft_iic_read_8bit_register  (&imu660ra_iic_struct, (reg)))
#define imu660ra_read_registers(reg, data, len)   (soft_iic_read_8bit_registers (&imu660ra_iic_struct, (reg), (data), (len)))
#else
//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA д�Ĵ���
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ����
// ���ز���     void
// ʹ��ʾ��     imu660ra_write_register(IMU660RA_PWR_CONF, 0x00);                   // �رո߼�ʡ��ģʽ
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void imu660ra_write_register(uint8 reg, uint8 data)
{
    IMU660RA_CS(0);
    spi_write_8bit_register(IMU660RA_SPI, reg | IMU660RA_SPI_W, data);
    IMU660RA_CS(1);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA д����
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ����
// ���ز���     void
// ʹ��ʾ��     imu660ra_write_registers(IMU660RA_INIT_DATA, imu660ra_config_file, sizeof(imu660ra_config_file));
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void imu660ra_write_registers(uint8 reg, const uint8 *data, uint32 len)
{
    IMU660RA_CS(0);
    spi_write_8bit_registers(IMU660RA_SPI, reg | IMU660RA_SPI_W, data, len);
    IMU660RA_CS(1);
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA ���Ĵ���
// ����˵��     reg             �Ĵ�����ַ
// ���ز���     uint8           ����
// ʹ��ʾ��     imu660ra_read_register(IMU660RA_CHIP_ID);
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static uint8 imu660ra_read_register(uint8 reg)
{
    uint8 data[2];
    IMU660RA_CS(0);
    spi_read_8bit_registers(IMU660RA_SPI, reg | IMU660RA_SPI_R, data, 2);
    IMU660RA_CS(1);
    return data[1];
}

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA ������
// ����˵��     reg             �Ĵ�����ַ
// ����˵��     data            ���ݻ�����
// ����˵��     len             ���ݳ���
// ���ز���     void
// ʹ��ʾ��     imu660ra_read_registers(IMU660RA_ACC_ADDRESS, dat, 6);
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static void imu660ra_read_registers(uint8 reg, uint8 *data, uint32 len)
{
    uint8 temp_data[7];
    IMU660RA_CS(0);
    spi_read_8bit_registers(IMU660RA_SPI, reg | IMU660RA_SPI_R, temp_data, len + 1);
    IMU660RA_CS(1);
    for(int i = 0; i < len; i ++)
    {
        *(data ++) = temp_data[i + 1];
    }
}
#endif

//-------------------------------------------------------------------------------------------------------------------
// �������     IMU660RA �Լ�
// ����˵��     void
// ���ز���     uint8           1-�Լ�ʧ�� 0-�Լ�ɹ�
// ʹ��ʾ��     imu660ra_self_check();
// ��ע��Ϣ     �ڲ�����
//-------------------------------------------------------------------------------------------------------------------
static uint8 imu660ra_self_check (void)
{
    uint8 dat = 0, return_state = 0;
    uint16 timeout_count = 0;
    do
    {
        if(timeout_count ++ > IMU660RA_TIMEOUT_COUNT)
        {
            return_state =  1;
            break;
        }
        dat = imu660ra_read_register(IMU660RA_CHIP_ID);
        system_delay_ms(1);
    }while(0x24 != dat);                                                    // ��ȡ�豸ID�Ƿ����0X24���������0X24����Ϊû��⵽�豸
    return return_state;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ���ٶȼ�����
// ����˵��     void
// ���ز���     void
// ʹ��ʾ��     imu660ra_get_acc();                                             // ִ�иú�����ֱ�Ӳ鿴��Ӧ�ı�������
// ��ע��Ϣ     ʹ�� SPI �Ĳɼ�ʱ��Ϊ69us
//            ʹ�� IIC �Ĳɼ�ʱ��Ϊ126us        �ɼ����ٶȼƵ�ʱ����ɼ������ǵ�ʱ��һ�µ�ԭ���Ƕ�ֻ�Ƕ�ȡ�Ĵ�������
//-------------------------------------------------------------------------------------------------------------------
void imu660ra_get_acc (void)
{
    uint8 dat[6];

    imu660ra_read_registers(IMU660RA_ACC_ADDRESS, dat, 6);
    imu660ra_acc_x = (int16)(((uint16)dat[1]<<8 | dat[0]));
    imu660ra_acc_y = (int16)(((uint16)dat[3]<<8 | dat[2]));
    imu660ra_acc_z = (int16)(((uint16)dat[5]<<8 | dat[4]));
}
//-------------------------------------------------------------------------------------------------------------------
// �������     ��ȡ IMU660RA ����������
// ����˵��     void
// ���ز���     void
// ʹ��ʾ��     imu660ra_get_gyro();                                            // ִ�иú�����ֱ�Ӳ鿴��Ӧ�ı�������
// ��ע��Ϣ     ʹ�� SPI �Ĳɼ�ʱ��Ϊ69us
//            ʹ�� IIC �Ĳɼ�ʱ��Ϊ126us
//-------------------------------------------------------------------------------------------------------------------
void imu660ra_get_gyro (void)
{
    uint8 dat[6];

    imu660ra_read_registers(IMU660RA_GYRO_ADDRESS, dat, 6);
    imu660ra_gyro_x = (int16)(((uint16)dat[1]<<8 | dat[0]));
    imu660ra_gyro_y = (int16)(((uint16)dat[3]<<8 | dat[2]));
    imu660ra_gyro_z = (int16)(((uint16)dat[5]<<8 | dat[4]));
}

//-------------------------------------------------------------------------------------------------------------------
// �������     �� IMU660RA ���ٶȼ�����ת��Ϊʵ����������
// ����˵��     gyro_value              // ������ļ��ٶȼ�����
// ���ز���     void
// ʹ��ʾ��     float data = imu660ra_acc_transition(imu660ra_acc_x);  //��λΪ g(m/s^2)
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
float imu660ra_acc_transition (int16 acc_value)
{
    float acc_data = 0;
    switch(IMU660RA_ACC_SAMPLE)
    {
        case 0x00: acc_data = (float)acc_value / 16384; break; // 0x00 ���ٶȼ�����Ϊ:��2g          ��ȡ���ļ��ٶȼ����� ����16384      ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        case 0x01: acc_data = (float)acc_value / 8192; break;  // 0x01 ���ٶȼ�����Ϊ:��4g          ��ȡ���ļ��ٶȼ����� ����8192       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        case 0x02: acc_data = (float)acc_value / 4096; break;  // 0x02 ���ٶȼ�����Ϊ:��8g          ��ȡ���ļ��ٶȼ����� ����4096       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        case 0x03: acc_data = (float)acc_value / 2048; break;  // 0x03 ���ٶȼ�����Ϊ:��16g         ��ȡ���ļ��ٶȼ����� ����2048       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        default: break;
    }
    return acc_data;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     �� IMU660RA ����������ת��Ϊʵ����������
// ����˵��     gyro_value              // �����������������
// ���ز���     void
// ʹ��ʾ��     float data = imu660ra_gyro_transition(imu660ra_gyro_x);  // ��λΪ��/s
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
float imu660ra_gyro_transition (int16 gyro_value)
{
    float gyro_data = 0;
    switch(IMU660RA_GYR_SAMPLE)
    {
        case 0x00: gyro_data = (float)gyro_value / 16.4f;  break;  //  0x00 ����������Ϊ:��2000dps      ��ȡ�������������ݳ���16.4          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        case 0x01: gyro_data = (float)gyro_value / 32.8f;  break;  //  0x01 ����������Ϊ:��1000dps      ��ȡ�������������ݳ���32.8          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        case 0x02: gyro_data = (float)gyro_value / 65.6f;  break;  //  0x02 ����������Ϊ:��500 dps      ��ȡ�������������ݳ���65.6          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        case 0x03: gyro_data = (float)gyro_value / 131.2f; break;  //  0x03 ����������Ϊ:��250 dps      ��ȡ�������������ݳ���131.2         ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        case 0x04: gyro_data = (float)gyro_value / 262.4f; break;  //  0x04 ����������Ϊ:��125 dps      ��ȡ�������������ݳ���262.4         ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        default: break;
    }
    return gyro_data;
}

//-------------------------------------------------------------------------------------------------------------------
// �������     ��ʼ�� IMU660RA
// ����˵��     void
// ���ز���     uint8           1-��ʼ��ʧ�� 0-��ʼ���ɹ�
// ʹ��ʾ��     imu660ra_init();
// ��ע��Ϣ
//-------------------------------------------------------------------------------------------------------------------
uint8 imu660ra_init (void)
{
    uint8 return_state = 0;
    system_delay_ms(20);                                                    // �ȴ��豸�ϵ�ɹ�
#if IMU660RA_USE_SOFT_IIC
    soft_iic_init(&imu660ra_iic_struct, IMU660RA_DEV_ADDR, IMU660RA_SOFT_IIC_DELAY, IMU660RA_SCL_PIN, IMU660RA_SDA_PIN);        // ���� IMU660RA �� IIC�˿�
#else
    spi_init(IMU660RA_SPI, SPI_MODE0, IMU660RA_SPI_SPEED, IMU660RA_SPC_PIN, IMU660RA_SDI_PIN, IMU660RA_SDO_PIN, SPI_CS_NULL);   // ���� IMU660RA �� SPI�˿�
    gpio_init(IMU660RA_CS_PIN, GPO, GPIO_HIGH, GPO_PUSH_PULL);                                                                  // ���� IMU660RA �� CS�˿�
    imu660ra_read_register(IMU660RA_CHIP_ID);                                                                                   // ��ȡһ���豸ID�����豸����ΪSPIģʽ
#endif
    do{
        if(imu660ra_self_check())                                           // IMU660RA�Լ�
        {
            // �������������˶�����Ϣ ������ʾ����λ��������
            // ��ô���� imu660ra �Լ��������ʱ�˳���
            // ���һ�½�����û������ ���û������ܾ��ǻ���
            zf_log(0, "imu660ra self check error.");
            return_state = 1;
            break;
        }
        imu660ra_write_register(IMU660RA_PWR_CONF, 0x00);                   // �رո߼�ʡ��ģʽ
        system_delay_ms(1);
        imu660ra_write_register(IMU660RA_INIT_CTRL, 0x00);                  // ��ʼ��ģ����г�ʼ������
        imu660ra_write_registers(IMU660RA_INIT_DATA, imu660ra_config_file, sizeof(imu660ra_config_file));                       // ��������ļ�
        imu660ra_write_register(IMU660RA_INIT_CTRL, 0x01);                  // ��ʼ�����ý���
        system_delay_ms(20);
        if(imu660ra_read_register(IMU660RA_INT_STA) == 0)                   // ����Ƿ��������
        {
            // �������������˶�����Ϣ ������ʾ����λ��������
            // ��ô���� imu660ra ���ó�ʼ���ļ�������
            // ���һ�½�����û������ ���û������ܾ��ǻ���
            zf_log(0, "imu660ra init error.");
            return_state = 1;
            break;
        }
        imu660ra_write_register(IMU660RA_PWR_CTRL, 0x0E);                   // ��������ģʽ  ʹ�������ǡ����ٶȡ��¶ȴ�����
        imu660ra_write_register(IMU660RA_ACC_CONF, 0xA7);                   // ���ٶȲɼ����� ����ģʽ �����ɼ� 50Hz ����Ƶ��
        imu660ra_write_register(IMU660RA_GYR_CONF, 0xA9);                   // �����ǲɼ����� ����ģʽ �����ɼ� 200Hz����Ƶ��
        imu660ra_write_register(IMU660RA_ACC_RANGE, IMU660RA_ACC_SAMPLE);   // ���ٶ��������� ��������Ϊ:��8g
        imu660ra_write_register(IMU660RA_GYR_RANGE, IMU660RA_GYR_SAMPLE);   // �������������� ��������Ϊ:��2000dps

        // IMU660RA_GYR_RANGE�Ĵ���
        // ����Ϊ:0x00 ���ٶȼ�����Ϊ:��2g          ��ȡ���ļ��ٶȼ����� ����16384      ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        // ����Ϊ:0x01 ���ٶȼ�����Ϊ:��4g          ��ȡ���ļ��ٶȼ����� ����8192       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        // ����Ϊ:0x02 ���ٶȼ�����Ϊ:��8g          ��ȡ���ļ��ٶȼ����� ����4096       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)
        // ����Ϊ:0x03 ���ٶȼ�����Ϊ:��16g         ��ȡ���ļ��ٶȼ����� ����2048       ����ת��Ϊ��������λ�����ݣ���λ��g(m/s^2)

        // IMU660RA_ACC_SAMPLE�Ĵ���
        // ����Ϊ:0x00 ����������Ϊ:��2000dps      ��ȡ�������������ݳ���16.4          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        // ����Ϊ:0x01 ����������Ϊ:��1000dps      ��ȡ�������������ݳ���32.8          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        // ����Ϊ:0x02 ����������Ϊ:��500 dps      ��ȡ�������������ݳ���65.6          ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        // ����Ϊ:0x03 ����������Ϊ:��250 dps      ��ȡ�������������ݳ���131.2         ����ת��Ϊ��������λ�����ݣ���λΪ����/s
        // ����Ϊ:0x04 ����������Ϊ:��125 dps      ��ȡ�������������ݳ���262.4         ����ת��Ϊ��������λ�����ݣ���λΪ����/s
    }while(0);
    return return_state;
}

