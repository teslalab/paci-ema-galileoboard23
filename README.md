# Mediciones Ambientales con GaLIoT Board
## PACI - Electrónica y Medio Ambiente - 2023
![Background](img/galiot_board-2.png)
## Instalación de la Tarjeta GALIoT Board

Para la instalación en Arduino IDE debemos seguir los siguientes pasos:

1. Abrir ARDUINO IDE
2. Debemos ir a la pestaña ***Archivo***->***Preferencias***.
	- En la pestaña ***Ajustes*** buscamos la opción: ***Gestor de URLs Adicionales de Tarjetas: ***
	- Pegamos la siguiente URL: `https://dl.espressif.com/dl/package_esp32_index.json`
	- Luego presionamos la opción ***OK*** y automáticamente se cerrará la ventana.

    ![Conf ESP32 en Arduino](img/conf-esp32-arduino-1.png)

3. Debemos ir a la pestaña ***Herramientas***->***Placa***->***Gestor de tarjetas***.
	- Colocamos en la barra de búsqueda ***ESP32***.
	- Seleccionamos la opción que nos muestre ***ESP32*** de Expressif.
	- Instalamos y luego presionamos la opción de ***Cerrar***.

   ![Conf ESP32 en Arduino](img/conf-esp32-arduino-2.png)

4. Debemos ir a la pestaña ***Herramientas***->***Placa***->***ESP32 Arduino***.
   	- Seleccionamos la opción que nos muestre ***ESP32 Dev Module*** o ***ESP32 Wrover Module*** de Expressif.
  
    ![Conf ESP32 en Arduino](img/conf-esp32-arduino-3.png)
 	

Con esto tendremos completa la instalación de nuestra tarjeta ESP32 y lista para ser programada.



## Instalación USB Driver ***(Si no reconoce el puerto COM)***

En algunos casos nuestra PC no es capaz de reconocer el dispositivo USB que nosotros conectamos, es por ello que dejaremos un archivo para la instalación del driver con ello nuestra PC deberá ser capaz de reconocer el dispositivo conectado, en caso de que el problema persista asegúrese de que su dispositivo no se este sobre calentando.

[Descarga este driver para Windows][DRIVER_USB]

[DRIVER_USB]: https://cdn.sparkfun.com/assets/learn_tutorials/5/9/7/Windows-CH340-Driver.zip?_gl=1*wudwzh*_ga*MTE0NjMwNzUzNC4xNjgzNjU2NDcz*_ga_T369JS7J9N*MTY4ODUzNjczNi4xLjEuMTY4ODUzNzA4MC4wLjAuMA..

1. Descomprimir el archivo ZIP descargado 
2. Seleccionar el archivo para instalación de Windows
	- SETUP.exe
3. Seleccionar CH341SER.INF
4. Click en la opción ***Install***
5. Cuando este instalado, debemos cerrar la ventana y listo.

Con esto estaría lista la instalación del Driver USB para nuestra tarjeta en el Sistema Operativo Windows.

Puede seguir está guía para la instalación como una segunda opción:

[Sigue la guía para instalar el driver CH340][DRIVER_CH340]

[DRIVER_CH340]: https://learn.sparkfun.com/tutorials/how-to-install-ch340-drivers/windows-710

## Instalación de librerias en Arduino
1. Adafruit IO Arduino *** de Adafruit ***
   
   ![Adafruit IO Libreria](img/instalar-adafruit-io-lib.png)
   
3. Adafruit BME680 	*** de Adafruit ***
   
   ![Adafruit BME680 Libreria](img/instalar-adafruit-bme680-lib.png)

## Código Base 

1. El código base de que se le brinda le permite realizar interacción con la tarjeta.
2. Puedes encontrar varios ejemplos en la carpeta de ejemplos de este github.

## Pinout

### NeoPixels
Nombre | GPIO 
--- | --- 
DATA | 14
VDD | 3V3
VSS | GND

### I2C Connector STEMMA

Nombre | GPIO 
--- | --- 
SCL | 22
SDI | 21
VDD | 3V3
VSS | GND

### Buzzer
Nombre | GPIO 
--- | --- 
DATA | 27
VDD | 3V3
VSS | GND

## Ejemplos básicos

### Pruebas con sensor BME680
Utilice el código de ejemplo con nombre ***galiot_board-bme680test*** y podrá tener una interacción con el Sensor BME680 despegando algunas variables ambientales.
   
   ![BME680Test](img/ejemplo_bme680_test.png)
   
