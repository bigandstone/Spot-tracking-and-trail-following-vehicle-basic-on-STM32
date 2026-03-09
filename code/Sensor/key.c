#include "key.h"

uint8_t key_num;
uint16_t key_tick;

void KeyProc(){
    static uint8_t state = 0;
    static uint8_t last_state = 0;
    static uint8_t key_temp = 0;
    
    state = 0;
    if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4) == GPIO_PIN_RESET) state += 1;
    if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_7) == GPIO_PIN_RESET) state += 2;
    if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_0) == GPIO_PIN_RESET) state += 4;
    if(HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_1) == GPIO_PIN_RESET) state += 8;
    
    if(last_state == 0 && state != 0)//press
    {
        key_tick = 0;
        key_temp = state;
    }
    else if(state == 0 && last_state != 0)//unpress
    {
        if(key_tick > 10) key_num = key_temp;
    }
    else if(state >= key_temp)//key change
    {
        key_temp = state;
    }
    
    last_state = state;
}

uint8_t KeyGet(uint8_t key){
    uint8_t temp = key_num;
    key_num = 0;
    temp = temp&(0x01<<(key-1));
    return temp==0?0:1;
}
