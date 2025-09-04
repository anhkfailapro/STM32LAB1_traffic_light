/*
 * global.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"

#define INIT 1
#define S0 2 	//NS_Green, EW_Red
#define S1 3 	//NS_Yellow, EW_Red
#define S2 4 	//NS_Red, EW_Green
#define S3 5	//NS_Red, EW_Yellow

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14

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

extern int status;
extern int counter;
extern const uint8_t SEG_TABLE[10];

void allOn();
void display7SEG(int num);
void display7SEG2(int num);
void SEG_Off();

#endif /* INC_GLOBAL_H_ */
