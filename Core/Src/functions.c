

#include "config.h"
#include "stm32f0xx_hal.h"
#include "stm32f1_rc522.h"
#include "Flash_Page_f0.h"

uint8_t Key_Card1[5];
uint8_t Key_Card2[5];
//uint8_t Key_Card_Read[5] ;


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
			if(((str[0] == Key_Card1[0]) &&
				(str[1] == Key_Card1[1]) &&
				(str[2] == Key_Card1[2]) &&
				(str[3] == Key_Card1[3]) &&
				(str[4] == Key_Card1[4])) ||

				((str[0] == Key_Card2[0]) &&
				(str[1] == Key_Card2[1]) &&
				(str[2] == Key_Card2[2]) &&
				(str[3] == Key_Card2[3]) &&
				(str[4] == Key_Card2[4])))
			{
				WHITE_LED_ON;
				Flap_open();
				HAL_Delay(2*1000);

			}

		}

		HAL_Delay(100);
	}



}


void Store_UID(void)
{
	if(!IS_READ_MODE_ACTIVE)
	{
		return;
	}


	uint8_t str[16]; // Max_LEN = 16
	uint8_t status;

	while(1)
	{
		status = MFRC522_Request(PICC_REQIDL, str);	//MFRC522_Request(0x26, str)
		status = MFRC522_Anticoll(str);				//Take a collision, look up 5 bytes
		if(status == MI_OK)
		{

			  Flash_Write_Data(STORE_ADDRESS_1,str, 5);

			  for(int i=0;i<11;i++)
			  {
				  USER_LED_TOGGLE;
				  HAL_Delay(100);
			  }

			  USER_LED_oFF;
			  USER_LED_ON;
			  HAL_Delay(2000);
			  USER_LED_oFF;
			  while(1)
			  	{
			  		status = MFRC522_Request(PICC_REQIDL, str);	//MFRC522_Request(0x26, str)
			  		status = MFRC522_Anticoll(str);				//Take a collision, look up 5 bytes
			  		if(status == MI_OK)
			  		{

			  			  Flash_Write_Data(STORE_ADDRESS_2,str, 5);

			  			  for(int i=0;i<11;i++)
			  			  {
			  				  USER_LED_TOGGLE;
			  				  HAL_Delay(100);
			  			  }
			  			USER_LED_oFF;
			  			return;
			  		}
			  		HAL_Delay(100);
			  	}
		USER_LED_oFF;

		HAL_Delay(100);

		}

	}
}

void Retrieve_UID(void)
{
	Flash_Read_Data (STORE_ADDRESS_1, Key_Card1, 5);
	Flash_Read_Data (STORE_ADDRESS_2, Key_Card2, 5);
}














