/*
 * command_parser.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Asus
 */

#include "command_parser.h"

void command_parser_fsm() {
	switch(parser_status) {
	case START_PARSER:
		if(temp == '!') {
			parser_status = RECEIVE_COMMAND;
			uart_status = WAIT_COMMAND;
		}
		break;

	case RECEIVE_COMMAND:
		if(temp == '#') {
			check_command();
			parser_status = START_PARSER;
		}
		else if(temp == '!') {
			clear_buffer();
		}
		break;

	default:
		break;
	}

}


