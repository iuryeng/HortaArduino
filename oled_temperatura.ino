//===================================================================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Interface dysplay oled informando a temperatura captada com o sensor digital DS18B20 
//===================================================================================


//importe a biblioteca necessária
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//defina o pino de leitura do sensor
#define DS18B20 8

//crie um objeto display com Adafruit_SSD1306
Adafruit_SSD1306 display = Adafruit_SSD1306();  

//intancie ourwire para se comunicar com o sensor DS18B20
OneWire sensor(DS18B20);

//passe o valor fornecido para dallastemperature
DallasTemperature sensor_temp(&sensor);


void setup(){
  //defina a velocidade de comunicação com o monitor serial em 9800
  Serial.begin(9800);
  
  //inicialize a leitura do display oled
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  
  //inicialize a leitura do sensor DS18B20
  sensor_temp.begin();
}

void loop(){

  //capture o valor fornecido pelo sensor
  sensor_temp.requestTemperatures();
  
  // declare a variavel temperatura para guardar o valor lido pelo sensor
  float  temperatura = sensor_temp.getTempCByIndex(0); 
  
  //Descomente e imprima o valor capturado para o monitor serial para testar a captura do valor fornecido pelo sensor
  //Serial.println(sensor_temp.getTempCByIndex(0));
  
  //desenhe um comando visivel no display
  display.display();
  
  //limpe o display
  display.clearDisplay();
  
  //sete o tamanho do texto
  display.setTextSize(3);
  
  // sete a cor branca para o texto
  display.setTextColor(WHITE);
  
  // posicione o cursos no centro 
  display.setCursor(37,10);
  
  //imprima o valor da temperatura no display 
  display.print(temperatura);

  //aguarde meio segundo
  delay(500);
  
}
