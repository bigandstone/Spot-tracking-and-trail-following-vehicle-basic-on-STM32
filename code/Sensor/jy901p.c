#include "jy901p.h"
#include "usart.h"

static uint8_t rx_buff[100];
static uint8_t rx_idx;
static uint8_t rx_data;

uint8_t jy_acc_buff[10];
uint8_t jy_gyro_buff[10];
uint8_t jy_angle_buff[10];
uint8_t jy_mag_buff[10];

static uint8_t flag;

float jy_x;
float jy_y;
float jy_z;

void JY_Init(){
    HAL_UART_Receive_IT(&huart3, &rx_data, 1);
}

void JY_UART_RxCpltCallback(){
	rx_buff[rx_idx++] = rx_data;
	if (rx_buff[0] != 0x55){
		rx_idx = 0;
	}
	else if(rx_idx >= 11){
		switch(rx_buff[1])//判断数据是哪种数据，然后将其拷贝到对应的结构体中，有些数据包需要通过上位机打开对应的输出后，才能接收到这个数据包的数据
		{
//			case 0x50:	memcpy(&stcTime,&rx_buff[2],8);break;//memcpy为编译器自带的内存拷贝函数，需引用"string.h"，将接收缓冲区的字符拷贝到数据结构体里面，从而实现数据的解析。
			case 0x51:	memcpy(jy_acc_buff,&rx_buff[2],8);break;
			case 0x52:	memcpy(jy_gyro_buff,&rx_buff[2],8);break;
			case 0x53:	memcpy(jy_angle_buff,&rx_buff[2],6);break;
			case 0x54:	memcpy(jy_mag_buff,&rx_buff[2],8);break;
//			case 0x55:	memcpy(&stcDStatus,&rx_buff[2],8);break;
//			case 0x56:	memcpy(&stcPress,&rx_buff[2],8);break;
//			case 0x57:	memcpy(&stcLonLat,&rx_buff[2],8);break;
//			case 0x58:	memcpy(&stcGPSV,&rx_buff[2],8);break;
//			case 0x59:	memcpy(&stcQ,&rx_buff[2],8);break;
            default:;
		}
		rx_idx = 0;//清空缓存区
        flag = 1;
	}
    
    HAL_UART_Receive_IT(&huart3, &rx_data, 1);
}

void JY_ProcAngleData(){
    if(flag){
        jy_x = (short)((short)jy_angle_buff[1]<<8 | jy_angle_buff[0]);
        jy_x = jy_x/32768*180;
        jy_y = (short)((short)jy_angle_buff[3]<<8 | jy_angle_buff[2]);
        jy_y = jy_y/32768*180;
        jy_z = (short)((short)jy_angle_buff[5]<<8 | jy_angle_buff[4]);
        jy_z = jy_z/32768*180;
        flag = 0;
    }
}