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

void http_task( void * pvParameters )
{

    for( ;; )
    {
        char *http_data = WIFI_HTTP_Request();
        if (http_data != NULL) 
        {
            // Yêu cầu HTTP thành công, có dữ liệu trả về
            // Bạn có thể sử dụng dữ liệu HTTP ở đây
            printf("Dữ liệu HTTP: %s\n", http_data);
            // Sau khi sử dụng dữ liệu HTTP, hãy giải phóng bộ nhớ đã được cấp phát
            free(http_data);
        } 
        else 
        {
            // Yêu cầu HTTP không thành công hoặc có lỗi
            printf("Yêu cầu HTTP không thành công hoặc có lỗi.\n");

        }
    }
}





void app_main(void)
{
    NVS_Init();
    WIFI_StaInit();
    uint8_t ssid3[] = "WIFI TANG 3.02 2.4G";
    uint8_t password3[] = "888888883";
    WIFI_Status_t connectionStatus = WIFI_Connect(ssid3, password3);
    if (connectionStatus == CONNECT_OK) {
        ESP_LOGI(TAG, "\tConnected\n");
    }

    xTaskCreate(http_task,
                "http",
                1024 * 20,
                NULL,
                3,
                NULL);

}
