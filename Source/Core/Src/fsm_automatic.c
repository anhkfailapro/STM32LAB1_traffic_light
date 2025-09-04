/*
 * fsm_automatic.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "fsm_automatic.h"

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
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(1000);
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
		if(isButton1Pressed() == 1){
			status = MAN_GREEN;
			setTimer1(1000);
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
		if(isButton1Pressed() == 1){
			status = MAN_YELLOW;
			setTimer1(1000);
		}
		break;
	default:
		break;
	}
	//counter--;
}

