/*
 * mcp2515user.h
 *
 *  Created on: Apr 21, 2025
 *      Author: cathy
 */

#ifndef SRC_MCP2515USER_H_
#define SRC_MCP2515USER_H_

#include "stm32-hal-mcp2515/CAN.h"

#ifdef __cplusplus
extern "C" {
#endif
	void initializeMCP2515();
	int sendMessage(struct can_frame*);
	int readMessage(struct can_frame*);
#ifdef __cplusplus
}
#endif

#endif /* INC_MCP2515USER_H_ */
