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
GPIO_InitTypeDef inputInit; 
#define LED_GREEN GPIO_PIN_5 // GPIOA
#define PIN GPIO_PIN_0 // GPIOC

extern "C"

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

	// Init Input
    inputInit.Pin = PIN; 
    inputInit.Mode = GPIO_MODE_INPUT; 
    inputInit.Pull = GPIO_NOPULL;
    inputInit.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOC, &inputInit);
	
    while(1){
        if(HAL_GPIO_ReadPin(GPIOC, PIN) == GPIO_PIN_SET) {
            HAL_GPIO_WritePin(GPIOA, LED_GREEN, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin(GPIOA, LED_GREEN, GPIO_PIN_RESET);        
        }
    }
}

