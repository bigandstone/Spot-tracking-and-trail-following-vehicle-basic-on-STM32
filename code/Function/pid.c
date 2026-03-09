#include "pid.h"

void PID_Init(PIDController *pid, float Kp, float Ki, float Kd, float min, float max){
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->output_min = min;
    pid->output_max = max;
}

float PID_Positional(PIDController *pid, float setpoint, float input) {
    float error = setpoint - input;
    
    float P = pid->Kp * error;
    
    pid->integral += error;
    if (pid->integral > pid->integral_max) pid->integral = pid->integral_max;
    if (pid->integral < pid->integral_min) pid->integral = pid->integral_min;
    float I = pid->Ki * pid->integral;
    
    float D = pid->Kd * (error - pid->prev_error);
    pid->prev_error = error;
    
    float output = P + I + D;
    
    if (output > pid->output_max) output = pid->output_max;
    if (output < pid->output_min) output = pid->output_min;
    
    return output;
}

float PID_Incremental(PIDController *pid, float setpoint, float input) {
    float error = setpoint - input;
    float delta_error = error - pid->prev_error;
        
    float P = pid->Kp * delta_error;
    float I = pid->Ki * error;
    float D = pid->Kd * (error - 2.0f * pid->prev_error + pid->prev_prev_error);
        
    float delta_output = P + I + D;
        
    pid->prev_prev_error = pid->prev_error;
    pid->prev_error = error;
        
    float output = pid->prev_output + delta_output;
    pid->prev_output = output;
    
    if (output > pid->output_max) output = pid->output_max;
    if (output < pid->output_min) output = pid->output_min;
    
    return output;
}