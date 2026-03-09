#ifndef __jy901p_h
#define __jy901p_h

#include "main.h"

extern float jy_x;
extern float jy_y;
extern float jy_z;

void JY_Init();
void JY_UART_RxCpltCallback();
void JY_ProcAngleData();

#endif
