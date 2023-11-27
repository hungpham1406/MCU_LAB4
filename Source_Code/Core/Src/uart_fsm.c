/*
 * uart_fsm.c
 *
 *  Created on: 25 thg 11, 2023
 *      Author: Asus
 */

#include "uart_fsm.h"

void uart_communication_fsm () {
	switch(uart_status) {
	case WAIT_COMMAND:
		if(check_command_status == 1) {

			check_command();
		}
		if(print_status == 1) {
			uart_status = SEND_DATA;
			setTimer2(50);

			print_status = 0;
		}
		break;

	case SEND_DATA:
		if(timer2_flag == 1) {
			setTimer2(50);
			send_data_status = 1;
			ADC_value = HAL_ADC_GetValue(&hadc1);
			HAL_UART_Transmit(&huart2, (uint8_t *)str, sprintf(str , "!ADC=%lu#\r\n"
						       ,ADC_value), 1000);
		}
		break;

	default:
			break;
	}

}

