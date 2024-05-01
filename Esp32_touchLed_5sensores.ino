//Librerias para gestión de energia
#include "WiFi.h"
#include <esp_sleep.h>
//Pines Touch
#define PIN_TOUCH_1 4
#define PIN_TOUCH_4 15
#define PIN_TOUCH_7 14
#define PIN_TOUCH_9 33  
#define PIN_TOUCH_10 32 

#define RANGOTACTIL 50//rango tactil
#define PIN_LED 2 //Pin led interno

//Definición de librerias para los neo pixels.
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif

//Definición de pin de salida de los neopixels.
#define PIN         22
//Definición de número de pixels
#define NUMPIXELS   20
//Definición tiempo.


//Defición Variables color, brillo.
int brillo=255; 

int red1,green1,blue1,red2,green2,blue2,red3,green3,blue3;

int contadorSwitch=0;

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//Fuciones para prender leds
void apagar(){
    digitalWrite(PIN_LED,LOW);
    pixels.clear();
    pixels.show();
    
}

//Incertar funcion arcoiris


void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
clock_prescale_set(clock_div_1);
#endif
  
pixels.begin(); 
Serial.begin(115200);
pixels.setBrightness(brillo);
pixels.show();

pinMode(PIN, OUTPUT);
pinMode(PIN_LED, OUTPUT);

// Sleep touch pin as input pullup (modified)
//pinMode(PIN_TOUCH_10, INPUT_PULLUP); // Wakeup touch pin as input pullup (modified)

// Apagar WiFi and Bluetooth por medio de gestión de energia.
Serial.println("Stopping Both WiFi and Bluetooth");
WiFi.mode(WIFI_OFF);
btStop();
delay(100);
}


void loop() {
//Inicia el loop apagando los leds.  
pixels.setBrightness(brillo);

long valorSensor_1 = touchRead(PIN_TOUCH_1);//Cable verde
long valorSensor_4 = touchRead(PIN_TOUCH_4);//Cable verde
long valorSensor_7 = touchRead(PIN_TOUCH_7);//Pack rojo claro
long valorSensor_9 = touchRead(PIN_TOUCH_9);//Amarillo 
//long valorSensor_10= touchRead(PIN_TOUCH_10);//Rojo 

/*
Serial.print("Valor Rango Tactil: ");
Serial.println(RANGOTACTIL);
*/
    Serial.print("1 Cuerda :  ");
    Serial.println(valorSensor_7);
//111111111111111
if (valorSensor_1 < RANGOTACTIL) {
    Serial.print("Sensor 1 :");
    Serial.println(valorSensor_1);
    digitalWrite(PIN_LED, HIGH);
    contadorSwitch++;
    brillo=255;
    switch (contadorSwitch){
      case 1://Colores Blanco
        Serial.print("Valor brillo: ");
        Serial.println(brillo);
        delay(300);
       //1 cuerda
        red1 =135;
        green1=206;
        blue1=255;       
       //2 cuerda       
        red2 =255;
        green2=30;
        blue2=30;        
       //3 cuerda
        red3 =255;
        green3=0;
        blue3=200;
        
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(90);
        pixels.show();
        }
        delay(300);
        apagar();
        break;

      case 2://Colores Rojos
        brillo=255;
        Serial.print("Valor brillo: ");
        Serial.println(brillo);
        //1 cuerda
        red1 =255;
        green1=50;
        blue1=0;
        //2 cuerda        
        red2 =255;
        green2=0;
        blue2=0;
        //3 cuerda        
        red3 =206;
        green3=150;
        blue3=0;
              
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;
        
      case 3://color Verde
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1 cuerda        
        red1 =50;
        green1=255;
        blue1=50;
        //2 cuerda
        red2 =0;
        green2=255;
        blue2=0;
        //3 cuerda
        red3 =2000;
        green3=255;
        blue3=50;
        
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);     
        apagar();
        break;

      case 4://Color Azul
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1 cuerda
        red1 =50;
        green1=50;
        blue1=255;
        // 2 cuerda
        red2 =0;
        green2=0;
        blue2=255;
        //3 cuerda
        red3 =150;
        green3=0;
        blue3=225;
        
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;

      case 5://color amarillo
        Serial.print("Valor brillo: ");
        Serial.println(brillo);      
        // 1 cuerda
        red1 =206;
        green1=206;
        blue1=0;
        // 2 cuerda
        red2 =45;
        green2=75;
        blue2=0;
        //3 cuerda
        red3 =150;
        green3=26;
        blue3=25;
                
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;

      case 6://Color Rosado
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1cuerda
        red1 =255;
        green1=05;
        blue1=255;
        //2 cuerda
        red2 =80;
        green2=25;
        blue2=210;
        //3 cuerda
        red3 =25;
        green3=255;
        blue3=50;
                
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;
      case 7://Color turquesa
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1 
        red1 =0;
        green1=255;
        blue1=255;
        //2 
        red2 =95;
        green2=75;
        blue2=255;
        // 3
        red3 =150;
        green3=30;
        blue3=255;
                
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;
      case 8://Color Al azar
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1 
        red1 =random(0,255);
        green1=random(0,255);
        blue1=random(0,255);
        //2 
        red2 =random(0,255);
        green2=random(0,255);
        blue2=random(0,255);
        // 3
        red3 =random(0,255);
        green3=random(0,255);
        blue3=random(0,255);
                
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;
        



      case 9://Sin color
        Serial.print("Valor brillo: ");
        Serial.println(brillo);        
        //1 
        red1 =0;
        green1=0;
        blue1=0;
        //2 
        red2 =0;
        green2=0;
        blue2=0;
        // 3
        red3 =0;
        green3=0;
        blue3=0;
                
        for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i, pixels.Color(red1,green1,blue1));
        delay(10);
        pixels.show();
        }
        delay(300);
        apagar();
        break;



      
      default:
        contadorSwitch=0;
        Serial.print("Valor brillo: ");
        Serial.println(brillo);      
        delay(100);
      break;

    }
} 

// 222222222222222222222
if (valorSensor_7<57) {
    Serial.print("1 Cuerda :  ");
    Serial.println(valorSensor_7);
    digitalWrite(PIN_LED, HIGH);

    for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i,pixels.Color(red1,green1,blue1));
        pixels.show();
        }
        delay(10);
        apagar();
}

//3333333333333333
if (valorSensor_9+30<RANGOTACTIL) {
    Serial.print("3 cuerda : ");
    Serial.println(valorSensor_9);
    digitalWrite(PIN_LED, HIGH);
   
    for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i,pixels.Color(red2,green2,blue2));
        pixels.show();
        } 
        delay(10);
        apagar();
} 


if (valorSensor_4+30 < RANGOTACTIL) {
    Serial.print("4 Cuerda: ");
    Serial.println(valorSensor_4);
    digitalWrite(PIN_LED, HIGH);
    for(int i=0; i<NUMPIXELS; i++) { 
        pixels.setPixelColor(i,pixels.Color(red3,green3,blue3));
        pixels.show();
        }   
        delay(10);
        apagar();
} 

/*
if (valorSensor_10+30 <RANGOTACTIL) {
    Serial.print("Sensor DM: ");
    Serial.println(valorSensor_10);
    digitalWrite(PIN_LED, HIGH);
    arcoiris();
    delay(500);
}
*/


//FIN
}