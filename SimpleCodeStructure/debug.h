/*
 * debug.h
 *
 *  Created on: Sep 8, 2021
 *      Author: Jimmy McAvoy
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include <ti/drivers/dpl/HwiP.h>
#include <stddef.h>

// Driver
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>

// Board
#include "ti_drivers_config.h"

#include <FreeRTOS.h>
#include <string.h>
#include <task.h>

// DEFINE EVENT VALUES

// Timer70 Debug Values
#define T70_ISR_BEGIN 0x10 //1
#define T70_BEFORE_QUEUE_SEND_ISR 0x11 //2
#define T70_AFTER_QUEUE_SEND_ISR 0x12 //3
#define T70_ISR_END 0x1F //4

// Timer500 Debug Values
#define T500_ISR_BEGIN 0x20 //1
#define T500_BEFORE_QUEUE_SEND_ISR 0x21 //2
#define T500_AFTER_QUEUE_SEND_ISR 0x22 //3
#define T500_ISR_END 0x2F //4

// Sensor Queue Debug Values
#define SENSOR_THREAD_1_BEGIN 0x30 //1
#define SENSOR_WHILE 0x31 //2
#define SENSOR_BEFORE_QUEUE_RECEIVE 0x32 //3
#define SENSOR_BEFORE_QUEUE_SEND 0x33 //4
#define SENSOR_AFTER_QUEUE_SEND 0x34 //5
#define SENSOR_AFTER_QUEUE_RECEIVE 0x3F //6

// UART Queue Debug Values
#define UART_THREAD_2_BEGIN 0x40 //1
#define UART_WHILE 0x41 //2
#define UART_BEFORE_QUEUE_RECEIVE 0x42 //3
#define UART_AFTER_QUEUE_RECEIVE 0x43 //4
#define UART_BEFORE_WRITE 0x44 //5
#define UART_AFTER_WRITE 0x4F //6

// Error Debug Values
#define T70_ERROR_EVENT 240 // 0xF0
#define T500_ERROR_EVENT 244 // 0xF4
#define SENSOR_ERROR_EVENT 248 // 0xF8
#define UART_ERROR_EVENT 255 // 0xFE


// END OF EVENT VALUES

void dbgInit();

void dbgEvent(unsigned int event);

void fatalError(unsigned int eventFailure);

#endif
