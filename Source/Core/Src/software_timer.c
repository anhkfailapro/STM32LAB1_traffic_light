/*
 * software_timer.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */


#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;

int timer0_counter = 0;
int timer0_flag = 0;

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun1(){
	if(timer1_counter > 0)
		if (--timer1_counter <= 0)
			timer1_flag = 1;
}

void setTimer0(int duration){
	timer0_counter = duration;
	timer0_flag = 0;
}

void timerRun0(){
	if(timer0_counter > 0)
		if (--timer0_counter <= 0)
			timer0_flag = 1;
}

