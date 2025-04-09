/*
 * shiftLights.h
 *
 *  Created on: Mar 29, 2025
 *      Author: cathy
 */


#ifndef SHIFTLIGHTS_H_
#define SHIFTLIGHTS_H_

//Includes
#include "main.h"
#include "stm32f4xx_hal.h"


#define LED_COUNT 16    // Number of WS2812B LEDs
#define BITS_PER_LED 24  // 8 Red + 8 Green + 8 Blue
#define PWM_BUFFER_SIZE (LED_COUNT * BITS_PER_LED)

void setColor(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t red, uint8_t green,
		uint8_t blue, uint8_t *ledcolors, uint16_t *ledbytes, int ledIndex);
void UpdateShiftLights(uint32_t current_rpm, int numLights);
void shiftLightsInit(TIM_HandleTypeDef *htim, uint32_t Channel,
		uint8_t *ledcolors, uint16_t *ledBytes);



#endif /* SHIFTLIGHTS_H_ */
