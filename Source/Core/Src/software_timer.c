/*
 * software_timer.c
 *
 *  Created on: Sep 3, 2025
 *      Author: Admin
 */
#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;

void setTimer1(int duration){
	timer1_counter = duration;
	timer1_flag = 0;
}

void timerRun1(){
	if(timer1_counter > 0)
		if(--timer1_counter <= 0)
			timer1_flag = 1;
}

int timer2_counter = 0;
int timer2_flag = 0;

void setTimer2(int duration){
	timer2_counter = duration;
	timer2_flag = 0;
}

void timerRun2(){
	if(timer2_counter > 0)
		if(--timer2_counter <= 0)
			timer2_flag = 1;
}

int timer3_counter = 0;
int timer3_flag = 0;

void setTimer3(int duration){
	timer3_counter = duration;
	timer3_flag = 0;
}

void timerRun3(){
	if(timer3_counter > 0)
		if(--timer3_counter <= 0)
			timer3_flag = 1;
}

int timer4_counter = 0;
int timer4_flag = 0;

void setTimer4(int duration){
	timer4_counter = duration;
	timer4_flag = 0;
}

void timerRun4(){
	if(timer4_counter > 0)
		if(--timer4_counter <= 0)
			timer4_flag = 1;
}

int timer5_counter = 0;
int timer5_flag = 0;

void setTimer5(int duration){
	timer5_counter = duration;
	timer5_flag = 0;
}

void timerRun5(){
	if(timer5_counter > 0)
		if(--timer5_counter <= 0)
			timer5_flag = 1;
}
