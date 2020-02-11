//==================================================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Medição da umidade do solo 
//==================================================================

//==================================================================
//Ligação dos terminais do display no arduino e do sensor de umidade
//SCK_PIN --- A5  
//SDA_PIN --- A4
//A0      --- A1
//=================================================================

// inclua as bibliotecas necessárias do dysplay oled
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//inclua as bibliotecas necessárias para leitura sensor de temperatura DS18B20
#include <DallasTemperature.h>
#include <SPI.h>
#include <Wire.h>

// defina o pino de ligação do sensor de umidade do solo
#define   analogico  A1 

// defina o pino D7 como saída para o rele
#define pino_saida  7

// defina o pino D8 como saída para o sensor de temperatura
#define DS18B20 8

// declare a variável global contendo o valor lido do sensor
int valor_lido = 0; 

// declare a variável global contendo o estado do solo
String estado;

// crie um objeto display com Adafruit_SSD1306
Adafruit_SSD1306 display = Adafruit_SSD1306();

//intancie ourwire para se comunicar com o sensor DS18B20
OneWire sensor(DS18B20);

//passe o valor fornecido para dallastemperature
DallasTemperature sensor_temp(&sensor);

//inicialize as definições de hardware
void setup()
{
    //defina a taxa de transmissão de dados como 9600
    Serial.begin(9600);  
    
    //defina o estado do pino analigico A0 como pino de entrada  
    pinMode(analogico,  INPUT);   
    
    //inicialize a leitura do display oled
     display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

    //inicialize o pino do rele como saida 
    pinMode(pino_saida, OUTPUT);

    
   //inicialize a leitura do sensor DS18B20
   sensor_temp.begin();

} 
// inicialize as definiçoes que irão ser tratadas no loop infinito do arduino
void loop()
{
  // declare a variável global sendo o valor lido na porta analogica A0
  valor_lido = analogRead(analogico); 

   //capture o valor fornecido pelo sensor
  sensor_temp.requestTemperatures();
  
  // declare a variavel temperatura para guardar o valor lido pelo sensor
  float  temperatura = sensor_temp.getTempCByIndex(0); 

//===imprima para o usuário o valor do sensor========================= 
  
    //desenhe um comando visivel no display
    display.display();  
    //limpe o display
    display.clearDisplay();  
    //sete o tamanho do texto
    display.setTextSize(1);  
    // sete a cor branca para o texto
    display.setTextColor(WHITE);  
    // posicione o cursos no centro 
    display.setCursor(27,2);  
    //imprima o valor lido no display
    display.print("Umidade:");
    display.print(valor_lido);
    display.setCursor(27,11);
    display.print(estado);
     //imprima o valor da temperatura no display
    display.setCursor(27,22);
    display.print("Temp:");
    display.print(temperatura);
    display.print(" *C");

    display.drawString(40, 22, (String)t+" °C");
    
//===================================================================

//=============Condições para cada nível de umidade==================                                          
  //declare a faixa de valores em que a umidade é total
  if (valor_lido > 0 && valor_lido < 169)             
  {
    estado = "Solo totalmente umido";
  }

  //declare a faixa de valores em que a umidade é média
  else if (valor_lido > 169 && valor_lido < 340)   
  {
    estado = "Solo muito umido"; 
  }
 
  //declare a faixa de valores em que a umidade é mínima
  else if (valor_lido > 340 && valor_lido < 511)  
  {
    estado = "Solo umido";  
  }
  //declare a faixa de valores em que o solo está secando 
  else if (valor_lido > 511 && valor_lido < 700)  
  {
    estado = "Solo quase seco"; 
     
    
  }

  //declare a faixa de valores em que o solo está seco
  else if (valor_lido > 700 && valor_lido < 1024)    
  {
    estado = "Solo seco"; 
    // liga o rele para irrigacao   
    digitalWrite(pino_saida, HIGH);
    //espera 3s com o rele ligado
    delay(3000);
    digitalWrite(pino_saida, LOW);
  }
//================================================================
  
  //defina o tempo de espera para o proximo loop                         
  delay(500);    
} 



 
 
