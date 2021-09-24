#include "uart_thread_queue.h"
#include <stdio.h>
#include <string.h>
#define LengthUart 10
static QueueHandle_t uart_queue = NULL;

void init_uart_queue(){
    uart_queue = xQueueCreate(LengthUart,sizeof(UARTMessage));
    if(uart_queue == NULL){
        fatalError(UART_ERROR_EVENT);
    }
}

void push_uart_msg(UARTMessage *msgptr){


    BaseType_t queue_status;
    bool isr_status = HwiP_inISR();
    if(isr_status)
        queue_status = xQueueSendFromISR(uart_queue, msgptr, NULL);
    else
        queue_status = xQueueSend(uart_queue, msgptr, portMAX_DELAY);

    if(queue_status == pdFALSE)
        fatalError(UART_ERROR_EVENT);
}

void pop_uart_msg(UARTMessage *msgptr){

    BaseType_t queue_status;
    bool isr_status = HwiP_inISR();
    if(isr_status)
        queue_status = xQueueReceiveFromISR(uart_queue, msgptr, NULL);
    else
        queue_status = xQueueReceive(uart_queue, msgptr, portMAX_DELAY);

    if(queue_status == pdFALSE)
        fatalError(UART_ERROR_EVENT);
}
