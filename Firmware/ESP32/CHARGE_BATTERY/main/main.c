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
#include "http_client_request.h"

static const char *TAG = "main";

static TaskHandle_t wifiScan_task;
uint8_t rec;
#define EXAMPLE_ESP_WIFI_SSID      "WIFI TANG 3.01 2.4G"
#define EXAMPLE_ESP_WIFI_PASS      "888888883"



static void startWifiScan(void *arg)
{
    while (1)
    {

        uint8_t ssid1[] = "tran hoang kien";
        uint8_t password1[] = "888888883";
        uint8_t ssid2[] = "kien2211736";
        uint8_t password2[] = "123456";
        uint8_t ssid3[] = "hell0 world";
        uint8_t password3[] = "20040502";
         uint8_t ssid4[] = "wifi thay the";
        uint8_t password4[] = "11111111";
        // char networks[100];
        // uint8_t numNetworks = WIFI_Scan(networks);
        // ESP_LOGI(TAG, "So luong Wifi:  %d\n",numNetworks);
        // vTaskDelay(100 / portTICK_PERIOD_MS);
        // WIFI_Status_t connectionStatus = WIFI_Connect(ssid, password);
        // if (connectionStatus == CONNECT_OK) {
        //     ESP_LOGI(TAG, "\tConnected\n");
        // }

        WIFI_StoreNVS(ssid1, password1);
        WIFI_StoreNVS(ssid2, password2);
        WIFI_StoreNVS(ssid3, password3);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        
        int8_t networkIndex = WIFI_ScanNVS(ssid3, password3);
        if (networkIndex != -1) {
            ESP_LOGI(TAG, "\ttim mk thay roi nha:))) \n");
            ESP_LOGI(TAG, "So luong Wifi duoc luu vao NVS:  %d\n",networkIndex);
        } else {
            ESP_LOGI(TAG, "\tNOT FOUND\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);



        int8_t status_dele = WIFI_DeleteNVS (ssid2);
           if (status_dele != -1) {
            ESP_LOGI(TAG, "Taof lao aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa:  %d\n",networkIndex);
        } else {
            ESP_LOGI(TAG, "\tNOT FOUND\n");
        }
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        WIFI_ScanNVS(ssid3, password3);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        WIFI_StoreNVS(ssid4, password4);
        WIFI_ScanNVS(ssid4, password4);
        ESP_LOGI(TAG, "\tDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA XONGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);


//         //  connectionStatus = WIFI_state_connect();
//         // if (connectionStatus == CONNECT_OK) {
//         //     ESP_LOGI(TAG, "\tDANG KET NOI\n");
//         // } else {
//         //     ESP_LOGI(TAG, "\tNGAT KET NOI\n");
//         // }
//         vTaskDelay(500 / portTICK_PERIOD_MS);
//         ESP_LOGI(TAG, "\tDAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA XONGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG RRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
//         vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}


void app_main(void)
{
    NVS_Init();
    WIFI_StaInit();

    xTaskCreate(startWifiScan,
                "Wifi scan",
                1024 * 40,
                NULL,
                3,
                &wifiScan_task);



//    uint8_t ssid[] = "WIFI TANG 3.01 2.4G";
//     uint8_t password[] = "888888883";
//     WIFI_Status_t connectionStatus = WIFI_Connect(ssid, password);
//     if (connectionStatus == CONNECT_OK) {
//         ESP_LOGI(TAG, "\tConnected\n");
//     } else {
//         ESP_LOGI(TAG, "\tDisconnected\n");
//     }
//     vTaskDelay(500 / portTICK_PERIOD_MS);
    
   
    //     uint8_t ssid[] = "WIFI TANG 3.01 2.4G";
    // uint8_t password[32];
    // int8_t networkIndex = WIFI_ScanNVS(ssid, password);
    // if (networkIndex != -1) {
    //     ESP_LOGI(TAG, "\ttim thay roi nha:)))\n");
    // } else {
    //     ESP_LOGI(TAG, "\tNOT FOUND\n");
    // }



    // WIFI_Status_t connectionStatus = WIFI_state_connect();
    // if (connectionStatus == WIFI_CONNECTED) {
    //     ESP_LOGI(TAG, "\tDANG KET NOI\n");
    // } else {
    //     ESP_LOGI(TAG, "\tNGAT KET NOI\n");
    // }

}
