
# Projeto: Horta Automatizada com Arduino

> IFPB -  Instituto de Federal Ciências e Tecnologia da Paraíba 

> Núcleo de Inovação e Tecnolgia Educacional

> Autor: Iury Anderson Fernandes Coelho


## Conteúdo

> Esta seção contém a documentação necessária para a implementação do projeto.

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

- Algorítimo 1
- __Proposito: medição da temperatura com sensor digital DS18B20__

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


## Teste 

- Going into more detail on code and technologies used
- I utilized this nifty <a href="https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet" target="_blank">Markdown Cheatsheet</a> for this sample `README`.

---



## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
- Copyright 2015 © <a href="http://fvcproductions.com" target="_blank">FVCproductions</a>.
