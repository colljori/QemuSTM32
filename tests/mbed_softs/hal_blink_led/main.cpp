/* Templates for tests using mbed
 * This template is launched using mbed startup and used HAL functions
 * and macros to manipulate the Nucleo Board
 *
 * 
 * 
 */

#include "mbed.h"

#define LED_GREEN GPIO_PIN_12
#define LED_ORANGE GPIO_PIN_13
#define LED_RED GPIO_PIN_14
#define LED_BLUE GPIO_PIN_15

/* Global variable used by hal macro and functions */ 
TIM_HandleTypeDef htim3;

/* Redefine IRQ Handler */
extern "C"
void TIM3_IRQHandler(void) {
	if (__HAL_TIM_GET_FLAG(&htim3, TIM_FLAG_UPDATE) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim3, TIM_FLAG_UPDATE);
	}
}


/* Main function */
int main() {

    int pin = LED_GREEN;

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
    __HAL_RCC_GPIOD_CLK_ENABLE();

	/* Component initialization
	 * NOTE : search for functions and macro in stm32f4xx_hal_* inside "target" folder 
	 */

	// Init TIM3
	htim3.Instance = TIM3; 
	htim3.Init.Period = 0xFFFF; //ARR
	htim3.Init.Prescaler = 0x2000; // PSC
	htim3.Init.ClockDivision = 0;
	htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&htim3);
	HAL_TIM_Base_Start(&htim3); 

    GPIO_InitTypeDef GPIO_Init;
    GPIO_Init.Pin = pin;
    GPIO_Init.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_Init.Pull = GPIO_NOPULL;
    GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_TypeDef GPIO_D;
    HAL_GPIO_Init(&GPIO_D, &GPIO_Init);

	/* Set NVIC Interruptions 
	 * NOTE : NVIC_SetVector(TIM3_IRQn, My_TIM3_IRQHandler);
	 *  can be used with a personnal IRQ Handler instead of redefine TIM3_IRQHandler
	 */
	NVIC_EnableIRQ(TIM3_IRQn); 	  

	/* Enable components interrupts generation */
	__HAL_TIM_ENABLE_IT(&htim3, TIM_IT_UPDATE);

    HAL_GPIO_WritePin(&GPIO_D, pin, GPIO_PIN_SET); 
}

