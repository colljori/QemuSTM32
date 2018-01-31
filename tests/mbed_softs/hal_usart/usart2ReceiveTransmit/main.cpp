/* Templates for tests using mbed
* This template is launched using mbed startup and used HAL functions
* and macros to manipulate the Nucleo Board
*
*
*
*/

#include "mbed.h"

/* Global variable used by hal macro and functions */
USART_HandleTypeDef usart2;



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
	__USART2_CLK_ENABLE();	//stm32f4xx_hal_rcc.h:587

	/* Component initialization
	* NOTE : search for functions and macro in stm32f4xx_hal_* inside "target" folder
	*/

	/* Configure usart TX pin */
	GPIO_InitTypeDef GPIO_InitStructure;

	//GPIO configuraton
	GPIO_InitStructure.Pin = 	GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4;		//USART2-RX(3) USART2-TX(2) USART2-CLK(4)
	GPIO_InitStructure.Speed = GPIO_SPEED_LOW;
	GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStructure.Pull = GPIO_PULLUP;
	GPIO_InitStructure.Alternate = GPIO_AF7_USART2;

	HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);


	//USART2 configuraton
	usart2.Instance=USART2;	//define at mbed-dev/targets/TARGET_STM/TARGET_STM32F4/TARGET_STM32F401xE/device/stm32f401xe.h
	usart2.Init.BaudRate=9600;
	usart2.Init.WordLength=USART_WORDLENGTH_8B;
	usart2.Init.StopBits=USART_STOPBITS_2;
	usart2.Init.Parity=USART_PARITY_NONE;
	usart2.Init.Mode=USART_MODE_TX_RX;
	usart2.Init.CLKPolarity=USART_POLARITY_LOW;
	usart2.Init.CLKPhase=USART_PHASE_2EDGE;
	usart2.Init.CLKLastBit=USART_LASTBIT_DISABLE;

	volatile HAL_StatusTypeDef usart2_status = HAL_USART_Init(&usart2);

	volatile uint8_t data1;
	volatile uint8_t data2;
	volatile uint8_t data3;

	switch(usart2_status){
		case HAL_OK:			//0x00U
			uint8_t data[3];
			data[0] = 'a';
			data[1] = 'b';
			data[2] = 'c';
			HAL_USART_Transmit(&usart2,data,3,10000);	// send in blocking mode
			HAL_USART_Receive(&usart2,data,3,10000);	// receive in blocking mode
			data1 = data[0];
			data2 = data[1];
			data3 = data[2];
			data1++;
			data2++;
			data3++;
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
