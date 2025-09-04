/*
 * fsm_manual.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();
		SEG_Off();

		if(timer1_flag == 1){
			status = AUTO_RED;
			setTimer1(500);
		}
		if(isButton1Pressed() == 1){
			status = MAN_GREEN;
			setTimer1(1000);
		}
		break;
	case MAN_GREEN:
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();
		SEG_Off();

		if(timer1_flag == 1){
			status = AUTO_GREEN;
			setTimer1(300);
		}
		if(isButton1Pressed() == 1){
			status = MAN_YELLOW;
			setTimer1(1000);
		}
		break;
	case MAN_YELLOW:
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();
		SEG_Off();

		if(timer1_flag == 1){
			status = AUTO_YELLOW;
			setTimer1(200);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(1000);
		}
		break;
	default: break;
	}
}
