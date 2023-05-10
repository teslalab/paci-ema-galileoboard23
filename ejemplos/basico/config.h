/************************ Configuración de Adafruit IO *******************************/

// Creamos cuenta en io.adafruit.com,
// Pegamos nuestras credenciales de Adafruit IO .
#define IO_USERNAME  "angelisidro"
#define IO_KEY       "aio_fRlI543XjecwWU2f1K7a7cImp1Xr"

/******************************* WIFI **************************************/
/* Código compatible unicamente con tarjetas de desarrollo de ESP32
Este código contiene las credenciales que utilizara el Router proporcionado especificamente
para este taller */

#define WIFI_SSID "UGMaker" 
#define WIFI_PASS "123456789"
 
#include "AdafruitIO_WiFi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||         \
    defined(ADAFRUIT_PYPORTAL)
// Configure los pines usados para el ESP32 
#if !defined(SPIWIFI_SS) 
#define SPIWIFI SPI
#define SPIWIFI_SS 10 
#define NINA_ACK 9    
#define NINA_RESETN 6 
#define NINA_GPIO0 -1 
#endif
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_SS,
                   NINA_ACK, NINA_RESETN, NINA_GPIO0, &SPIWIFI);
#else
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
#endif
