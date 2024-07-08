#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "thingsboard_mqtt.h"

// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/timers.h"
// #include "freertos/queue.h"

// #include "esp_system.h"
// #include "esp_event.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_wifi.h"
#include "rom/ets_sys.h"

#include "wifi.h"
// #include "gpio.h"
#include "nvs_rw.h" 
// #include "uart_driver.h"
#include "mqtt_client_tcp.h"
#include "tbc_mqtt_helper.h"


uint32_t te_lux = 10;
tbcmh_handle_t client;
tbc_transport_config_esay_t config = 
{
    .uri = URI,                     /*!< Complete ThingsBoard MQTT broker URI */
    .access_token = ACCESS_TOKEN,   /*!< ThingsBoard Access Token */
    .log_rxtx_package = true                /*!< print Rx/Tx MQTT package */
};

static void tb_on_connected(tbcmh_handle_t client, void *context)
{
    printf("CONNECTED\n");
}

static void tb_on_disconnected(tbcmh_handle_t client, void *context)
{
    printf("DISCONNECTED\n");
}

tbcmh_value_t* te_get_lux(void)
{
    cJSON* lux = cJSON_CreateNumber(te_lux);
    return lux;
}

static void tb_telemetry_send(tbcmh_handle_t client)
{

    cJSON *object = cJSON_CreateObject();
    cJSON_AddItemToObject(object, TELEMETRY_LUX, te_get_lux());
    tbcmh_telemetry_upload_ex(client, object, 1/*qos*/, 0/*retain*/);
    cJSON_Delete(object);
}

void MQTT_init(void)
{
    client = tbcmh_init();
    tbcmh_connect_using_url(client, &config, NULL, tb_on_connected, tb_on_disconnected);
}

void PostData_Thingsboard(void)
{
    if (tbcmh_has_events(client)) tbcmh_run(client);
    if (tbcmh_is_connected(client)) tb_telemetry_send(client);  
}

