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
GPIO_InitTypeDef ledInit;
GPIO_InitTypeDef buttonInit; 
#define LED_GREEN GPIO_PIN_5 // GPIOA
#define BUTTON GPIO_PIN_13 // GPIOC

extern "C"
void EXTI15_10_IRQHandler(void){
  if(READ_BIT(EXTI->PR, 1 << 13)){	
	WRITE_REG(EXTI->PR, 1 << 13);
	HAL_GPIO_TogglePin(GPIOA, LED_GREEN); 
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
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_SYSCFG_CLK_ENABLE();

	/* Component initialization
	 * NOTE : search for functions and macro in stm32f4xx_hal_* inside "target" folder 
	 */

	// Init LED
    ledInit.Pin = LED_GREEN;
    ledInit.Mode = GPIO_MODE_OUTPUT_PP; 
    ledInit.Pull = GPIO_NOPULL;
    ledInit.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &ledInit);

	// Init LED
    buttonInit.Pin = BUTTON; 
    buttonInit.Mode = GPIO_MODE_INPUT; 
    buttonInit.Pull = GPIO_NOPULL;
    buttonInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC, &buttonInit);
	
	// Enable Interrupt button
	uint32_t temp = 0;
	uint32_t pin_index = POSITION_VAL(BUTTON); 
	temp = SYSCFG->EXTICR[pin_index >> 2];
	CLEAR_BIT(temp, (0x0FU) << (4U * (pin_index & 0x03U)));
	SET_BIT(temp, 2 << (4U * (pin_index & 0x03U)));// 2 = GPIOC 
	SYSCFG->EXTICR[pin_index >> 2] = temp;


	WRITE_REG(EXTI->IMR, 1<< pin_index);
	SET_BIT(EXTI->RTSR, 1<<pin_index);
	//SET_BIT(EXTI->FTSR, 1<<pin_index);


	/* Set NVIC Interruptions
	 * NOTE : NVIC_SetVector(TIM3_IRQn, My_TIM3_IRQHandler);
	 *  can be used with a personnal IRQ Handler instead of redefine TIM3_IRQHandler
	 */
	NVIC_EnableIRQ(EXTI15_10_IRQn); 
    HAL_GPIO_WritePin(GPIOA, LED_GREEN, GPIO_PIN_SET); 

}

