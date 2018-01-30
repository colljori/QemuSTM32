/* Template for tests using mbed
 * This template is launched using mbed startup and used HAL functions
 * and macros to manipulate the Nucleo Board
 *
 * Blinking led using HAL functions. 
 * 
 */

#include "mbed.h"

/* Global variable used by hal macro and functions */ 
TIM_HandleTypeDef htim3;
GPIO_InitTypeDef led1Init;
GPIO_InitTypeDef led2Init;
#define LED1 GPIO_PIN_5
#define LED2 GPIO_PIN_0

/* Redefine IRQ Handler */
extern "C"
void TIM3_IRQHandler(void) {
	if (__HAL_TIM_GET_FLAG(&htim3, TIM_FLAG_UPDATE) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_UPDATE);
		HAL_GPIO_TogglePin(GPIOA, LED1); 
	}
	if (__HAL_TIM_GET_FLAG(&htim3, TIM_FLAG_CC1) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_CC1);
		uint32_t prev = __HAL_TIM_GET_COMPARE(&htim3, TIM_CHANNEL_1);
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, prev + 0xF000);
		HAL_GPIO_TogglePin(GPIOA, LED2); 
	}
}


/* Main function */
int main() {
	/* DEBUG OPTION */ 
	// Freeze Timer when debugging
	__HAL_DBGMCU_FREEZE_TIM2(); 
	__HAL_DBGMCU_FREEZE_TIM3(); 
	__HAL_DBGMCU_FREEZE_TIM4(); 
	__HAL_DBGMCU_FREEZE_TIM5();


	/* Enable clock for components used
	 * NOTE : Some are already enable like TIM5 ... 
	 */
	__HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

	/* Component initialization
	 * NOTE : search for functions and macro in stm32f4xx_hal_* inside "target" folder 
	 */

	// Init TIM3
	htim3.Instance = TIM3; 
	htim3.Init.Period = 0xFFFF; //ARR
	htim3.Init.Prescaler = 0x0100; // PSC
	htim3.Init.ClockDivision = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&htim3);

	// Init LED 1 
    led1Init.Pin = LED1;
    led1Init.Mode = GPIO_MODE_OUTPUT_PP; 
    led1Init.Pull = GPIO_NOPULL;
    led1Init.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &led1Init);

	// Init LED 2 
    led2Init.Pin = LED2;
    led2Init.Mode = GPIO_MODE_OUTPUT_PP; 
    led2Init.Pull = GPIO_NOPULL;
    led2Init.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &led2Init);
	
	/* Set NVIC Interruptions 
	 * NOTE : NVIC_SetVector(TIM3_IRQn, My_TIM3_IRQHandler);
	 *  can be used with a personnal IRQ Handler instead of redefine TIM3_IRQHandler
	 */
	NVIC_EnableIRQ(TIM3_IRQn); 	  

	/* Enable components interrupts generation */
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_CC1);


	// Start timer
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0xF000);
	HAL_TIM_Base_Start(&htim3); 
}

