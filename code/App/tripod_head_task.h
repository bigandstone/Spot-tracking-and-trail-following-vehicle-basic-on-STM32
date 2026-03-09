#ifndef __tripod_head_task_h
#define __tripod_head_task_h

#include "main.h"
#include "cmsis_os.h"

void TripodHead_Task_Init();
void TripodHead_Task(void *arguement);

void TripodHead_UART_RxCpltCallback();
void Emm_V5_Pos_Control_xy(uint8_t dir_x,uint8_t dir_y,uint16_t speed,uint16_t vel_x,uint16_t vel_y);
#endif