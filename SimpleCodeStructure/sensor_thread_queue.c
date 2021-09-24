#include "sensor_thread_queue.h"
#define Length 5
static QueueHandle_t sensor_queue = NULL;

void init_sensor_queue(){
    sensor_queue = xQueueCreate(Length,sizeof(SensorMessage));
    if(sensor_queue == NULL){
        fatalError(SENSOR_ERROR_EVENT);
    }
}

//add status checks
void push_sensor_msg(SensorMessage *msgptr){

    BaseType_t queue_status;
    bool isr_status = HwiP_inISR();
    if(isr_status)
        queue_status = xQueueSendFromISR(sensor_queue, msgptr, NULL);
    else
        queue_status = xQueueSend(sensor_queue, msgptr, portMAX_DELAY);

    if(queue_status == pdFALSE)
        fatalError(SENSOR_ERROR_EVENT);
}

void pop_sensor_msg(SensorMessage *msgptr){


    BaseType_t queue_status;
    bool isr_status = HwiP_inISR();
    if(isr_status)
        queue_status = xQueueReceiveFromISR(sensor_queue, msgptr, NULL);
    else
        queue_status = xQueueReceive(sensor_queue, msgptr, portMAX_DELAY);

    if(queue_status == pdFALSE)
        fatalError(SENSOR_ERROR_EVENT);
}
