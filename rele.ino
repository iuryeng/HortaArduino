//===============================================
//Oficinas de programação em C usando o Arduino
//Autor: Iury Anderson Fernandes Coelho
//Acionamento da bomda d'agua 
//===============================================

// defina o peino D7 como saída
#define pino_saida  7
void setup() {
  pinMode(pino_saida, OUTPUT);
}
 
void loop() {
  // ative o relé
  digitalWrite(pino_saida, HIGH);   
  //espere 1000 milissegundos
  delay(1000);
  // Desative o relé             
  digitalWrite(pino_saida, LOW); 
  // espere 1000 milissegundos   
  delay(1000);             
  
}
