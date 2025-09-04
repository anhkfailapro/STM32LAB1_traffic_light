/*
 * button.h
 *
 *  Created on: Sep 4, 2025
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

extern int button1_flag;

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
void subKeyProcess();
void getKeyInput();


#endif /* INC_BUTTON_H_ */
