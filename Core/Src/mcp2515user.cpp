/*
 * mcp2515user.cpp
 *
 *  Created on: Apr 21, 2025
 *      Author: cathy
 */

#include "mcp2515user.h"

#include "stm32-hal-mcp2515/mcp2515.h"
#include "spi.h"
#include "gpio.h"

MCP2515 myMCP(&hspi2, 10, GPIOA, GPIO_PIN_4);
void initializeMCP2515() {
	myMCP.reset();
	myMCP.setBitrate(CAN_500KBPS, MCP_8MHZ);
	myMCP.setNormalMode();
}

int sendMessage(struct can_frame *frame) {
	return myMCP.sendMessage(frame);
}

int readMessage(struct can_frame *frame) {
	return myMCP.readMessage(frame);
}
