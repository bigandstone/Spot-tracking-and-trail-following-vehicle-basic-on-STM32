#ifndef __pid_h
#define __pid_h

#include "main.h"

typedef struct {
    float Kp, Ki, Kd;
    float output_max, output_min;
    
    float integral;
    float integral_max, integral_min;
    float prev_error;
    
    float prev_prev_error;
    float prev_output;
} PIDController;

void PID_Init(PIDController *pid, float Kp, float Ki, float Kd, float min, float max);
float PID_Positional(PIDController *pid, float setpoint, float input);
float PID_Incremental(PIDController *pid, float setpoint, float input);

#endif