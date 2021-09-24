/*
 * uart_thread.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Jrore
 */

#include <stdint.h>
#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/UART.h>

#include "uart_thread.h"
#include "ti_drivers_config.h"
#include "FreeRTOS.h"
#include "queue.h"

//Recives messaes containing C-strings
//Outputs them to the UART
//Make API call to create task

void *uartTask(void *arg0)
{
    dbgEvent(UART_THREAD_2_BEGIN);
    static UARTMessage message;
    //char message[50] = "\n"; //message is a pointer
    //struct instead of char

    UART_Handle uart;
    UART_Params uartParams;

    /* Call driver init functions */
    UART_init();

    /* Create a UART with the parameters below. */
    UART_Params_init(&uartParams);
    uartParams.writeMode = UART_MODE_BLOCKING;
    uartParams.readMode = UART_MODE_BLOCKING;
    uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.baudRate = 115200;
    uartParams.readEcho = UART_ECHO_OFF;

    uart = UART_open(CONFIG_UART_0, &uartParams);
    //check uart fatal error if null
    dbgEvent(UART_WHILE);

     while (1) {

         dbgEvent(UART_BEFORE_QUEUE_RECEIVE);
         pop_uart_msg(&message);
         dbgEvent(UART_AFTER_QUEUE_RECEIVE);


         dbgEvent(UART_BEFORE_WRITE);
         //check without &
         UART_write(uart, &message.messagerecived, message.length);
         dbgEvent(UART_AFTER_WRITE);
     }
}
