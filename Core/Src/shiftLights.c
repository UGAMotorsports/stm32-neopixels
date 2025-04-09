/*
 * shiftLights.c
 *
 *  Created on: Mar 29, 2025
 *      Author: cathy
 */
#include <stdint.h>
#include <stdio.h>
#include "shiftLights.h"

volatile uint8_t datasentflag;
extern TIM_HandleTypeDef htim4;


void setColor(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t green, uint8_t red,
		uint8_t blue, uint8_t *ledcolors, uint16_t *ledbytes, int ledIndex) {

	int index = (ledIndex * 3);
	ledcolors[index] = green;
    ledcolors[index + 1] = red;
    ledcolors[index + 2] = blue;

    for (int i = index; i < (index + 3); i++) {
    	for (int j = 0; j < 8; j++) {
    		if ((ledcolors[i] << j) & 128) {
    			ledbytes[(i * 8) + j] = 90;
    		} else {
    			ledbytes[(i * 8) + j] = 20;
    		}
    	}
    }
    for (int i = PWM_BUFFER_SIZE; i < (PWM_BUFFER_SIZE + 150); i++) {
    	ledbytes[i] = 35;
    }
    HAL_TIM_PWM_Start_DMA(htim, Channel, (uint32_t *)ledbytes, PWM_BUFFER_SIZE + 150);
    while (!datasentflag) {};
    datasentflag = 0;
}

void shiftLightsInit(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t *ledcolors, uint16_t *ledbytes) {
	for (int i = 0; i < 48; i += 3) {
		ledcolors[i] = 0;
		ledcolors[i + 1] = 0;
		ledcolors[i + 2] = 255;
	}
	for (int i = 0; i < 48; i++) {
		for (int j = 0; j < 8; j++) {
			if ((ledcolors[i] << j) & 128) {
				ledbytes[(i * 8) + j] = 70;
			} else {
				ledbytes[(i * 8) + j] = 35;
			}
		}
	}
	for (int i = PWM_BUFFER_SIZE; i < (PWM_BUFFER_SIZE + 150); i++) {
		ledbytes[i] = 35;
	}
	HAL_TIM_PWM_Start_DMA(htim, Channel, (uint32_t *)ledbytes, PWM_BUFFER_SIZE + 150);
	while(!datasentflag) {};
	datasentflag = 0;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	HAL_TIM_PWM_Stop_DMA(&htim4, TIM_CHANNEL_1);
	datasentflag = 1;
}


// Function to handle the shift lights
//void UpdateShiftLights(uint32_t current_rpm, int numLights) {
  //  for (int i = 0; i < numLights; i++) {
 //       if (current_rpm >= RPM_thresholds[i]) {
  //          // Turn on the shift light (use appropriate LED control function)
   //         TurnOnShiftLight(i);  // This is a placeholder for your actual function
   //     } else {
   //         // Turn off the shift light
   //         TurnOffShiftLight(i);  // This is a placeholder for your actual function
   //     }
  //  }
//}
