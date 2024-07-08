#ifndef _THINGSBOARD_MQTT_H
#define _THINGSBOARD_MQTT_H


#define TELEMETRY_LUX         	"Temperature"
#define ACCESS_TOKEN            "rhnr36ad0v00djzbc9ya"
#define URI                     "mqtt://thingsboard.cloud"

void MQTT_init(void);

void PostData_Thingsboard(void);

#endif