// Name: uart_interface.c
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

#include "uart_interface.h"


/**
 * @brief
 * @note
 *
 * @param huart
 * @param uart
 * @return
 */
void interrupt_rxtx(UART_HandleTypeDef* huart, UartInfo* uart) {
    uint8_t i;
    if (uart->rx_indx == 0) {
        for(i = 0; i < RX_BUFFER_SIZE; i++) {
            uart->rx_buffer[i] = 0;  // clear Rx_Buffer before receiving new data
        }
    }
    if (uart->rx_data[0] != 13) {  // if received data different from ascii 13 (enter)
        uart->transfer_cplt = false;
        uart->rx_buffer[(uart->rx_indx)++] = uart->rx_data[0];
        HAL_UART_Transmit(huart, uart->rx_data, 1, 1000);
    } else {
        // uart->rxBuffer[(uart->rx_indx)++] = uart->rx_data[0];  // testing
        uart->rx_indx = 0;
        uart->transfer_cplt = true;  // transfer complete, data is ready to read
        HAL_UART_Transmit(huart, "\r\n", 2, 1000);
    }
    // Activate UART receive interrupt every time
    HAL_UART_Receive_IT(huart, uart->rx_data, 1);
}
