#include "tb6612.h"

void MotorInit(){
    MotorStop();
    
    HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim9,TIM_CHANNEL_2);
    HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);
}

void MotorSet(MotorID motor,int speed){
    switch (motor)
    {
    	case MOTOR_LF:
            if(speed > 0){
                HAL_GPIO_WritePin(LB_1_GPIO_Port,LB_1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LB_2_GPIO_Port,LB_2_Pin,GPIO_PIN_SET);
                htim12.Instance->CCR2 = speed < 100? speed:99;
    		}else{
                HAL_GPIO_WritePin(LB_1_GPIO_Port,LB_1_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(LB_2_GPIO_Port,LB_2_Pin,GPIO_PIN_RESET);
                htim12.Instance->CCR2 = speed > -100? -speed:99;
            }
    		break;
    	case MOTOR_LB:
            if(speed > 0){
                HAL_GPIO_WritePin(LF_1_GPIO_Port,LF_1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LF_2_GPIO_Port,LF_2_Pin,GPIO_PIN_SET);
                htim12.Instance->CCR1 = speed < 100? speed:99;
    		}else{
                HAL_GPIO_WritePin(LF_1_GPIO_Port,LF_1_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(LF_2_GPIO_Port,LF_2_Pin,GPIO_PIN_RESET);
                htim12.Instance->CCR1 = speed > -100? -speed:99;
            }
            break;
    	case MOTOR_RF:
            if(speed > 0){
                HAL_GPIO_WritePin(RF_1_GPIO_Port,RF_1_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(RF_2_GPIO_Port,RF_2_Pin,GPIO_PIN_RESET);
                htim9.Instance->CCR1 = speed < 100? speed:99;
    		}else{
                HAL_GPIO_WritePin(RF_1_GPIO_Port,RF_1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(RF_2_GPIO_Port,RF_2_Pin,GPIO_PIN_SET);
                htim9.Instance->CCR1 = speed > -100? -speed:99;
            }
    		break;
    	case MOTOR_RB:
            if(speed > 0){
                HAL_GPIO_WritePin(RB_1_GPIO_Port,RB_1_Pin,GPIO_PIN_RESET);
                HAL_GPIO_WritePin(RB_2_GPIO_Port,RB_2_Pin,GPIO_PIN_SET);
                htim9.Instance->CCR2 = speed < 100? speed:99;
    		}else{
                HAL_GPIO_WritePin(RB_1_GPIO_Port,RB_1_Pin,GPIO_PIN_SET);
                HAL_GPIO_WritePin(RB_2_GPIO_Port,RB_2_Pin,GPIO_PIN_RESET);
                htim9.Instance->CCR2 = speed > -100? -speed:99;
            }
    		break;
    	default:return;
    		break;
    }
}
void MotorStop(void){
    HAL_GPIO_WritePin(LF_2_GPIO_Port,LF_2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LF_1_GPIO_Port,LF_1_Pin,GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(LB_2_GPIO_Port,LB_2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(LB_1_GPIO_Port,LB_1_Pin,GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(RF_2_GPIO_Port,RF_2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(RF_1_GPIO_Port,RF_1_Pin,GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(RB_2_GPIO_Port,RB_2_Pin,GPIO_PIN_SET);
    HAL_GPIO_WritePin(RB_1_GPIO_Port,RB_1_Pin,GPIO_PIN_SET);
}