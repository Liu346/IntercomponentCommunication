#include "timer500.h"


void timer500Init(){
    Timer_Handle timer500;
    Timer_Params params;

    /* Call driver init functions */
    GPIO_init();
    Timer_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_1, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn off user LED */
    GPIO_write(CONFIG_GPIO_LED_1, CONFIG_GPIO_LED_OFF);

    /*
     * Setting up the timer in continuous callback mode
     */
    Timer_Params_init(&params);
    params.period = 500000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timer500Callback;

    timer500 = Timer_open(CONFIG_TIMER_1, &params);

    if (timer500 == NULL) {
        /* Failed to initialized timer */
        fatalError(T500_ERROR_EVENT);
        while (1) {}
    }

    if (Timer_start(timer500) == Timer_STATUS_ERROR) {
        /* Failed to start timer */
        fatalError(T500_ERROR_EVENT);
        while (1) {}
    }

}

void timer500Callback(Timer_Handle myHandle, int_fast16_t status){
    dbgEvent(T500_ISR_BEGIN);
    SensorMessage msg;
    msg.type = TIMER500_MESSAGE;
    dbgEvent(T500_BEFORE_QUEUE_SEND_ISR);
    push_sensor_msg(&msg);
    //call funtion to grab ticks
    dbgEvent(T500_AFTER_QUEUE_SEND_ISR);
    dbgEvent(T500_ISR_END);

}
