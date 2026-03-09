#include "encoder.h"
#include "tim.h" 
/*
htim1--LF
hitm4--LB
htim5--RF
htim3--RB
*/
Encoder_T encoder[4] = {0};

void EncoderInit(void){
    HAL_TIM_Encoder_Start(&htim1, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim5, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
    HAL_TIM_Encoder_Start(&htim4, TIM_CHANNEL_ALL);
    
    encoder[MOTOR_LF].last_cnt = htim1.Instance->CNT;
    encoder[MOTOR_LB].last_cnt = htim4.Instance->CNT;
    encoder[MOTOR_RF].last_cnt = htim5.Instance->CNT;
    encoder[MOTOR_RB].last_cnt = htim3.Instance->CNT;
}

void EncoderProcOne(MotorID motor) {
    uint16_t current_cnt = 0;
    
    switch(motor) {
        case MOTOR_LF: current_cnt = htim1.Instance->CNT; break;
        case MOTOR_LB: current_cnt = htim4.Instance->CNT; break;
        case MOTOR_RF: current_cnt = htim5.Instance->CNT; break;
        case MOTOR_RB: current_cnt = htim3.Instance->CNT; break;
        default:return;
    }
    
    int16_t delta = current_cnt - encoder[motor].last_cnt;
    
    encoder[motor].last_cnt = current_cnt;
    encoder[motor].total_cnt += delta;
    
    encoder[motor].speed = delta * 4800 * 3.1416 / 1040 / 10;
    encoder[motor].distant = encoder[motor].total_cnt * 48 * 3.1416 / (BEIPING * PPR * JIANSUBI);
}

void EncoderProc(){
    for(uint8_t i = 0 ; i < 4 ;i++){
        EncoderProcOne(i);
    }
}
