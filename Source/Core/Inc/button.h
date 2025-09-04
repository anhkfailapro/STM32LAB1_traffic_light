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
extern int button2_flag;
extern int button3_flag;
extern int button4_flag;

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
void subKey1Process();
void getKey1Input();

int isButton2Pressed();
void subKey2Process();
void getKey2Input();


int isButton3Pressed();
void subKey3Process();
void getKey3Input();

int isButton4Pressed();
void subKey4Process();
void getKey4Input();



#endif /* INC_BUTTON_H_ */
