#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "thingsboard_mqtt.h"

#include "esp_log.h"
#include "esp_err.h"
#include "esp_wifi.h"
#include "rom/ets_sys.h"

#include "wifi.h"
#include "nvs_rw.h" 
#include "mqtt_client_tcp.h"
#include "tbc_mqtt_helper.h"


tbcmh_handle_t client;
tbc_transport_config_esay_t config = 
{
    .uri = URI,                     /*!< Complete ThingsBoard MQTT broker URI */
    .access_token = ACCESS_TOKEN,   /*!< ThingsBoard Access Token */
    .log_rxtx_package = true                /*!< print Rx/Tx MQTT package */
};

static void MQTT_Connected_Handle(tbcmh_handle_t client, void *context)
{
    printf("CONNECTED\n");
}

static void MQTT_Disconnected_Handle(tbcmh_handle_t client, void *context)
{
    printf("DISCONNECTED\n");
}

tbcmh_value_t *MQTT_getData_lux(int32_t te_lux)
{
    cJSON *lux = cJSON_CreateNumber(te_lux);
    return lux;
}

static void MQTT_sendTelemetry(tbcmh_handle_t client, MQTT_Telemetry_Data_t *Post_Data)
{

    cJSON *object = cJSON_CreateObject();
    cJSON_AddItemToObject(object, Post_Data->title_Telemetry, MQTT_getData_lux(Post_Data->data_Telemetry));
    tbcmh_telemetry_upload_ex(client, object, 1/*qos*/, 0/*retain*/);
    cJSON_Delete(object);
}

void MQTT_init(void)
{
    client = tbcmh_init();
    MQTT_Connect_URL(client, &config, NULL, MQTT_Connected_Handle, MQTT_Disconnected_Handle);
}

void MQTT_post(MQTT_Telemetry_Data_t *Post_Data)
{
    if (MQTT_Events(client)) MQTT_Continue(client);
    if (MQTT_Connected(client)) MQTT_sendTelemetry(client, Post_Data);  
}

