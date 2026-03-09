/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RF_1_Pin GPIO_PIN_3
#define RF_1_GPIO_Port GPIOE
#define RF_2_Pin GPIO_PIN_4
#define RF_2_GPIO_Port GPIOE
#define RF_PWM_Pin GPIO_PIN_5
#define RF_PWM_GPIO_Port GPIOE
#define RB_PWM_Pin GPIO_PIN_6
#define RB_PWM_GPIO_Port GPIOE
#define RB_1_Pin GPIO_PIN_0
#define RB_1_GPIO_Port GPIOC
#define RB_2_Pin GPIO_PIN_1
#define RB_2_GPIO_Port GPIOC
#define MXC_RX_Pin GPIO_PIN_2
#define MXC_RX_GPIO_Port GPIOA
#define MXC_TX_Pin GPIO_PIN_3
#define MXC_TX_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_2
#define LED_GPIO_Port GPIOB
#define LF_1_Pin GPIO_PIN_7
#define LF_1_GPIO_Port GPIOE
#define LF_2_Pin GPIO_PIN_8
#define LF_2_GPIO_Port GPIOE
#define LB_1_Pin GPIO_PIN_10
#define LB_1_GPIO_Port GPIOE
#define LB_2_Pin GPIO_PIN_12
#define LB_2_GPIO_Port GPIOE
#define OLED_SCL_Pin GPIO_PIN_10
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin GPIO_PIN_11
#define OLED_SDA_GPIO_Port GPIOB
#define LF_PWM_Pin GPIO_PIN_14
#define LF_PWM_GPIO_Port GPIOB
#define LB_PWM_Pin GPIO_PIN_15
#define LB_PWM_GPIO_Port GPIOB
#define JY_RX_Pin GPIO_PIN_8
#define JY_RX_GPIO_Port GPIOD
#define JY_TX_Pin GPIO_PIN_9
#define JY_TX_GPIO_Port GPIOD
#define K230_RX_Pin GPIO_PIN_6
#define K230_RX_GPIO_Port GPIOC
#define K230_TX_Pin GPIO_PIN_7
#define K230_TX_GPIO_Port GPIOC
#define DEBUG_RX_Pin GPIO_PIN_9
#define DEBUG_RX_GPIO_Port GPIOA
#define DEBUG_TX_Pin GPIO_PIN_10
#define DEBUG_TX_GPIO_Port GPIOA
#define KEY_1_Pin GPIO_PIN_4
#define KEY_1_GPIO_Port GPIOD
#define KEY_2_Pin GPIO_PIN_7
#define KEY_2_GPIO_Port GPIOD
#define HD_SDA_Pin GPIO_PIN_7
#define HD_SDA_GPIO_Port GPIOB
#define HD_SCL_Pin GPIO_PIN_8
#define HD_SCL_GPIO_Port GPIOB
#define KEY_3_Pin GPIO_PIN_0
#define KEY_3_GPIO_Port GPIOE
#define KEY_4_Pin GPIO_PIN_1
#define KEY_4_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
