/*
 * debug.c
 *
 *  Created on: Sep 8, 2021
 *      Author: Jimmy McAvoy
 */

#include "debug.h"

void dbgInit(){

    // Initialize GPIO
    GPIO_init();

    GPIO_setConfig(CONFIG_GPIO_LED_0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    // Configure Pin Outputs
    GPIO_setConfig(GPIO_0_P03, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_1_P05, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_2_P06, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_3_P07, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_4_P08, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_5_P18, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_6_P21, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    GPIO_setConfig(GPIO_7_P50, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);

    return;
}


void dbgEvent(unsigned int event)
{

    if(event > 127){
        fatalError(event);
    }

    bool eventBits[7];

    int i;
    for (i = 0;  i < 7;  ++i){
        eventBits[i] = 0 != (event & (1 << i));
    }

    // Toggle MSB High While Writing
    GPIO_write(GPIO_7_P50, 1);

    GPIO_write(GPIO_0_P03, eventBits[0]);
    GPIO_write(GPIO_1_P05, eventBits[1]);
    GPIO_write(GPIO_2_P06, eventBits[2]);
    GPIO_write(GPIO_3_P07, eventBits[3]);
    GPIO_write(GPIO_4_P08, eventBits[4]);
    GPIO_write(GPIO_5_P18, eventBits[5]);
    GPIO_write(GPIO_6_P21, eventBits[6]);

    // Toggle MSB Low When Finished
    GPIO_write(GPIO_7_P50, 0);

}

void fatalError(unsigned int eventFailure){

    const TickType_t xDelay = 500 / portTICK_PERIOD_MS;

    unsigned int errorCode = eventFailure - 127;

    bool errorBits[8];

    int i;
    for (i = 0;  i < 8;  ++i){
        errorBits[i] = 0 != (errorCode & (1 << i));
    }

    // 8 Bit Error Code
    GPIO_write(GPIO_0_P03, errorBits[0]);
    GPIO_write(GPIO_1_P05, errorBits[1]);
    GPIO_write(GPIO_2_P06, errorBits[2]);
    GPIO_write(GPIO_3_P07, errorBits[3]);
    GPIO_write(GPIO_4_P08, errorBits[4]);
    GPIO_write(GPIO_5_P18, errorBits[5]);
    GPIO_write(GPIO_6_P21, errorBits[6]);
    GPIO_write(GPIO_7_P50, errorBits[7]);

    // Turn error LED on
    GPIO_write(CONFIG_GPIO_LED_0, 1);

    // End tasks
    vTaskSuspendAll();

    // Disable interrupts
    taskENTER_CRITICAL();

    // Blink red LED
    while(1){
        GPIO_toggle(CONFIG_GPIO_LED_0);
        vTaskDelay(xDelay);
    }

}

