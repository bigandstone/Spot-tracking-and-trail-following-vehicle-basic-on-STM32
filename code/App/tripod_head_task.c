#include "tripod_head_task.h"
#include "usart.h"
#include "stepper_motor.h"
#include "k230.h"
#include "pid.h"

static uint8_t rx_buff[255];
 uint8_t dir_x, dir_y;
 float vel_x, vel_y;
 uint16_t speed_x = 40;
 uint16_t speed_y = 40;

PIDController pid_stmotory = {
    .Kp = 0.15,
    .Ki = 0.0,
    .Kd = 0.05,
    .output_max = 100.0,
    .output_min = -100.0,
    .integral = 0.0f,
    .integral_max = 0.0f,
    .integral_min = 0.0f,
    .prev_error = 0.0f,
    .prev_prev_error = 0.0f,
    .prev_output = 0.0f
};

PIDController pid_stmotorx = {
    .Kp = 0.0,
    .Ki = 0.0,
    .Kd = 0.0,
    .output_max = 100.0,
    .output_min = -100.0,
    .integral = 0.0f,
    .integral_max = 0.0f,
    .integral_min = 0.0f,
    .prev_error = 0.0f,
    .prev_prev_error = 0.0f,
    .prev_output = 0.0f
};

osThreadId_t htripod_head;

void TripodHead_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "TripodHead_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    htripod_head = osThreadNew(TripodHead_Task, NULL, &attr);
}

void TripodHead_Task(void *arguement){
    uint32_t time = osKernelGetTickCount();
    
    //stepper motor init
//    __HAL_UART_CLEAR_IDLEFLAG(&huart4); 											
//	__HAL_UART_ENABLE_IT(&huart4, UART_IT_IDLE); 
//    HAL_UART_Receive_DMA(&huart4, rx_buff, sizeof(rx_buff));
    
    //camera init,actually is maxicam but is also rxtx to receive data
    K230_Init();
    
    while (1)
    {
        if(data_a[1] != -1 && data_b[1] != -1){
            vel_y = PID_Positional(&pid_stmotory, data_a[1], data_b[1]);
            vel_x = PID_Positional(&pid_stmotorx, data_a[0], data_b[0]);
        }
        else{
            vel_y = 0;
            vel_x = 0;
        }
        
        if(vel_y > 0){
            dir_y = 0;
        }else{
            dir_y = 1;
            vel_y = -vel_y;
        }
        
        if(vel_x > 0){
            dir_x = 1;
        }else{
            dir_x = 0;
            vel_x = -vel_x;
        }

        Emm_V5_Pos_Control(1, dir_y, speed_y, 0, vel_y, 0, 0);

        time = osKernelGetTickCount();
        osDelayUntil(time + 10);
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
    if(huart == &huart4){
        Emm_V5_Pos_Control(2, dir_x, speed_x, 0, vel_x, 0, 0);
    }
}
