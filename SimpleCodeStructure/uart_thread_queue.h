#ifndef UART_QUEUE_HEADER
#define UART_QUEUE_HEADER

/* RTOS header files */
#include <FreeRTOS.h>
#include <queue.h>

#include "debug.h"
#define MAXUARTSTRINGLENGTH 50
typedef struct {
    char messagerecived[MAXUARTSTRINGLENGTH];
    int length;
} UARTMessage;

//QueueHandle_t uart_queue; //.c

void init_uart_queue();

void push_uart_msg(UARTMessage *msgptr);
void pop_uart_msg(UARTMessage *msgptr);


#endif
