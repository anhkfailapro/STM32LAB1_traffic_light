/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define LED_RED_ON()   HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET)   // active-high
#define LED_RED_OFF()  HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET)

#define LED_YELLOW_ON()   HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET)   // active-low
#define LED_YELLOW_OFF()  HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET)

#define LED_GREEN_ON()   HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET) // active-low
#define LED_GREEN_OFF()  HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET)

#define RED_ON()   HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, RESET)   // active-high
#define RED_OFF()  HAL_GPIO_WritePin(RED_GPIO_Port, RED_Pin, SET)

#define YELLOW_ON()   HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, SET)   // active-low
#define YELLOW_OFF()  HAL_GPIO_WritePin(YELLOW_GPIO_Port, YELLOW_Pin, RESET)

#define GREEN_ON()   HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, SET) // active-low
#define GREEN_OFF()  HAL_GPIO_WritePin(GREEN_GPIO_Port, GREEN_Pin, RESET)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
const uint8_t SEG_TABLE[10] = {
  0x3F, // 0 -> 0b00111111
  0x06, // 1 -> 0b00000110
  0x5B, // 2 -> 0b01011011
  0x4F, // 3 -> 0b01001111
  0x66, // 4 -> 0b01100110
  0x6D, // 5 -> 0b01101101
  0x7D, // 6 -> 0b01111101
  0x07, // 7 -> 0b00000111
  0x7F, // 8 -> 0b01111111
  0x6F  // 9 -> 0b01101111
};

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int num){
	if(num>9) return;
	uint8_t pattern = SEG_TABLE[num];
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, !(pattern & 0x01) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, !(pattern & 0x02) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, !(pattern & 0x04) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, !(pattern & 0x08) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, !(pattern & 0x10) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, !(pattern & 0x20) ? SET : RESET);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, !(pattern & 0x40) ? SET : RESET);
}
void display7SEG2(int num){
	if(num > 9) return;
	uint8_t pattern = SEG_TABLE[num];
	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, !(pattern & 0x01) ? SET : RESET);
	HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, !(pattern & 0x02) ? SET : RESET);
	HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, !(pattern & 0x04) ? SET : RESET);
	HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, !(pattern & 0x08) ? SET : RESET);
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, !(pattern & 0x10) ? SET : RESET);
	HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, !(pattern & 0x20) ? SET : RESET);
	HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, !(pattern & 0x40) ? SET : RESET);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int timecounter = 0;
	int counter = 0;
	int state2 = 2;
	int state = 0; // 0: red, 1: yellow, 2: green.
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  LED_RED_OFF();
	  LED_YELLOW_OFF();
	  LED_GREEN_OFF();
	  RED_OFF();
	  YELLOW_OFF();
	  GREEN_OFF();

	  if (state == 0){
		  LED_RED_ON();
		  display7SEG(5-timecounter);
		  	  if(++timecounter >= 5){
		  		  timecounter = 0;
		  		  state = 2;
		  	  	}
	  } else if (state == 1){
		  LED_YELLOW_ON();
		  display7SEG(2-timecounter);
		if(++timecounter >= 2){
					timecounter = 0;
					state = 0;
				}
	  } else if(state == 2){
		  LED_GREEN_ON();
		  display7SEG(3-timecounter);
		  if(++timecounter >= 3){
			  timecounter = 0;
		  	  state = 1;
		  	  	}
	  }

	  if (state2 == 0){
	  		  RED_ON();
	  		  display7SEG2(5-counter);
	  		  	  if(++counter >= 5){
	  		  		  counter = 0;
	  		  		  state2 = 2;
	  		  	  	}
	  	  } else if (state2 == 1){
	  		  YELLOW_ON();
	  		  display7SEG2(2-counter);
	  		  if(++counter >= 2){
	  					counter = 0;
	  					state2 = 0;
	  				}
	  	  } else if(state2 == 2){
	  		  GREEN_ON();
	  		  display7SEG2(3-counter);
	  		  if(++counter >= 3){
	  			  counter = 0;
	  		  	  state2 = 1;
	  		  	  	}
	  	  }

	  HAL_Delay(1000);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|RED_Pin
                          |YELLOW_Pin|GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin|A_Pin
                          |B_Pin|C_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin LED_YELLOW_Pin LED_GREEN_Pin RED_Pin
                           YELLOW_Pin GREEN_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|LED_YELLOW_Pin|LED_GREEN_Pin|RED_Pin
                          |YELLOW_Pin|GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG_A_Pin SEG_B_Pin SEG_C_Pin D_Pin
                           E_Pin F_Pin G_Pin SEG_D_Pin
                           SEG_E_Pin SEG_F_Pin SEG_G_Pin A_Pin
                           B_Pin C_Pin */
  GPIO_InitStruct.Pin = SEG_A_Pin|SEG_B_Pin|SEG_C_Pin|D_Pin
                          |E_Pin|F_Pin|G_Pin|SEG_D_Pin
                          |SEG_E_Pin|SEG_F_Pin|SEG_G_Pin|A_Pin
                          |B_Pin|C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
