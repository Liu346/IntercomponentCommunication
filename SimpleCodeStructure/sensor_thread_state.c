#include "sensor_task.h"
#include "uart_thread_queue.h"
#include "timer500.h"
#include "timer70.h"
#include <stdio.h>

#define INIT_AVERAGE 0
#define UPDATE_AVERAGE 1
void * sensorThreadState(int * i)
{
        static SensorMessage msg;
        static UARTMessage msguart;

        int state = 0;
        int sensorTotal = 0;
        int sensorCount = 0;
        double test = 0.0;
        double toto = 0.0;

        dbgEvent(SENSOR_WHILE);
        //move to task.c
        //make vars static dont need to pass vars
        while(1){

            dbgEvent(SENSOR_BEFORE_QUEUE_RECEIVE);
            pop_sensor_msg(&msg);
            dbgEvent(SENSOR_AFTER_QUEUE_RECEIVE);

            if(state == INIT_AVERAGE){
                sensorTotal = 0;
                sensorCount = 0;
                if(msg.type == TIMER500_MESSAGE){
                    state = UPDATE_AVERAGE;
                }
            }
            else if(state == UPDATE_AVERAGE){
                if(msg.type == TIMER70_MESSAGE){
                    sensorTotal = sensorTotal + msg.distance;
                    sensorCount++;
                    int temp = msg.distance;
                    if(temp >= 22)
                        temp = -1;
                    if(temp == -1)
                        sensorTotal = 0;
                    sprintf(msguart.messagerecived,"Sensor = %i inches                         \n\r",temp);
                }
                else if(msg.type == TIMER500_MESSAGE){
                    int averageVal = sensorTotal/sensorCount;
                    if(sensorCount == 0)
                        averageVal = 0;
                    test = sensorCount * .07;
                    toto = toto + test;
                    //making string

                    msguart.length = snprintf(msguart.messagerecived,MAXUARTSTRINGLENGTH,"Sensor Average = %i inch ; Time = %0.2f sec\n\r",averageVal,toto);
                    //check length too large fatal error
                    //always use snprintf
                    state = INIT_AVERAGE;
                }

            dbgEvent(SENSOR_BEFORE_QUEUE_SEND);
            push_uart_msg(&msguart);
            dbgEvent(SENSOR_AFTER_QUEUE_SEND);
            }
        }
}
