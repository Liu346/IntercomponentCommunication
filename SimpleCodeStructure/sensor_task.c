#include "sensor_task.h"
#include "uart_thread_queue.h"
#include "timer500.h"
#include "timer70.h"
#include "sensor_thread_state.h"
#include <stdio.h>
#define INIT_AVERAGE 0
#define UPDATE_AVERAGE 1
void * sensorTask(void *arg0)
{
    // Initialize Timers
    timer70Init();
    timer500Init();

    sensorThreadState();

}
