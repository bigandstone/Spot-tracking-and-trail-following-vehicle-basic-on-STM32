#include "my_task.h"
#include "motor_task.h"
#include "sensor_task.h"
#include "usart.h"
#include "encoder.h"
#include "key.h"
#include "jy901p.h"
#include "tripod_head_task.h"
#include "stepper_motor.h"

void MyTask_Init(){
    Led_Task_Init();
//    Sensor_Task_Init();
    Debug_Task_Init();
    Motor_Task_Init();
//    TripodHead_Task_Init();
}

osThreadId_t hled;
void Led_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "Led_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    hled = osThreadNew(Led_Task, NULL, &attr);
}

void Led_Task(void *argument){
    uint32_t time = osKernelGetTickCount();
    extern uint16_t key_tick;
    static uint16_t cnt;
    while (1)
    {
        cnt++;
        key_tick += 1;
        KeyProc();
        if(cnt >= 1000){
            HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
            cnt = 0;
        }
        time = osKernelGetTickCount();
        osDelayUntil(time + 1);//one second
    }
}

uint8_t tx_buff[100] = {0x01,0xFD,0x00,0x00,0x64,0x00,0x00,0x00,0x01,0x40,0x00,0x00,0x6B};

osThreadId_t hdebug;
void Debug_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "Debug_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    hdebug = osThreadNew(Debug_Task, NULL, &attr);
}

void Debug_Task(void *arguement){
    uint32_t time = osKernelGetTickCount();
//    HAL_UART_Transmit_IT(&huart1, (uint8_t*)tx_buff, strlen(tx_buff));
    
    while (1)
    {
        extern int motor_l_speed_target;
        extern float position;
//        sprintf(tx_buff, "%d,%d\n",encoder[1].speed,motor_l_speed_target);
//        sprintf(tx_buff, "%.2f\n",position);
//        HAL_UART_Transmit(&huart1, (uint8_t*)tx_buff, strlen(tx_buff), 5);
//        HAL_UART_Transmit_DMA(&huart1, (uint8_t *)tx_buff, 13);
//        Emm_V5_Pos_Control(1, 0, 100, 0, 320, 0, 0);
        time = osKernelGetTickCount();
        osDelayUntil(time + 10);
    }
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if(huart == &huart3) JY_UART_RxCpltCallback();
//    if(huart == &huart4) TripodHead_UART_RxCpltCallback();
}
