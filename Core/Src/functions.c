

#include "config.h"
#include "stm32f0xx_hal.h"
#include "stm32f1_rc522.h"

uint8_t Key_Card[5]  = {0x93, 0x59, 0x93, 0x6, 0x5f};
uint8_t Key_Card2[5] = {0xdc, 0x27, 0x87, 0x64, 0x18};


void Motor_forward(void)
{
	MOTOR_POSITIVE_HIGH;
	MOTOR_NEGATIVE_LOW;
}

void Motor_backward(void)
{
	MOTOR_POSITIVE_LOW;
	MOTOR_NEGATIVE_HIGH;
}

void Motor_stop(void)
{
	MOTOR_POSITIVE_HIGH;
	MOTOR_NEGATIVE_HIGH;
}

void Flap_open(void)
{
	Motor_forward();
	while(GET_LIMIT_MAX)
	{

	}
	Motor_stop();
}

void Flap_close(void)
{
	Motor_backward();
	while(GET_LIMIT_MIN)
	{

	}
	Motor_stop();
}

uint8_t Flap_position(void)
{
	if((GET_LIMIT_MIN == HIGH))
	{
		return OPEN;
	}
	else if((GET_LIMIT_MAX == HIGH))
	{
		return CLOSE;
	}
	else if ((GET_LIMIT_MAX == HIGH) && (GET_LIMIT_MIN == HIGH))
	{
		return OPEN;
	}
	else
	{
		return OPEN;
	}

}

void Card_detect(void)
{
	HAL_Delay(30*1000);
	if(Flap_position() == OPEN)
	{
		Flap_close();
	}

	uint8_t str[16]; // Max_LEN = 16
	uint8_t status;

	while(1)
	{
		status = MFRC522_Request(PICC_REQIDL, str);	//MFRC522_Request(0x26, str)
		status = MFRC522_Anticoll(str);		//Take a collision, look up 5 bytes
		if(status == MI_OK)
		{
			if( ((str[0] == Key_Card[0]) &&
				(str[1] == Key_Card[1]) &&
				(str[2] == Key_Card[2]) &&
				(str[3] == Key_Card[3]) &&
				(str[4] == Key_Card[4])) ||

				((str[0] == Key_Card2[0]) &&
				(str[1] == Key_Card2[1]) &&
				(str[2] == Key_Card2[2]) &&
				(str[3] == Key_Card2[3]) &&
				(str[4] == Key_Card2[4])))
			{
				Flap_open();
				HAL_Delay(2*1000);

			}

		}

		HAL_Delay(100);
	}



}



















