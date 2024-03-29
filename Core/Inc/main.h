/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
#define limit_max_Pin GPIO_PIN_0
#define limit_max_GPIO_Port GPIOA
#define limit_min_Pin GPIO_PIN_1
#define limit_min_GPIO_Port GPIOA
#define W_led_Pin GPIO_PIN_2
#define W_led_GPIO_Port GPIOA
#define M__Pin GPIO_PIN_3
#define M__GPIO_Port GPIOA
#define M_A4_Pin GPIO_PIN_4
#define M_A4_GPIO_Port GPIOA
#define USR_LED_Pin GPIO_PIN_5
#define USR_LED_GPIO_Port GPIOA
#define RST_Pin GPIO_PIN_8
#define RST_GPIO_Port GPIOA
#define CC_Pin GPIO_PIN_9
#define CC_GPIO_Port GPIOA
#define Read_mode_pb_Pin GPIO_PIN_10
#define Read_mode_pb_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
