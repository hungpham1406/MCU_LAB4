/*
 * command_parser.c
 *
 *  Created on: Nov 25, 2023
 *      Author: Asus
 */

#include "command_parser.h"

uint8_t temp=0;
uint8_t buffer [ MAX_BUFFER_SIZE ]={0};
uint8_t index_buffer=0;
uint8_t buffer_flag=0;

char str[MAX_BUFFER_SIZE] = {0};
