#ifndef __my_task_h
#define __my_task_h

#include "main.h"
#include "cmsis_os.h"

void MyTask_Init();

void Led_Task_Init();
void Led_Task(void *argument);

void Debug_Task_Init();
void Debug_Task(void *arguement);

#endif

/*
osThreadId_t hXX;

void XX_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "XX_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    hXX = osThreadNew(XX_Task, NULL, &attr);
}

void XX_Task(void *arguement){
    uint32_t time = osKernelGetTickCount();

    while (1)
    {
        
        time = osKernelGetTickCount();
        osDelayUntil(time + 5);
    }
}
*/