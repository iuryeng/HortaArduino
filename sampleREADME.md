
# Projeto: Horta Automatizada com Arduino

> IFPB -  Instituto de Federal Ciências e Tecnologia da Paraíba. 

> Núcleo de Inovação e Tecnolgia Educacional.

> Curso de Engenharia de Computação.

> Autor: Iury Anderson Fernandes Coelho

## Introdução

## Conteúdo

> Esta seção contém os links das documentações necessárias para a implementação do projeto.

- [Instalação da IDE do Arduino](#instalacao)
- [Teste](#teste)
- [Download das Bibliotecas](#download)
- [Algorítimos](#materiais)
- [Contributing](#contributing)
- [Support](#support)
- [License](#license)

---
## Instalação 

> Vamos comerçar...

- é interessante que você acesse o site oficial do arduino: https://www.arduino.cc/;
- você irá precisar instalar a IDE do arduino para poder programa-lo;
- entre em: https://www.arduino.cc/en/Main/Software e faça o downlaod da IDE do arduino de acordo com as especificações de seu sistema operacional.

## Teste 


## Download das Bibliotecas

- Para que seu projeto rode adequadamente será necessário fazer o download das seguintes bibliotecas: 
- SPI.h
- Wire.h
- Adafruit_GFX.h
- Adafruit_SSD1306.h
- DallasTemperature.h

## Algorítimos em C/C++
> Nesta seção serão apresentados os algorítimos e suas respectivas finalidades

- Algorítimo 1
- __Propósito: medição da temperatura com sensor digital DS18B20__

```c
// Medição da temperatura com sensor digital DS18B20 

//importe a biblioteca necessária

#include <DallasTemperature.h>

//defina o pino de leitura do sensor
#define DS18B20 8

//intancie ourwire para se comunicar com o sensor DS18B20
OneWire sensor(DS18B20);

//passe o valor fornecido para dallastemperature
DallasTemperature sensor_temp(&sensor);

void setup() {
  
  //defina a velocidade de comunicação com o monitor serial em 9800
  Serial.begin(9800);
  
  // inicialize a leitura do sensor DS18B20
  sensor_temp.begin();
}

void loop() {
  
  //capture o valor fornecido pelo sensor
  sensor_temp.requestTemperatures();
  
  //Imprima o valor capturado para o monitor serial
  Serial.println(sensor_temp.getTempCByIndex(0));
  
  //espere 700 milissegundos
  delay(700);
}
```

- Algorítimo 2
- __Propósito: medição da umidade do solo__

```c
//Medição da umidade do solo 

// defina o pino de ligação do sensor de umidade do solo
#define   analogico  A1 

// declare a variável global contendo o valor lido do sensor
int valor_lido = 0; 

//inicialize as definições de hardware
void setup()
{
    //defina a taxa de transmissão de dados como 9600
    Serial.begin(9600);  
    
    //defina o estado do pino analigico A0 como pino de entrada  
    pinMode(analogico,  INPUT);   

} 
// inicialize as definiçoes que irão ser tratadas no loop infinito do arduino
void loop()
{
  // declare a variável global sendo o valor lido na porta analogica A0
  valor_lido = analogRead(analogico);                         

  //imprima para o usuário o valor do sensor 
  Serial.print("Valor lido: ");                                
  Serial.print(valor_lido); 
                                            
  //declare a faixa de valores em que a umidade é total
  if (valor_lido > 0 && valor_lido < 169)             
  {
    Serial.println(" Umidade: Solo totalmente umido"); 
  }

  //declare a faixa de valores em que a umidade é média
  else if (valor_lido > 169 && valor_lido < 340)   
  {
    Serial.println(" Umidade: Solo muito umido"); 
  }
 
  //declare a faixa de valores em que a umidade é mínima
  else if (valor_lido > 340 && valor_lido < 511)  
  {
    Serial.println(" Umidade: Solo umido");
  }
  
  //declare a faixa de valores em que o solo está secando 
  else if (valor_lido > 511 && valor_lido < 853)  
  {
    Serial.println(" Umidade: Solo quase Seco"); 
  }

  //declare a faixa de valores em que o solo está seco
  else if (valor_lido > 853 && valor_lido < 1024)    
  {
    Serial.println(" Umidade: Solo seco");
  }
  
  //defina o tempo de espera para o proximo loop                         
  delay(500);   
  
} 
```

- Algorítimo 3
- __Propósito: implementação de display Oled__

```c
//Hello word tela de oled

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

```
## Teste 

- Going into more detail on code and technologies used
- I utilized this nifty <a href="https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet" target="_blank">Markdown Cheatsheet</a> for this sample `README`.

---



## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2015 © <a href="http://fvcproductions.com" target="_blank">FVCproductions</a>.
