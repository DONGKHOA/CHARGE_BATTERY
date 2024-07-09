#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "freertos/queue.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_wifi.h"
#include "rom/ets_sys.h"

#include "wifi.h"
#include "gpio.h"
#include "nvs_rw.h" 
#include "uart_driver.h"
#include "mqtt_client_tcp.h"
#include "tbcmh_helper.h"

uint8_t ssid3[] = "WIFI TANG 3.01 2.4G";
uint8_t password3[] = "888888883";
MQTT_Telemetry_Data_t post_data =
{
    "trankien12345",
    35.2
};

static void mqtt_main(void *arg)
{
    MQTT_init();   
    while(1) 
    {
        PostData_Thingsboard(&post_data);
    }
}

void app_main(void)
{
    NVS_Init();
    WIFI_StaInit();
    WIFI_Connect(ssid3, password3);
    printf("init service in main\n");


    xTaskCreate(mqtt_main, "mqtt_maintask", 1024*10, NULL, 11, NULL);
}
