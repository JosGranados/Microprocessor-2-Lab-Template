#include <stdio.h>
#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "esp_system.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include "lwip/netdb.h"
#include "lwip/api.h"

#include "driver/gpio.h"
#include "rom/gpio.h"
#include "hal/gpio_ll.h"



//ONBOARD LED
#define BLINK_GPIO 2 // Onboard LED

//HTML HEADERS
const static char http_html_hdr[] = "HTTP/1.1 200 OK\r\nContent-type: text/html\r\n\r\n";
const static char http_html_txt[] = "HTTP/1.1 200 OK\r\nContent-type: text/plain\r\n\r\n";
const static char http_index_hml[] = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta charset=UTF-8 name="viewport" content="width = device-width initial-scale = 1.0">
    <title>Home Page</title>
</head>

<body>
    <div class="header">
        <h1>Jose Granados</h1>
    </div> <input class="btn" id="btn0" type="button" value="BTN0" onclick="sendRequest()"> <input class="btn" id="btn1"
        type="button" value="BTN1" onclick="sendRequest1()">
    <div class="JGRANA">
        <p> JGRANADOS3@MINERS.UTEP.EDU </p>
        <div id="sen"></div>
    </div>
    <style>
        * {
            margin: 0;
            padding: 0;
        }

        body {
            background-color: #D4DCE2;
        }

        .header {
            width: 100%;
            height: 55px;
            color: white;
            background-color: #04254D;
            padding: 0;
            text-align: center;
        }

        .header h1 {
            color: white;
            vertical-align: center;
            font-size: 42px;
        }

        .btn {
            margin: 0;
            margin-top: .5%;
            background-color: #FB9541;
            width: 48%;
            border: none;
            color: white;
            padding: 25px 38px;
            text-align: center;
            text-decoration: none;
            font-size: 16px;
        }

        .JGRANA {
            margin: 0;
            margin-top: .5%;
            width: 100%;
            height: 70px;
            color: white;
            background-color: #04254D;
            padding: 0;
            text-align: center;
        }

        .sensorVal p {
            color: white;
            vertical-align: center;
            font-size: 38px;
        }
    </style>
    <script> 
            function sendRequest() { 
                var http = new XMLHttpRequest(); 
                http.onreadystatechange = (() => { 
                    if (http.readyState === 4) { 
                        if (http.status === 200) { 
                            var res = http.responseText; 
                            } 
                        } 
                    }); 
                http.open("GET", "0", true);
http.send(); 
            }
function sendRequest1(){
var http = new XMLHttpRequest();
                http.onreadystatechange = () => { 
                    if (http.readyState === 4) { 
                        if (http.status === 200) { 
                            var res = http.responseText; 
                        } 
                    }
                }; 
                http.open("GET", "1", true); http.send(); 
            }
    </script>
</body>

</html>
)=====";

//SSID, PASS
#define EXAMPLE_ESP_WIFI_SSID "SSID" //Name of the wifi or Hotspot you are connecting to
#define EXAMPLE_ESP_WIFI_PASS "PASSWORD" //password of the wifi


static const char *TAG = "wifi station";

static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                    int32_t event_id, void* event_data)
{

	if(event_id == WIFI_EVENT_STA_START){
		printf("UP and RUNNING\n");
	}

	else if (event_id == WIFI_EVENT_STA_CONNECTED){
		wifi_event_ap_staconnected_t* event = (wifi_event_ap_staconnected_t*) event_data;
		ESP_LOGI(TAG, "station " MACSTR " join, AID=%d", MAC2STR(event->mac), event->aid);
	}
	else if(event_id == WIFI_EVENT_STA_DISCONNECTED){
		wifi_event_ap_stadisconnected_t* event = (wifi_event_ap_stadisconnected_t*) event_data;
		ESP_LOGI(TAG, "station " MACSTR " leave, AID=%d", MAC2STR(event->mac), event->aid);
	}
	else if(event_id == IP_EVENT_STA_GOT_IP){
		printf("IP created    \n\n");
	}
}

void wifi_init_station()
{
	nvs_flash_init(); //initialize NVS
	ESP_ERROR_CHECK(esp_netif_init());
	    ESP_ERROR_CHECK(esp_event_loop_create_default());
	    esp_netif_create_default_wifi_sta();

	    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
	    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

	    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
	                                                        ESP_EVENT_ANY_ID,
	                                                        &wifi_event_handler,
	                                                        NULL,
	                                                        NULL));
    ESP_ERROR_CHECK(esp_wifi_init(&cfg)); //initialize esp_wifi
    //Set wifi as custom SSID, PASS

    esp_event_handler_register(WIFI_EVENT,ESP_EVENT_ANY_ID,wifi_event_handler,NULL);
    esp_event_handler_register(IP_EVENT,IP_EVENT_STA_GOT_IP,wifi_event_handler,NULL);
    wifi_config_t wifi_config = {
                                    .sta = {
                                    .ssid = EXAMPLE_ESP_WIFI_SSID,
                                    .password = EXAMPLE_ESP_WIFI_PASS,
                                    },
                                };
    if (strlen(EXAMPLE_ESP_WIFI_PASS) == 0) {
        wifi_config.ap.authmode = WIFI_AUTH_OPEN; // set authenication as open
    }
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA)); //set wifi as station
    ESP_ERROR_CHECK(esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config)); //set wifi to configuration
    ESP_ERROR_CHECK(esp_wifi_start()); //start wifi
    esp_wifi_connect();
}
static void http_server_netconn_serve(struct netconn *conn)
{
    struct netbuf *inbuf;
    char *buf;
    u16_t buflen;
    err_t err;
    //Set onboard led as output for the led to blink
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    /* Read the data from the port, blocking if nothing yet there.
    We assume the request (the part we care about) is in one netbuf */
    err = netconn_recv(conn, &inbuf);
    if (err == ERR_OK) {
        netbuf_data(inbuf, (void**)&buf, &buflen);
        printf("\nTESTING\n%s\n\n", buf);
        /* Is this an HTTP GET command? (only check the first 5 chars, since
        there are other formats for GET, and we're keeping it very simple )*/
        if (buflen>=5 && buf[0]=='G' && buf[1]=='E' && buf[2]=='T' && buf[3]==' ' && buf[4]=='/' ){

            printf("%c\n", buf[5]);
            /* Send the HTML header
            * subtract 1 from the size, since we dont send the \0 in the string
            * NETCONN_NOCOPY: our data is const static, so no need to copy it
            */
            /*check if the GET /0 for button 0*/
            if(buf[5] == '0'){
                //send anything back
                netconn_write(conn, http_html_txt, sizeof(http_html_txt)-1, NETCONN_NOCOPY);
                netconn_write(conn, "1", 1, NETCONN_NOCOPY);
                gpio_set_level(BLINK_GPIO, 0); //turn off led
            }
            /*check if the GET /1 for button 1*/
            if(buf[5] == '1'){
                //send anything back
                netconn_write(conn, http_html_txt, sizeof(http_html_txt)-1, NETCONN_NOCOPY);
                netconn_write(conn, "1", 1, NETCONN_NOCOPY);
                gpio_set_level(BLINK_GPIO, 1); //turn on led
            }
            else{
                //else send original home page
                netconn_write(conn, http_html_hdr, sizeof(http_html_hdr)-1, NETCONN_NOCOPY);
                netconn_write(conn, http_index_hml, sizeof(http_index_hml)-1, NETCONN_NOCOPY);
            }
        }
    }
    netconn_close(conn); //close connection
    netbuf_delete(inbuf); //delete buffer
}
/* http server */
static void http_server(void *pvParameters){
    struct netconn *conn, *newconn;
    err_t err;
    conn = netconn_new(NETCONN_TCP); //set TCP
    netconn_bind(conn, NULL, 80); // bind to port 80 for local
    netconn_listen(conn); //list to port
    do {
        err = netconn_accept(conn, &newconn); //accept the connection
        if (err == ERR_OK) {
            http_server_netconn_serve(newconn); //run http server
            //netconn_delete(newconn); //delete connection
        }
    } while(err == ERR_OK);
    netconn_close(conn); //close connection
    netconn_delete(conn); //delete connection
}
void app_main()
{
    wifi_init_station(); //set wifi as station
    //create task
    xTaskCreate(&http_server, "http_server", 2048, NULL, 5, NULL);
}
