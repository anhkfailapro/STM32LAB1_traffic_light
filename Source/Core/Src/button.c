/*
 * button.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#include "button.h"

int button1_flag = 0; 	//manual
int button2_flag = 0;	//down
int button3_flag = 0;	//up
int button4_flag = 0;	//walk

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
int timeForKey1Press = 200;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	} return 0;
}

void subKey1Process(){
	button1_flag = 1;
	//TODO
}

void getKey1Input(){
	KeyReg0 = KeyReg1;
	KeyReg1 = KeyReg2;
	KeyReg2 = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	if((KeyReg0 == KeyReg1) && (KeyReg1 == KeyReg2)){
		if(KeyReg3 != KeyReg2){
			KeyReg3 = KeyReg2;
			if(KeyReg2 == PRESSED_STATE){
				timeForKey1Press = 200;
				subKey1Process();
			}
		} else {
			timeForKey1Press--;
			if(timeForKey1Press == 0){
				//TO DO
				if(KeyReg2 == PRESSED_STATE){
				subKey1Process();
				}
				timeForKey1Press = 200;
			}
		}
	}
}
