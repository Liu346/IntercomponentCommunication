#ifndef SENSOR_QUEUE_HEADER
#define SENSOR_QUEUE_HEADER


/* RTOS header files */
#include <FreeRTOS.h>
#include <queue.h>

#include "debug.h"

typedef enum message_type { TIMER70_MESSAGE, TIMER500_MESSAGE } message_type;
typedef struct {
    message_type type;
    TickType_t timeElapsed;
    long distance;
} SensorMessage;

//QueueHandle_t sensor_queue; //.c

void init_sensor_queue();

void push_sensor_msg(SensorMessage *msgptr);
void pop_sensor_msg(SensorMessage *msgptr);

#endif
