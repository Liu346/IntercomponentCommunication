#ifndef TIMER70_HEADER
#define TIMER70_HEADER


#include <stddef.h>

/* Driver Header files */
#include <ti/drivers/GPIO.h>
#include <ti/drivers/Timer.h>
#include <ti/drivers/ADC.h>

/* Board Header file */
#include "ti_drivers_config.h"

/* Queues */
#include "sensor_thread_queue.h"

#include "debug.h"

/* Callback used for toggling the LED. */
void timer70Callback(Timer_Handle myHandle, int_fast16_t status);
void timer70Init();
float convert_V_to_in(uint32_t V);

#endif
