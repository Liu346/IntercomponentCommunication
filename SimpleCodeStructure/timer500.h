#ifndef TIMER500_HEADER
#define TIMER500_HEADER



#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>

/* Board Header file */
#include "ti_drivers_config.h"

/* Queues */
#include "sensor_thread_queue.h"

#include "debug.h"

/* Callback used for toggling the LED. */
void timer500Callback(Timer_Handle myHandle, int_fast16_t status);
/* set up */
void timer500Init();

#endif
