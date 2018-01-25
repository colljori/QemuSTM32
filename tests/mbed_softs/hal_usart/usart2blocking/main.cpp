/* Templates for tests using mbed
* This template is launched using mbed startup and used HAL functions
* and macros to manipulate the Nucleo Board
*
*
*
*/

#include "mbed.h"

/* Global variable used by hal macro and functions */
USART_HandleTypeDef usart1;
USART_HandleTypeDef usart2;

/* Redefine IRQ Handler */
// extern "C"
// void TIM3_IRQHandler(void) {
// 	if (__HAL_TIM_GET_FLAG(&htim3, TIM_FLAG_UPDATE) == SET) {
// 		__HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_UPDATE);
// 	}
// }


/* Main function */
int main() {
	/* DEBUG OPTION */
	// Freeze Timer when debugging
	// __HAL_DBGMCU_FREEZE_TIM2();
	// __HAL_DBGMCU_FREEZE_TIM3();
	// __HAL_DBGMCU_FREEZE_TIM4();
	// __HAL_DBGMCU_FREEZE_TIM5();


	/* Enable clock for components used
	* NOTE : Some are already enable like TIM5 ...
	*/
	__GPIOA_CLK_ENABLE();		//stm32f4xx_hal_rcc.h:402
	__USART1_CLK_ENABLE();	//stm32f4xx_hal_rcc.h:587

	/* Component initialization
	* NOTE : search for functions and macro in stm32f4xx_hal_* inside "target" folder
	*/

	/* Configure usart TX pin */
	GPIO_InitTypeDef GPIO_InitStructure;

	//USART1
	// GPIO_InitStructure.Pin = GPIO_PIN_9 | GPIO_PIN_10;	//USART1-RX(10) USART1-TX(9)
	// GPIO_InitStructure.Speed = GPIO_SPEED_LOW;
	// GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	// GPIO_InitStructure.Pull = GPIO_PULLUP;
	// GPIO_InitStructure.Alternate = GPIO_AF7_USART1;

	//GPIO configuraton
	GPIO_InitStructure.Pin = 	GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 |	//USART2-RX(3) USART2-TX(2) USART2-CLK(4)
		 												GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;	//USART1-RX(8) USART1-TX(9) USART1-CLK(10)
	GPIO_InitStructure.Speed = GPIO_SPEED_LOW;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2 |GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);


	//USART2 configuraton
	usart2.Instance=USART2;	//define at mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE/device/stm32f401xe.h
	usart2.Init.BaudRate=9600;
	usart2.Init.WordLength=USART_WORDLENGTH_8B;
	usart2.Init.StopBits=USART_STOPBITS_2;
	usart2.Init.Parity=USART_PARITY_NONE;
	usart2.Init.Mode=USART_MODE_TX;
	usart2.Init.CLKPolarity=USART_POLARITY_HIGH;
	usart2.Init.CLKPhase=USART_PHASE_2EDGE;
	usart2.Init.CLKLastBit=USART_LASTBIT_ENABLE;

	volatile HAL_StatusTypeDef usart2_status = HAL_USART_Init(&usart2);


	//USART1 configuraton
	usart1.Instance=USART1;	//define at mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE/device/stm32f401xe.h
	usart1.Init.BaudRate=9600;
	usart1.Init.WordLength=USART_WORDLENGTH_8B;
	usart1.Init.StopBits=USART_STOPBITS_1;
	usart1.Init.Parity=USART_PARITY_NONE;
	usart1.Init.Mode=USART_MODE_TX;
	usart1.Init.CLKPolarity=USART_POLARITY_LOW;
	usart1.Init.CLKPhase=USART_PHASE_1EDGE;
	usart1.Init.CLKLastBit=USART_LASTBIT_ENABLE;

	volatile HAL_StatusTypeDef usart1_status = HAL_USART_Init(&usart1);

	switch(usart2_status){
		case HAL_OK:			//0x00U
			uint8_t data[3];
			data[0]='a';
			data[1]='b';
			data[2]='c';
			HAL_USART_Transmit(&usart2,data,3,10000);	// send in blocking mode
		break;
		case HAL_ERROR:		//0x01U
		break;
		case HAL_BUSY:		//0x02U
		break;
		case HAL_TIMEOUT:	//0x03U
		break;
		default:
		break;
	}

	switch(usart1_status){
		case HAL_OK:			//0x00U
			uint8_t data[3];
			data[0]='d';
			data[1]='e';
			data[2]='f';
			HAL_USART_Transmit(&usart1,data,3,10000);	// send in blocking mode
		break;
		case HAL_ERROR:		//0x01U
		break;
		case HAL_BUSY:		//0x02U
		break;
		case HAL_TIMEOUT:	//0x03U
		break;
		default:
		break;
	}

}
