//***************************************************************************************************************
// Universidad del Valle de Guatemala 
// BE3015 - Electrónica Digital 2
// Jeremy Mejía 
// Proyecto 3
// Arduino
// Carné: 19846
//***************************************************************************************************************

//***************************************************************************************************************
// Librerías
//***************************************************************************************************************

#include <Arduino.h>
#include <Adafruit_AHT10.h>


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

//***************************************************************************************************************
// Definición de Pines
//***************************************************************************************************************
Adafruit_AHT10 aht;
#define PIN 27
#define NUMPIXELS 1 // Popular NeoPixel ring size
#define NUMPIXELS 2
#define NUMPIXELS 3
#define NUMPIXELS 4
#define NUMPIXELS 5
#define NUMPIXELS 6
#define NUMPIXELS 7
#define NUMPIXELS 8
#define NUMPIXELS 9
#define NUMPIXELS 10
#define NUMPIXELS 11
#define NUMPIXELS 12
#define NUMPIXELS 13
#define NUMPIXELS 14
#define NUMPIXELS 15
#define NUMPIXELS 16

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************



//***************************************************************************************************************
// Variables Globales
//***************************************************************************************************************
int voltaje; 
int adcRaw;
int valor = 0;


//***************************************************************************************************************
// Configuración
//***************************************************************************************************************


void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);

  Serial.println("Adafruit AHT10 demo!");

  if (! aht.begin()) {
    Serial.println("Could not find AHT10? Check wiring");
    while (1) delay(10);
  }
  Serial.println("AHT10 found");

  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  
}

//***************************************************************************************************************
// Loop Principal
//***************************************************************************************************************

void loop() {
  
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  voltaje = humidity.relative_humidity;
  
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
  Serial.println("-------------------------------------------------------");
  pixels.clear();

  if(Serial2.available() > 0){
    valor = Serial2.read(); 
 
  }
  Serial.println(valor); 

  if (valor == 0){
    pixels.setPixelColor(1, pixels.Color(0, 150, 0));
    pixels.setPixelColor(2, pixels.Color(0, 150, 0));
    pixels.setPixelColor(3, pixels.Color(0, 150, 0));
    pixels.setPixelColor(4, pixels.Color(0, 150, 0));
    pixels.setPixelColor(5, pixels.Color(0, 150, 0));
    pixels.setPixelColor(6, pixels.Color(0, 150, 0));
    pixels.setPixelColor(7, pixels.Color(0, 150, 0));
    pixels.setPixelColor(8, pixels.Color(0, 150, 0));
    pixels.setPixelColor(9, pixels.Color(0, 150, 0));
    pixels.setPixelColor(10, pixels.Color(0, 150, 0));
    pixels.setPixelColor(11, pixels.Color(0, 150, 0));
    pixels.setPixelColor(12, pixels.Color(0, 150, 0));
    pixels.setPixelColor(13, pixels.Color(0, 150, 0));
    pixels.setPixelColor(14, pixels.Color(0, 150, 0));
    pixels.setPixelColor(15, pixels.Color(0, 150, 0));
    pixels.setPixelColor(16, pixels.Color(0, 150, 0));
  }
  if (valor == 1){
    pixels.setPixelColor(1, pixels.Color(150, 0, 0));
    pixels.setPixelColor(2, pixels.Color(150, 0, 0));
    pixels.setPixelColor(3, pixels.Color(150, 0, 0));
    pixels.setPixelColor(4, pixels.Color(150, 0, 0));
    pixels.setPixelColor(5, pixels.Color(150, 0, 0));
    pixels.setPixelColor(6, pixels.Color(150, 0, 0));
    pixels.setPixelColor(7, pixels.Color(150, 0, 0));
    pixels.setPixelColor(8, pixels.Color(150, 0, 0));
    pixels.setPixelColor(9, pixels.Color(150, 0, 0));
    pixels.setPixelColor(10, pixels.Color(150, 0, 0));
    pixels.setPixelColor(11, pixels.Color(150, 0, 0));
    pixels.setPixelColor(12, pixels.Color(150, 0, 0));
    pixels.setPixelColor(13, pixels.Color(150, 0, 0));
    pixels.setPixelColor(14, pixels.Color(150, 0, 0));
    pixels.setPixelColor(15, pixels.Color(150, 0, 0));
    pixels.setPixelColor(16, pixels.Color(150, 0, 0));
  }
  if (valor == 2){
    pixels.setPixelColor(1, pixels.Color(0, 0, 150));
    pixels.setPixelColor(2, pixels.Color(0, 0, 150));
    pixels.setPixelColor(3, pixels.Color(0, 0, 150));
    pixels.setPixelColor(4, pixels.Color(0, 0, 150));
    pixels.setPixelColor(5, pixels.Color(0, 0, 150));
    pixels.setPixelColor(6, pixels.Color(0, 0, 150));
    pixels.setPixelColor(7, pixels.Color(0, 0, 150));
    pixels.setPixelColor(8, pixels.Color(0, 0, 150));
    pixels.setPixelColor(9, pixels.Color(0, 0, 150));
    pixels.setPixelColor(10, pixels.Color(0, 0, 150));
    pixels.setPixelColor(11, pixels.Color(0, 0, 150));
    pixels.setPixelColor(12, pixels.Color(0, 0, 150));
    pixels.setPixelColor(13, pixels.Color(0, 0, 150));
    pixels.setPixelColor(14, pixels.Color(0, 0, 150));
    pixels.setPixelColor(15, pixels.Color(0, 0, 150));
    pixels.setPixelColor(16, pixels.Color(0, 0, 150));
  }
  //pixels.setPixelColor(16, pixels.Color(0, 150, 0));
  pixels.show();
 
  Serial2.write(voltaje); 
  

  delay(500);

}
