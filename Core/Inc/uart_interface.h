// Name: uart_interface.h
// Description: https://github.com/yongxianan/TemperatureControllerMCU
// Author: John Houlihan

//------------------------------------------------------------------------------------
// MIT License
//
// Copyright (c) 2025 John Houlihan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//------------------------------------------------------------------------------------

#ifndef uart_interface_h
#define uart_interface_h


/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f3xx_hal.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>


#define RX_BUFFER_SIZE 64


typedef struct{
	uint8_t rx_indx;
	char rx_buffer[RX_BUFFER_SIZE];
	char rx_data[2];
	bool transfer_cplt;
} UartInfo;


void interrupt_rxtx(UART_HandleTypeDef* huart1, UartInfo* uart);



#ifdef __cplusplus
}  /* End of CPP guard */
#endif


#endif  // uart_interface_h
