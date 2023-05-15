#include "config.h"

/************************ Librerias *******************************/
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <Wire.h>
#include "Adafruit_NeoPixel.h"

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C

// Feeds utilizados para este ejemplo
AdafruitIO_Feed *temperatura = io.feed("temp");
AdafruitIO_Feed *humedad = io.feed("hume");
AdafruitIO_Feed *gases = io.feed("gases");


// Neopixels
#define PIXEL_PIN     14
#define PIXEL_COUNT   6
#define PIXEL_TYPE    NEO_GRB + NEO_KHZ800
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
AdafruitIO_Feed *color = io.feed("color");

void setup() {

  Serial.begin(115200);
  while(! Serial);

  // Conexión io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println(io.statusText());

    while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // configuración del set del BME680
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms
  
  color->onMessage(handleMessage);
    // neopixel init
  pixels.begin();
  pixels.show();

}

void loop() {
 if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }

  Serial.print(bme.temperature);
  io.run();

  Serial.print("Temperatura: ");
  Serial.print(bme.temperature);
  Serial.println("C");

  temperatura->save(bme.temperature);

  Serial.print("Humedad: ");
  Serial.print(bme.humidity);
  Serial.println("%");

  
  Serial.print("Gases: ");
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println("K Ohms");
  humedad->save(bme.temperature);
  gases->save(bme.gas_resistance / 1000.0);

  delay(10000);

}

void handleMessage(AdafruitIO_Data *data) {

  // print RGB values and hex value
  Serial.println("Received HEX: ");
  Serial.println(data->value());

  long color = data->toNeoPixel();

  for(int i=0; i<PIXEL_COUNT; ++i) {
    pixels.setPixelColor(i, color);
  }

  pixels.show();

}
