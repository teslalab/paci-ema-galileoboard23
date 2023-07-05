# Mediciones Ambientales con GalIoT Board
## PACI - Electrónica y Medio Ambiente - 2023
 ![Background](img/galiot_board-2.png)
## Instalación de la Tarjeta GALIoT Board

Para la instalación en Arduino IDE debemos seguir los siguientes pasos:

1. Abrir ARDUINO IDE
2. Debemos ir a la pestaña ***Archivo***->***Preferencias***.
	- En la pestaña ***Ajustes*** buscamos la opción: ***Gestor de URLs Adicionales de Tarjetas: ***
	- Pegamos la siguiente URL: `https://dl.espressif.com/dl/package_esp32_index.json`
	- Luego presionamos la opción ***OK*** y automáticamente se cerrará la ventana.
3. Debemos ir a la pestaña ***Herramientas***->***Placa***->***Gestor de tarjetas***.
	- Colocamos en la barra de búsqueda ***ESP32***.
	- Seleccionamos la opción que nos muestre ***NodeMCU-32S***.
	- Instalamos y luego presionamos la opción de ***Cerrar***.

Con esto tendremos completa la instalación de nuestra tarjeta ESP32 y lista para ser programada.	 

## Instalación USB Driver ***(Si no reconoce el puerto COM)***

En algunos casos nuestra PC no es capaz de reconocer el dispositivo USB que nosotros conectamos, es por ello que dejaremos un archivo para la instalación del driver con ello nuestra PC deberá ser capaz de reconocer el dispositivo conectado, en caso de que el problema persista asegúrese de que su dispositivo no se este sobre calentando.

[Descarga este driver para Windows][DRIVER_USB]

[DRIVER_USB]: https://www.arduined.eu/files/windows10/CH341SER.zip

1. Descomprimir el archivo ZIP descargado 
2. Seleccionar el archivo para instalación de Windows
	- SETUP.exe
3. Seleccionar CH341SER.INF
4. Click en la opción ***Install***
5. Cuando este instalado cerrar la ventana y listo.!

Con esto estaría lista la instalación del Driver USB para nuestra tarjeta en el Sistema Operativo Windows.

Puede seguir está guía para la instalación como una segunda opción 

[Sigue la guía para instalar el driver CH340][DRIVER_CH340]

[DRIVER_CH340]: https://www.arduined.eu/ch340-windows-10-driver-download/

## Instalación de librerias 

1. Sketch
2. Incluir libreria
3. Gestionar Bibliotecas 

### Librerias a instalar 
1. Adafruit IO Arduino *** de Adafruit ***
![Adafruit IO Libreria](img/AdaIOLib.png)
2. Adafruit BME680 	*** de Adafruit ***
![Adafruit BME680 Libreria](img/AdaBMElib.png)

## Código Base 

1. El código base de que se le brinda le permite realizar interacción con la tarjeta.

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
