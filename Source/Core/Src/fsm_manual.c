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

		RED_OFF();
		YELLOW_OFF();
		GREEN_ON();

		SEG_Off();

		if(timer1_flag == 1){
			status = S3;
			setTimer1(200);
		}
		if(isButton1Pressed() == 1){
			status = MAN_GREEN;
			setTimer1(200);
		}
		break;
	case MAN_GREEN:
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		SEG_Off();

		if(timer1_flag == 1){
			status = S0;
			setTimer1(300);
		}
		if(isButton1Pressed() == 1){
			status = MAN_YELLOW;
			setTimer1(200);
		}
		break;
	case MAN_YELLOW:
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		SEG_Off();

		if(timer1_flag == 1){
			status = S1;
			setTimer1(200);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(200);
		}
		break;
	case PED_RED:
		break;
	case PED_YELLOW:
		break;
	case PED_GREEN:
		break;
	default: break;
	}
}
