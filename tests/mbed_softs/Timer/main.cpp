#include "mbed.h"

DigitalOut myled(LED2);
TIM_HandleTypeDef htim;

void Basic_TIM_IRQHandler(void) {
	if (__HAL_TIM_GET_FLAG(&htim, TIM_FLAG_UPDATE) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim, TIM_FLAG_UPDATE);
		myled = !myled;
	}
	if (__HAL_TIM_GET_FLAG(&htim, TIM_FLAG_CC1) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim, TIM_FLAG_CC1);
		uint32_t prev = __HAL_TIM_GET_COMPARE(&htim, TIM_CHANNEL_1);
		__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_1, prev + 0xF000);
	}
	if (__HAL_TIM_GET_FLAG(&htim, TIM_FLAG_CC2) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim, TIM_FLAG_CC2);
		uint32_t prev = __HAL_TIM_GET_COMPARE(&htim, TIM_CHANNEL_2);
		__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_2, prev + 0xFFFF);
	}

	if (__HAL_TIM_GET_FLAG(&htim, TIM_FLAG_CC3) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim, TIM_FLAG_CC3);
	}
	if (__HAL_TIM_GET_FLAG(&htim, TIM_FLAG_CC4) == SET) {
		__HAL_TIM_CLEAR_FLAG(&htim, TIM_FLAG_CC4);
	}
}

void test1(); 
void test2();

int main() {
	// Freeze Timer when debugging
	__HAL_DBGMCU_FREEZE_TIM2(); 
	__HAL_DBGMCU_FREEZE_TIM3(); 
	__HAL_DBGMCU_FREEZE_TIM4(); 
	__HAL_DBGMCU_FREEZE_TIM5();

	// Enable TIMs
	__HAL_RCC_TIM2_CLK_ENABLE(); 
	__HAL_RCC_TIM3_CLK_ENABLE(); 

	test1(); 	

}

/* Basic test */
void test1(){
	htim.Instance = TIM3; 
	htim.Init.Period = 0xFFFF; //ARR
	htim.Init.Prescaler = 0x8FF; // PSC
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV0;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&htim);
	HAL_TIM_Base_Start(&htim); 	

	/* Enable IRQ */ 
	NVIC_EnableIRQ(TIM3_IRQn);
	NVIC_SetVector(TIM3_IRQn, (uint32_t) Basic_TIM_IRQHandler);

	__HAL_TIM_ENABLE_IT(&htim, TIM_IT_UPDATE);
}


/* Output compare test */ 
void test2(){
	htim.Instance = TIM2; 
	htim.Init.Period = 0xFFFFFFFF; //ARR
	htim.Init.Prescaler = 0xF53; // PSC
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV0;
	htim.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&htim);
	HAL_TIM_Base_Start(&htim); 	

	/* Enable IRQ */ 
	NVIC_EnableIRQ(TIM2_IRQn); 
	NVIC_SetVector(TIM2_IRQn, (uint32_t) Basic_TIM_IRQHandler);
		
	__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_1, 0xF000);
	__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL_2, 0xFFFF);

	__HAL_TIM_ENABLE_IT(&htim, TIM_IT_CC1);
	__HAL_TIM_ENABLE_IT(&htim, TIM_IT_CC2);
}
