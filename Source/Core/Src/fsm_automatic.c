/*
 * fsm_automatic.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "fsm_automatic.h"

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

void allOn(){
	LED_RED_ON();
	LED_YELLOW_ON();
	LED_GREEN_ON();

	RED_ON();
	YELLOW_ON();
	GREEN_ON();

	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);

	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, RESET);
	HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, RESET);
	HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, RESET);
	HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, RESET);
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, RESET);
	HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, RESET);
	HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, RESET);
}

void fsm_automatic_run(){
	switch(status){
	case INIT:
		allOn();
		status = AUTO_RED;
		setTimer1(500);
		counter = 5;
		break;
	case AUTO_RED:
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();
		if(timer1_flag == 1){
			status = AUTO_GREEN;
			counter = 3;
			setTimer1(300);
		}
		break;
	case AUTO_GREEN:
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();
		display7SEG(counter);
		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			counter = 2;
			setTimer1(200);
		}
		break;
	case AUTO_YELLOW:
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();
		display7SEG(counter);
		if(timer1_flag == 1){
			status = AUTO_RED;
			counter = 5;
			setTimer1(500);
		}
		break;
	default:
		status = INIT;
		break;
	}
	//counter--;
}

