#include "k230.h"
#include "usart.h"

uint8_t rx_data;
uint8_t rx_idx;
uint8_t rx_buff[100];

int data_a[2];//red pot
int data_b[2];//green pot
static int data_a_last[2];//red pot
static int data_b_last[2];//green pot

void K230_Init(){
    HAL_UARTEx_ReceiveToIdle_IT(&huart6, rx_buff, sizeof(rx_buff));
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
	if(huart == &huart6){
        if(sscanf((char*)rx_buff,"x1:%d,y1:%d,x2:%d,y2:%d",&data_a[0],&data_a[1],&data_b[0] ,&data_b[1]) == 4){
            
        }
        memset(rx_buff,0,sizeof(rx_buff));
    }
    
    HAL_UARTEx_ReceiveToIdle_IT(&huart6, rx_buff, sizeof(rx_buff));
}
