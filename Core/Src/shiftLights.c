/*
 * shiftLights.c
 *
 *  Created on: Mar 29, 2025
 *      Author: cathy
 */

#include "shiftLights.h"

int datasentflag;
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
    			ledbytes[(i * 8) + j] = 70;
    		} else {
   			ledbytes[(i * 8) + j] = 35;
    		}
    	}
    }
    for (int i = PWM_BUFFER_SIZE; i < (PWM_BUFFER_SIZE + 150); i++) {
    	ledbytes[i] = 0;
    }
    HAL_TIM_PWM_Start_DMA(htim, Channel, (uint32_t *)ledbytes, PWM_BUFFER_SIZE + 150);
    while (!datasentflag) {};
    datasentflag = 0;
}

void shiftLightsInit(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t *ledcolors, uint16_t *ledbytes) {
	for (int i = 0; i < 48; i += 3) {
		ledcolors[i] = 128;
		ledcolors[i + 1] = 255;
		ledcolors[i + 2] = 0;
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
		ledbytes[i] = 0;
	}
	HAL_TIM_PWM_Start_DMA(htim, Channel, (uint32_t *)ledbytes, PWM_BUFFER_SIZE + 150);
	while(!datasentflag) {};
	datasentflag = 0;

	ledbytes = 0;
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim) {
	HAL_TIM_PWM_Stop_DMA(&htim4, TIM_CHANNEL_1);
	datasentflag = 1;
}


void UpdateShiftLights(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t *ledcolors,
		uint16_t *ledbytes, int current_rpm, int * RPM_thresholds) {
  for (int i = 2; i < 14; i++) {
    if (current_rpm >= RPM_thresholds[i]) {
        // Turn on the shift light (use appropriate LED control function)
    	lightOn(htim, Channel,ledcolors, ledbytes, i);
    } else {
        // Turn off the shift light
    	setColor(htim, Channel, 0, 0, 0, ledcolors, ledbytes, i);
    }
  }
}

void lightOn(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t *ledcolors,
		uint16_t *ledbytes,int index) {
	if (index < 6) {
		setColor(htim, Channel, 255, 255, 0, ledcolors, ledbytes, index);
	} else if (index < 10) {
		setColor(htim, Channel, 128, 255, 0, ledcolors, ledbytes, index);
	} else if (index < 13){
		setColor(htim, Channel, 0, 255, 0, ledcolors, ledbytes, index);
	} else {

	}
}

void startUp(TIM_HandleTypeDef *htim, uint32_t Channel, uint8_t *ledcolors, uint16_t *ledbytes) {
	int middle = 7;
	for (int i = 0; i < 8; i++) {
		setColor(htim, Channel, 0, 255, 0, ledcolors, ledbytes, middle - i);
		setColor(htim, Channel, 0, 255, 0, ledcolors, ledbytes, middle + i + 1);
		HAL_Delay(25);
	}
	for (int i = 0; i < 8; i++) {
		setColor(htim, Channel, 0, 0, 0, ledcolors, ledbytes, middle - i);
		setColor(htim, Channel, 0, 0, 0, ledcolors, ledbytes, middle + i + 1);
		HAL_Delay(25);
	}
}


