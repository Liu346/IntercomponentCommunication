#ifndef SENSOR_TASK_HEADER
#define SENSOR_TASK_HEADER

#include <ti/drivers/GPIO.h>
#include "ti_drivers_config.h"
#include "sensor_thread_queue.h"

#include "debug.h"

void * sensorTask(void *arg0);


#endif
