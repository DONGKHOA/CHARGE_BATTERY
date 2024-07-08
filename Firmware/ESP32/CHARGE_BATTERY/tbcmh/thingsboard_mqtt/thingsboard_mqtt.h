#ifndef _THINGSBOARD_MQTT_H
#define _THINGSBOARD_MQTT_H


#define TELEMETRY_LUX         	"Temperature"
#define ACCESS_TOKEN            "rhnr36ad0v00djzbc9ya"
#define URI                     "mqtt://thingsboard.cloud"

typedef struct 
{
    char *telemetry;
    int32_t data_telemetry;
}MQTT_Telemetry_Data_t;

void MQTT_init(void);

void PostData_Thingsboard(MQTT_Telemetry_Data_t *Post_Data);

#endif