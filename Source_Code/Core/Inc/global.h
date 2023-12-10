/*
 * global.h
 *
 *  Created on: 25 thg 11, 2023
 *      Author: Asus
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "string.h"
#include "software_timer.h"

#define START_PARSER		1
#define RECEIVE_COMMAND		2

#define WAIT_COMMAND		10
#define SEND_DATA			11

# define MAX_BUFFER_SIZE 30

extern uint8_t temp;
extern uint32_t ADC_value;

extern uint8_t buffer [MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;
extern char str[MAX_BUFFER_SIZE];

extern int parser_status;
extern int uart_status;

//extern int check_command_status;

extern int print_status;
extern int send_data_status;


ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

void clear_buffer();
void check_command();

#endif /* INC_GLOBAL_H_ */
