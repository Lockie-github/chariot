/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define TIM_CH1_Pin GPIO_PIN_8
#define TIM_CH1_GPIO_Port GPIOA
#define TIM_CH2_Pin GPIO_PIN_9
#define TIM_CH2_GPIO_Port GPIOA
#define TIM3_CH1_ENCODER_Pin GPIO_PIN_4
#define TIM3_CH1_ENCODER_GPIO_Port GPIOB
#define TIM3_CH2_ENCODER_Pin GPIO_PIN_5
#define TIM3_CH2_ENCODER_GPIO_Port GPIOB


/* USER CODE BEGIN Private defines */
///<获取速度的时间间隔（ms）
#define GET_SPEED_INTERVAL 100

#define PI 3.1415

///<轮子的半径（m）
#define WHEEL_D 0.065

///<编码器分辨率
#define ENCODER_RESOLUTION 13

///<减速比
#define REDCUTION_RATIO 78

///<编码器倍频因子
#define MULTIPLICATION_FACTOR 4

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
