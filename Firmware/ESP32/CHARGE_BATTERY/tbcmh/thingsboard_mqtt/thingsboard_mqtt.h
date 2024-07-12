#ifndef _THINGSBOARD_MQTT_H
#define _THINGSBOARD_MQTT_H


#define ACCESS_TOKEN            "rhnr36ad0v00djzbc9ya"
#define URI                     "mqtt://thingsboard.cloud"

typedef struct 
{
    char *title_Telemetry;
    int32_t data_Telemetry;
}MQTT_Telemetry_Data_t;

void MQTT_init(void);

void MQTT_post(MQTT_Telemetry_Data_t *Post_Data);

#endif