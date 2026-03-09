#include "motor_task.h"
#include "tb6612.h"
#include "pid.h"
#include "key.h"

extern float position;

float pid_out_speed;
float pid_out_dir;

int motor_l_speed_target = 0;
int motor_r_speed_target = 0;

PIDController speed_l_pid = {
    .Kp = 3.0f,
    .Ki = 0.25f,
    .Kd = 0.5f,
    .output_max = 100.0f,
    .output_min = -100.0f,
    .integral = 0.0f,
    .integral_max = 1000.0f,
    .integral_min = -1000.0f,
    .prev_error = 0.0f,
    .prev_prev_error = 0.0f,
    .prev_output = 0.0f
};

PIDController speed_r_pid = {
    .Kp = 3.0f,
    .Ki = 0.25f,
    .Kd = 0.5f,
    .output_max = 100.0f,
    .output_min = -100.0f,
    .integral = 0.0f,
    .integral_max = 1000.0f,
    .integral_min = -1000.0f,
    .prev_error = 0.0f,
    .prev_prev_error = 0.0f,
    .prev_output = 0.0f
};

PIDController dir_pid = {
    .Kp = 30.0f,
    .Ki = 0.0f,
    .Kd = 10.0f,
    .output_max = 50.0f,
    .output_min = -50.0f,
    .integral = 0.0f,
    .integral_max = 1000.0f,
    .integral_min = -1000.0f,
    .prev_error = 0.0f,
    .prev_prev_error = 0.0f,
    .prev_output = 0.0f
};


osThreadId_t hmotor;
void Motor_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "Motor_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    hmotor = osThreadNew(Motor_Task, NULL, &attr);
}

void Motor_Task(void *arguement){
    uint32_t time = osKernelGetTickCount();
    MotorInit();
//    EncoderInit();
    MotorSet(MOTOR_L, 0);
    MotorSet(MOTOR_R, 0);
    
    while (1)
    {
        //get key to set speed
//        if(KeyGet(1) == 1){
//            motor_l_speed_target += 15;
//            motor_r_speed_target += 15;
//            if(motor_l_speed_target >= 60||motor_r_speed_target >= 60){
//                motor_l_speed_target = 0;
//                motor_r_speed_target = 0;
//            }
//        }
//        
//        pid_out_dir = PID_Positional(&dir_pid, 0, position/42);
//        
//        //pid speed
//        pid_out_speed = PID_Positional(&speed_l_pid, motor_l_speed_target - pid_out_dir, encoder[1].speed);
//        MotorSet(MOTOR_L, pid_out_speed *2/3);//A
//        pid_out_speed = PID_Positional(&speed_r_pid, motor_r_speed_target + pid_out_dir, encoder[2].speed);
//        MotorSet(MOTOR_R, pid_out_speed *2/3);
        
        time = osKernelGetTickCount();
        osDelayUntil(time + 10);
    }
}