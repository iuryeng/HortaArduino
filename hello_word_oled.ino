//===============================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Hello word tela de oled
//===============================================
//Ligação dos terminais do sensor no arduino
//SCK_PIN --- A5  
//SDA_PIN --- A4
//===============================================

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(); 

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop(){
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Smart Garden");
  display.display();
  delay(1000); 
  display.clearDisplay(); 
  display.setCursor(37,10); 
  display.print("ECIT Prata");
  display.display();
  delay(1000); 
  display.clearDisplay(); 
  display.setCursor(37,10); 
  display.print("Extensao IFPB");
  display.display();
  delay(1000);
}
