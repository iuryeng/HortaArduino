//===============================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Medição da temperatura com sensor digital DS18B20 
//===============================================

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
