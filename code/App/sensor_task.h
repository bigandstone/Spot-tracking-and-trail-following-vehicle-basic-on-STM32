#ifndef __sensor_task_h
#define __sensor_task_h

#include "main.h"
#include "cmsis_os.h"

void Sensor_Task_Init();
void Sensor_Task(void *arguement);
void Sensor_GetPosition();

#endif
