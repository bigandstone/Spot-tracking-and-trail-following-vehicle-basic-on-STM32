#include "servo.h"

void OutInit(){
//    DL_TimerG_setCaptureCompareValue(SERVO_INST,1500,GPIO_SERVO_C0_IDX);
}
void OutServoSetAngle(float angle){
    if(angle > ANGLE_MAX) angle = ANGLE_MAX;
    if(angle < ANGLE_MIN) angle = ANGLE_MIN;
    uint16_t pulse = 500 + (2500 - 500) * angle / 180;
//    DL_TimerG_setCaptureCompareValue(SERVO_INST,pulse,GPIO_SERVO_C0_IDX);
}
