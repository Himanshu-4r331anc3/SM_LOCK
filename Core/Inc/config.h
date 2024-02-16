/*
 * config.h
 *
 *  Created on: Feb 11, 2024
 *      Author: himanshu
 */

#ifndef INC_CONFIG_H_
#define INC_CONFIG_H_

#include "stm32f0xx_hal.h"


#define HIGH					1U
#define LOW						0U

#define OPEN					1U
#define CLOSE					0U

/*************** limit switch define ***************/
#define LIMIT_MAX_PIN			GPIO_PIN_0
#define LIMIT_MAX_PORT			GPIOA
#define GET_LIMIT_MAX			HAL_GPIO_ReadPin(LIMIT_MAX_PORT, LIMIT_MAX_PIN)

#define LIMIT_MIN_PIN			GPIO_PIN_1
#define LIMIT_MIN_PORT			GPIOA
#define GET_LIMIT_MIN			HAL_GPIO_ReadPin(LIMIT_MIN_PORT, LIMIT_MIN_PIN)

#define MOTOR_POSITIVE_PIN		GPIO_PIN_3
#define MOTOR_POSITIVE_PORT		GPIOA
#define MOTOR_POSITIVE_HIGH		HAL_GPIO_WritePin(MOTOR_POSITIVE_PORT, MOTOR_POSITIVE_PIN, HIGH)
#define MOTOR_POSITIVE_LOW		HAL_GPIO_WritePin(MOTOR_POSITIVE_PORT, MOTOR_POSITIVE_PIN, LOW)

#define MOTOR_NEGATIVE_PIN		GPIO_PIN_4
#define MOTOR_NEGATIVE_PORT		GPIOA
#define MOTOR_NEGATIVE_HIGH		HAL_GPIO_WritePin(MOTOR_NEGATIVE_PORT, MOTOR_NEGATIVE_PIN, HIGH)
#define MOTOR_NEGATIVE_LOW		HAL_GPIO_WritePin(MOTOR_NEGATIVE_PORT, MOTOR_NEGATIVE_PIN, LOW)

#define WHITE_LED_PIN			GPIO_PIN_2
#define WHITE_LED_PORT			GPIOA
#define WHITE_LED_ON			HAL_GPIO_WritePin(WHITE_LED_PORT, WHITE_LED_PIN, HIGH)
#define WHITE_LED_OFF			HAL_GPIO_WritePin(WHITE_LED_PORT, WHITE_LED_PIN, LOW)

#define USER_LED_PORT			GPIOA
#define USER_LED_PIN			GPIO_PIN_5
#define USER_LED_ON				HAL_GPIO_WritePin(USER_LED_PORT, USER_LED_PIN, LOW)
#define USER_LED_ofF			HAL_GPIO_WritePin(USER_LED_PORT, USER_LED_PIN, HIGH)
#define USER_LED_TOGGLE			HAL_GPIO_TogglePin(USER_LED_PORT, USER_LED_PIN)




/**************** function declarations ********************/

void Motor_forward(void);
void Motor_backward(void);
void Motor_stop(void);
void Flap_open(void);
void Flap_close(void);
uint8_t Flap_position(void);
void Card_detect(void);




#endif /* INC_CONFIG_H_ */
