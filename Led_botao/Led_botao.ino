 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */

int CHAVE=8;
#define LED 13 // define, usado para definir uma porta ou um valor fixo dentro do programa
void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(CHAVE,INPUT);
}

void loop()
{
  if(digitalRead(CHAVE) == HIGH)
  digitalWrite(LED,HIGH);
  else
  digitalWrite(LED,LOW);
}

