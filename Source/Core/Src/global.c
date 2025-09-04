/*
 * global.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "global.h"

int status = 0;
int counter = 0;
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

void SEG_Off(){
	HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
	HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
	HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
	HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
	HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
	HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
	HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);

	HAL_GPIO_WritePin(A_GPIO_Port, A_Pin, SET);
	HAL_GPIO_WritePin(B_GPIO_Port, B_Pin, SET);
	HAL_GPIO_WritePin(C_GPIO_Port, C_Pin, SET);
	HAL_GPIO_WritePin(D_GPIO_Port, D_Pin, SET);
	HAL_GPIO_WritePin(E_GPIO_Port, E_Pin, SET);
	HAL_GPIO_WritePin(F_GPIO_Port, F_Pin, SET);
	HAL_GPIO_WritePin(G_GPIO_Port, G_Pin, SET);
}
