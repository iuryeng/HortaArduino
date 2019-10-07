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

// inclua as bibliotecas necessárias
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// defina o pino de ligação do sensor de umidade do solo
#define   analogico  A1 

// defina o pino D7 como saída para o rele
#define pino_saida  7

// declare a variável global contendo o valor lido do sensor
int valor_lido = 0; 

// declare a variável global contendo o estado do solo
String estado;

// crie um objeto display com Adafruit_SSD1306
Adafruit_SSD1306 display = Adafruit_SSD1306();

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

} 
// inicialize as definiçoes que irão ser tratadas no loop infinito do arduino
void loop()
{
  // declare a variável global sendo o valor lido na porta analogica A0
  valor_lido = analogRead(analogico);                         

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
    display.setCursor(27,5);  
    //imprima o valor lido no display
    display.print("Valor lido:");
    display.print(valor_lido);
    display.setCursor(27,20);
    display.print(estado);
    
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



 
 
