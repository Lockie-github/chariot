/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"
#include <stdlib.h>
#include "SEGGER_RTT.h"
#include "float.h"
#include "charoit_abstract.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* 当前时刻总计数值 */
__IO int32_t Capture_Count = 0;
/* 上一时刻总计数值 */
__IO int32_t Last_Count = 0;
/* 电机转轴转速 */
__IO float Shaft_Speed = 0;
///< 角速度
// __IO float angular_velocity = 0.0f;
// __IO float linear_velocity = 0.0f;
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
	__HAL_RCC_SYSCFG_CLK_ENABLE();

  HAL_InitTick(5);
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  // htim1.Init.Period = 32768;
  motor_init();
  MX_TIM1_Init();
  MX_TIM3_Init();

  HAL_TIM_OC_Start(&htim1,TIM_CHANNEL_1);
  HAL_TIM_OC_Start(&htim1,TIM_CHANNEL_2);
  // HAL_TIM_Base_Start_IT(&htim3);
  HAL_TIM_Encoder_Start_IT(&htim3, TIM_CHANNEL_ALL);



  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,0);
    __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,32768);
    // Motor_Direction = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3);
    // HAL_Delay(100);
    // myprintf("Motor_Direction : %0.2f\n",Shaft_Speed);

    // HAL_Delay(50);
    // myprintf("tim1：%d\n",__HAL_TIM_GET_COUNTER(&htim1));

    // myprintf("tim3：%d\n",__HAL_TIM_GET_COUNTER(&htim3));
    // myprintf("\n");
 
    //  myprintf("7");
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // HAL_Delay(2000);
//     #if 0
//       // HAL_TIM_Base_Stop(&htim1);
// // //  HAL_Delay(2000);
// //   // 修改周期值
// //   htim1.Init.Period = 32768;

// //   // 更新自动重装载寄存器
// //   HAL_TIM_Base_Init(&htim1);

// //   // 重新启动定时器
// //   HAL_TIM_Base_Start(&htim1);

// //     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,0);
// //     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,32768);
// //       HAL_Delay(200);
// //             HAL_TIM_Base_Stop(&htim1);
// //  HAL_Delay(2000);
//   // 修改周期值
//   // htim1.Init.Period = 65535;

//   // // 更新自动重装载寄存器
//   // HAL_TIM_Base_Init(&htim1);

//   // // 重新启动定时器
//   // HAL_TIM_Base_Start(&htim1);
//     #endif

//     change_period(&htim1,32768);
//     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1,0);
//     __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2,32768);
//     HAL_Delay(2000);
//     while (1);
    
  }
  /* USER CODE END 3 */
}
void HAL_SYSTICK_Callback(void)
{
  static uint16_t i = 0;
  i++;
  if(i == GET_SPEED_INTERVAL)/* 100ms计算一次 */
  {
    /* 电机旋转方向 = 计数器计数方向 */
    Motor_Direction = __HAL_TIM_IS_TIM_COUNTING_DOWN(&htim3);
    
    /* 当前时刻总计数值 = 计数器值 + 计数溢出次数 * ENCODER_TIM_PERIOD  */
    Capture_Count =__HAL_TIM_GET_COUNTER(&htim3) + (Encoder_Overflow_Count * 65535);
    
    /*角速度 = 单位时间内的计数值/（单圈脉冲数*单位时间）*/
    motor.angular_velocity = (float)(Capture_Count - Last_Count)/(ENCODER_RESOLUTION*MULTIPLICATION_FACTOR*GET_SPEED_INTERVAL/1000);
    
    /*线速度 = 角速度*轮子的直径*PI/减速比(m/s)*/
    motor.linear_velocity = motor.angular_velocity * WHEEL_D * PI/REDCUTION_RATIO;

    // Shaft_Speed = (float)(Capture_Count - Last_Count) / 13*4 * 10 ;

    // myprintf("电机方向：%d\n", Motor_Direction);
    // myprintf("jshu：%d\n", Capture_Count);
    // myprintf("last:%d\n", Last_Count);
    myprintf("angular_velocity:%f\n", motor.angular_velocity);
    myprintf("linear_velocity:%f\n", motor.linear_velocity);


    
    /* 记录当前总计数值，供下一时刻计算使用 */
    Last_Count = Capture_Count;
    i = 0;
  }
}
/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

