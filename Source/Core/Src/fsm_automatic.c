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
		status = S0;
		setTimer1(300);
		counter = 3;
		break;
	case S0:
		LED_RED_OFF();
		LED_YELLOW_OFF();
		LED_GREEN_ON();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		if(timer1_flag == 1){
			status = S1;
			counter = 2;
			setTimer1(200);
		}
		if(isButton1Pressed() == 1){
			status = MAN_GREEN;
			setTimer1(200);
		}
		break;
	case S1:
		LED_RED_OFF();
		LED_YELLOW_ON();
		LED_GREEN_OFF();

		RED_ON();
		YELLOW_OFF();
		GREEN_OFF();

		display7SEG(counter);
		if(timer1_flag == 1){
			status = S2;
			counter = 3;
			setTimer1(300);
		}
		if(isButton1Pressed() == 1){
			status = MAN_YELLOW;
			setTimer1(200);
		}
		break;
	case S2:
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_OFF();
		GREEN_ON();

		display7SEG(counter);
		if(timer1_flag == 1){
			status = S3;
			counter = 2;
			setTimer1(200);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(200);
		}
		break;
	case S3:
		LED_RED_ON();
		LED_YELLOW_OFF();
		LED_GREEN_OFF();

		RED_OFF();
		YELLOW_ON();
		GREEN_OFF();

		display7SEG(counter);
		if(timer1_flag == 1){
			status = S0;
			counter = 3;
			setTimer1(300);
		}
		if(isButton1Pressed() == 1){
			status = MAN_RED;
			setTimer1(200);
		}

		break;
	default:
		break;
	}
	//counter--;
}

