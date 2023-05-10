#include "config.h"

/************************ Example Starts Here *******************************/
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BME680.h"
#include <Wire.h>

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME680 bme; // I2C
// pin connected to DH22 data line
#define DATA_PIN 2

// create DHT22 instance
DHT_Unified dht(DATA_PIN, DHT22);

// set up the 'temperature' and 'humidity' feeds
AdafruitIO_Feed *temperatura = io.feed("temp");
AdafruitIO_Feed *humedad = io.feed("hume");
AdafruitIO_Feed *gases = io.feed("gases");
void setup() {

  // start the serial connection
  Serial.begin(115200);

  // wait for serial monitor to open
  while(! Serial);

  // initialize dht22
  dht.begin();

  // connect to io.adafruit.com
  Serial.print("Connecting to Adafruit IO");
  io.connect();

  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  // we are connected
  Serial.println();
  Serial.println(io.statusText());

    while (!Serial);
  Serial.println(F("BME680 test"));

  if (!bme.begin()) {
    Serial.println("Could not find a valid BME680 sensor, check wiring!");
    while (1);
  }

  // Set up oversampling and filter initialization
  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
  bme.setGasHeater(320, 150); // 320*C for 150 ms

}

void loop() {
 if (! bme.performReading()) {
    Serial.println("Failed to perform reading :(");
    return;
  }
  // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  Serial.print(bme.temperature);
  io.run();

  //sensors_event_t event;
  //dht.temperature().getEvent(&event);

  Serial.print("Temperatura: ");
  Serial.print(bme.temperature);
  Serial.println("C");
  // save fahrenheit (or celsius) to Adafruit IO
  temperatura->save(bme.temperature);

  //dht.humidity().getEvent(&event);

  Serial.print("Humedad: ");
  Serial.print(bme.humidity);
  Serial.println("%");

  
  Serial.print("Gases: ");
  Serial.print(bme.gas_resistance / 1000.0);
  Serial.println("F");

  // save humidity to Adafruit IO
  humedad->save(bme.temperature);

  // wait 5 seconds (5000 milliseconds == 5 seconds)
  delay(5000);

}
