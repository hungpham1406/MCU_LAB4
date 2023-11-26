/*
 * command_parser.h
 *
 *  Created on: Nov 25, 2023
 *      Author: Asus
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

# define MAX_BUFFER_SIZE 30

#include "global.h"

extern uint8_t buffer [MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern char str[MAX_BUFFER_SIZE];

void clear_bufer();
void command_parser_fsm();

#endif /* INC_COMMAND_PARSER_H_ */
