 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */

int Status; 
void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600); // seta a velocidade de transmissao de dados pela porta serial
}

void loop() 
{
  delay(1000);
  Serial.println("texto");
  if (Serial.available() > 0)  // verifica se existem dados no bufer serial 
  {
    Status = Serial.read(); // le os dados recebidos na porta serial 
if (Status == 'H')          // avalia se o caracter digitado é igual a letra H
    {
      digitalWrite(13, HIGH);
      Serial.println("LED ligado"); // mostra no monitor serial a frase LED ligado
} 

    if (Status == 'L')    // verifica se o caracter digitado é igual a letra L
    {
      digitalWrite(13, LOW); 
      Serial.println("LED Desligado"); 
    }
  }
}
