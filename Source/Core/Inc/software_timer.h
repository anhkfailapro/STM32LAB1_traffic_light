/*
 * software_timer.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer0_flag;

void setTimer1(int duration);
void timerRun1();

void setTimer0(int duration);
void timerRun0();


#endif /* INC_SOFTWARE_TIMER_H_ */
