//===============================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Medição da umidade do solo 
//===============================================


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



 
