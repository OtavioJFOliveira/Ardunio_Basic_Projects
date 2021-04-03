 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */

//Efeito de fogo
int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 11;

void setup()
{
  for(int i =9; i<12;i++) pinMode(i,OUTPUT);
  
 //	pinMode(ledPin1, OUTPUT);
 //	pinMode(ledPin2, OUTPUT);
 //	pinMode(ledPin3, OUTPUT);
}

void loop()
{
analogWrite(ledPin1, random(120)+135); //função random fornece numeros aleatótios com limites configuraveis
analogWrite(ledPin2, random(120)+135); // neste caso foi configurado o limite superiror de 120
analogWrite(ledPin3, random(120)+135); //essa função pega numeros totalmente aleatorios durante a execução  
delay(random(100));                    
}
