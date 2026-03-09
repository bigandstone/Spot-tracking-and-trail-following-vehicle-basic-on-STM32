#include "main.h"
#include "tim.h"
//MG310
#define BEIPING     4
#define PPR         13
#define JIANSUBI    20

typedef enum {
    MOTOR_LF = 0,
    MOTOR_LB = 1,
    MOTOR_L = 1,
    MOTOR_R = 2,    
    MOTOR_RF = 2,    
    MOTOR_RB = 3
} MotorID;


typedef struct {
    int32_t total_cnt;     
    uint16_t last_cnt;    
    int32_t speed;
    int distant;
} Encoder_T;

extern Encoder_T encoder[4];

void EncoderInit();
void EncoderProc();
void EncoderProcOne(MotorID motor);