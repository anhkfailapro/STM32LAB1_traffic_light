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



//Code for manual button
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

//Code for down button
int Key2Reg0 = NORMAL_STATE;
int Key2Reg1 = NORMAL_STATE;
int Key2Reg2 = NORMAL_STATE;
int Key2Reg3 = NORMAL_STATE;
int timeForKey2Press = 200;

int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	} return 0;
}

void subKey2Process(){
	button2_flag = 1;
	//TODO
}

void getKey2Input(){
	Key2Reg0 = Key2Reg1;
	Key2Reg1 = Key2Reg2;
	Key2Reg2 = HAL_GPIO_ReadPin(Down_GPIO_Port, Down_Pin);
	if((Key2Reg0 == Key2Reg1) && (Key2Reg1 == Key2Reg2)){
		if(Key2Reg3 != Key2Reg2){
			Key2Reg3 = Key2Reg2;
			if(Key2Reg2 == PRESSED_STATE){
				timeForKey2Press = 200;
				subKey2Process();
			}
		} else {
			timeForKey2Press--;
			if(timeForKey2Press == 0){
				//TO DO
				if(Key2Reg2 == PRESSED_STATE){
				subKey2Process();
				}
				timeForKey2Press = 200;
			}
		}
	}
}

//Code for Up button
int Key3Reg0 = NORMAL_STATE;
int Key3Reg1 = NORMAL_STATE;
int Key3Reg2 = NORMAL_STATE;
int Key3Reg3 = NORMAL_STATE;
int timeForKey3Press = 200;

int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	} return 0;
}

void subKey3Process(){
	button3_flag = 1;
	//TODO
}

void getKey3Input(){
	Key3Reg0 = Key3Reg1;
	Key3Reg1 = Key3Reg2;
	Key3Reg2 = HAL_GPIO_ReadPin(Up_GPIO_Port, Up_Pin);
	if((Key3Reg0 == Key3Reg1) && (Key3Reg1 == Key3Reg2)){
		if(Key3Reg3 != Key3Reg2){
			Key3Reg3 = Key3Reg2;
			if(Key3Reg2 == PRESSED_STATE){
				timeForKey3Press = 200;
				subKey3Process();
			}
		} else {
			timeForKey3Press--;
			if(timeForKey3Press == 0){
				//TO DO
				if(Key3Reg2 == PRESSED_STATE){
				subKey3Process();
				}
				timeForKey3Press = 200;
			}
		}
	}
}



//Code for walk button
//Code for Up button
int Key4Reg0 = NORMAL_STATE;
int Key4Reg1 = NORMAL_STATE;
int Key4Reg2 = NORMAL_STATE;
int Key4Reg3 = NORMAL_STATE;
int timeForKey4Press = 200;

int isButton4Pressed(){
	if(button4_flag == 1){
		button4_flag = 0;
		return 1;
	} return 0;
}

void subKey4Process(){
	button4_flag = 1;
	//TODO
}

void getKey4Input(){
	Key4Reg0 = Key4Reg1;
	Key4Reg1 = Key4Reg2;
	Key4Reg2 = HAL_GPIO_ReadPin(Walk_GPIO_Port, Walk_Pin);
	if((Key4Reg0 == Key4Reg1) && (Key4Reg1 == Key4Reg2)){
		if(Key4Reg3 != Key4Reg2){
			Key4Reg3 = Key4Reg2;
			if(Key4Reg2 == PRESSED_STATE){
				timeForKey4Press = 200;
				subKey4Process();
			}
		} else {
			timeForKey4Press--;
			if(timeForKey4Press == 0){
				//TO DO
				if(Key4Reg2 == PRESSED_STATE){
				subKey4Process();
				}
				timeForKey4Press = 200;
			}
		}
	}
}
