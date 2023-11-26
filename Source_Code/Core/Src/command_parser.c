/*
 * command_parser.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Asus
 */

#include "command_parser.h"

uint8_t buffer [ MAX_BUFFER_SIZE ]={0};
uint8_t index_buffer=0;
uint8_t buffer_flag=0;
uint32_t ADC_value;

char str[MAX_BUFFER_SIZE] = {0};

void clear_buffer() {
	memset(buffer, 0, sizeof(buffer));
	index_buffer = 0;
}

void command_parser_fsm() {
	switch(parser_status) {
	case START_PARSER:
		if(temp == '!') {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			parser_status = RECEIVE_COMMAND;
			uart_status = WAIT_COMMAND;
			index_buffer = 0;
		}
		break;

	case RECEIVE_COMMAND:
		if(temp == '#') {
			HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
			uint32_t ADC_value;
			ADC_value= HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str, "!ADC=%lu#\r\n"
			,ADC_value), 1000);
		}
		else if(temp == '!') {
			clear_buffer();
		}
		break;

	default:
		break;
	}

}


