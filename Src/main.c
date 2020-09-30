/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"

int main(void)
{
  /*
   *  DO NOT WRITE TO THE WHOLE REGISTER!!!
   *  Write to the bits, that are meant for change.
   */


  /*
   * TASK - configure MCU peripherals so that button state can be read and LED will blink.
   * Button must be connected to the GPIO port A and its pin 3.
   * LED must be connected to the GPIO port A and its pin 4.
   *
   * In header file "assignment.h" define macros for MCU registers access and LED blink application.
   * Code in this file must use these macros for the peripherals setup.
   * Code of the LED blink application is already given so just the macros used in the application must be defined.
   */


  /* Enable clock for GPIO port A*/

	  *((volatile uint32_t *) (uint32_t)(0x40021000 + 0x00000014U)) |= (uint32_t)(1 << 17);


	//type your code for GPIOA clock enable here:


  /* GPIOA pin 3 and 4 setup */
	  //pin 3 tlacidlo 00 je rdy na Input
	   *((volatile uint32_t *)((uint32_t)0x48000400)) &= ~(uint32_t)(0x3 << 6); //vyresetujem
	   // *((volatile uint32_t *)((uint32_t)0x48000400)) |= (uint32_t)(1 << 6);	//zapisem 1
	   *((volatile uint32_t *)((uint32_t)0x48000400)) &= ~(uint32_t)(0x3 << 8); //vyresetujem 4 pin pre istotu
	   *((volatile uint32_t *)((uint32_t)0x48000400)) |= (uint32_t)(1 << 8);	//zapisem 1 aby bolo 01 general purpose output mode

	//type your code for GPIOA pins setup here:

	   /*GPIO OTYPER register*/
	     *((volatile uint32_t *)((uint32_t)(0x48000400 + 0x04U))) &= ~(1 << 4);

	   /*GPIO OSPEEDR register*/
	       //Set Low speed for GPIOA pin 4
	     *((volatile uint32_t *)((uint32_t)(0x48000400 + 0x08U))) &= ~(0x3 << 8);

	     /*GPIO PUPDR register, reset*/
	       //Set pull up for GPIOB pin 3 (input)
	       *((volatile uint32_t *)((uint32_t)(0x48000400 + 0x0CU))) |= (1 << 6);
	       //Set no pull for GPIOB pin 4
	       *((volatile uint32_t *)((uint32_t)(0x48000400 + 0x0CU))) &= ~(0x3 << 8);
  while (1)
  {
	  if(BUTTON_GET_STATE)
	  {
		  // 0.25s delay
		  LL_mDelay(250);
		  LED_ON;
		  // 0.25s delay
		  LL_mDelay(250);
		  LED_OFF;
	  }
	  else
	  {
		  // 1s delay
		  LL_mDelay(1000);
		  LED_ON;
		  // 1s delay
		  LL_mDelay(1000);
		  LED_OFF;
	  }
  }

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
