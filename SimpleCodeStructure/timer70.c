#include "timer70.h"


void timer70Init(){
    Timer_Handle timer70;
    Timer_Params params;

    /* Call driver init functions */
    GPIO_init();
    Timer_init();

    /* Configure the LED pin */
    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    /* Turn off user LED */
    GPIO_write(CONFIG_GPIO_LED_0, CONFIG_GPIO_LED_OFF);

    /* ADC Init*/
    ADC_init();

    /*
     * Setting up the timer in continuous callback mode
     */
    Timer_Params_init(&params);
    params.period = 70000;
    params.periodUnits = Timer_PERIOD_US;
    params.timerMode = Timer_CONTINUOUS_CALLBACK;
    params.timerCallback = timer70Callback;

    timer70 = Timer_open(CONFIG_TIMER_0, &params);

    if (timer70 == NULL) {
        /* Failed to initialized timer */
        fatalError(T70_ERROR_EVENT);
        while (1) {}
    }

    if (Timer_start(timer70) == Timer_STATUS_ERROR) {
        /* Failed to start timer */
        fatalError(T70_ERROR_EVENT);
        while (1) {}
    }

}

void timer70Callback(Timer_Handle myHandle, int_fast16_t status){
    dbgEvent(T70_ISR_BEGIN);
    uint16_t adcValue0;
    uint32_t adcValue0MicroVolt;
    ADC_Handle   adc;
    ADC_Params  params;
    ADC_Params_init(&params);

    int_fast16_t res;
    /*Get Voltage from ADC */
    adc = ADC_open(CONFIG_ADC_0, &params);

    if (adc == NULL) {
        /* Error Init ADC */
        while (1);
    }

    /* Blocking mode conversion */
    res = ADC_convert(adc, &adcValue0);
    if(adcValue0 >= 2000)
            GPIO_toggle(CONFIG_GPIO_LED_0);


    SensorMessage msg;
    msg.type = TIMER70_MESSAGE;
    msg.distance = convert_V_to_in(adcValue0);
    dbgEvent(T70_BEFORE_QUEUE_SEND_ISR);
    push_sensor_msg(&msg);
    ADC_close(adc);
    dbgEvent(T70_AFTER_QUEUE_SEND_ISR);
    dbgEvent(T70_ISR_END);

}

float convert_V_to_in(uint32_t V){
    float mm;
    mm = 12000/V;
    if(mm > 30 || mm < 4)
        mm = -1;
    return mm;
}
