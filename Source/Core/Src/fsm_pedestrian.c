/*
 * fsm_pedestrian.c
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */
#include "fsm_pedestrian.h"

void fsm_pedestrian_run(){
	switch(status_ped){
	case STAY:
		WR_OFF(); WY_OFF(); WG_OFF();
		break;
	case PED_RED:
		WR_ON(); WY_OFF(); WG_OFF();
		if(timer2_flag == 1){
			counter_ped--;
			setTimer2(100);
			if(counter_ped <= 0){
				status_ped = STAY;
			}
		}
		break;
	case PED_YELLOW:
		WR_OFF(); WY_ON(); WG_OFF();
		if(timer2_flag == 1){
			counter_ped--;
			setTimer2(100);
			if(counter_ped <= 0){
				status_ped = PED_RED;
				counter_ped = 2;
			}
		}
		break;
	case PED_GREEN:
		WR_OFF(); WY_OFF(); WG_ON();
		if(timer2_flag == 1){
			counter_ped--;
			setTimer2(100);
			if(counter_ped <= 0){
				status_ped = PED_YELLOW;
				counter_ped = 2;
			}
		}
		break;
	case WAIT:
		WR_ON(); WY_OFF(); WG_OFF();
		if(timer2_flag == 1){
			counter_ped--;
			setTimer2(100);
			if(counter_ped <= 0){
				status_ped = PED_GREEN;
				counter_ped = 3;
			}
		}
		break;
	default: break;
	}
}
