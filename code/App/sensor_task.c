#include "sensor_task.h"
#include "jy901p.h"
#include "hardware_iic.h"
#include "gw_grayscale_sensor.h"
#include "encoder.h"
#include "K230.h"

uint8_t digtal;
uint8_t hd_sensor[8];
int hd_sensor_weight[8] = {-42, -30, -18, -6, 6, 18, 30, 42};
float position,prev_position;

osThreadId_t hsensor;
void Sensor_Task_Init(){
    const osThreadAttr_t attr = {
        .name = "Sensor_Task",
        .stack_size = 128 * 8,
        .priority = (osPriority_t)osPriorityNormal,
    };
    hsensor = osThreadNew(Sensor_Task, NULL, &attr);
}

void Sensor_Task(void *arguement){
    uint32_t time = osKernelGetTickCount();
    //init jy901p
    JY_Init();

    while (1)
    {
        Sensor_GetPosition();
        
        EncoderProc();
        
//        JY_ProcAngleData();
        
        time = osKernelGetTickCount();
        osDelayUntil(time + 10);
    }
}

void Sensor_GetPosition(){
    digtal = IIC_Get_Digtal();
    for(uint8_t i = 0;i < 8;i++) hd_sensor[i] = (digtal&(0x01<<i)) == 0? 1:0;
    
    int32_t weighted_sum = 0;
    uint8_t active_count = 0;
    
    for (uint8_t i = 0; i < 8; i++) {
        if (hd_sensor[i] > 0) {
            weighted_sum += hd_sensor_weight[i];
            active_count++;
        }
    }
    if(active_count) position = weighted_sum / active_count;
    else position = prev_position;
    
    if(hd_sensor[0] && !hd_sensor[1]) {
        position -= 10;
    }
    else if(hd_sensor[7] && !hd_sensor[6]) {
        position += 10;
    }
    if(fabs(position) < 6.1f) position = 0;
    
    prev_position = position;
}
