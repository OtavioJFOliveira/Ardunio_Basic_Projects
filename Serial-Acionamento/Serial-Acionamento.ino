 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */

int ledPin13 =  9;
int ledPin11 =  8; // atribui o nome ledPin11 para o pino digital 11 do arduino
# define ledPin9  7  // outra forma de atribuir nome aos pinos digitais, essa é a mais utilizada, pois nao reserva espaço na memoria 
int ledPin7  =  6;
int ledPin5  =  5;
//----------SETUP DOS PINOS E COMUNICAÇÃO --------------------
void setup()   {
 
  Serial.begin(9600); // seta a velocidade de transmissao dos dados via porta serial
 
  pinMode(ledPin13, OUTPUT); // seta os pinos como saida de forma individual 
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  
 // for(int i =5;i<10;i++) pinMode(i,OUTPUT); // utilizando um laço FOR é possível otimizar o processo, considerando que os pinos sejam usados de forma sequencial
}


//----------LOOP INFINITO -----------------------------------
void loop()
{
  char tecla; // cria uma variavel tipo cHAR com nome tecla 
  tecla = Serial.read(); // Comando responsavel por fazer a leitura da porta de entrada de dados durante a comunicação serial e atribuir o valor lido a variavel tecla
  
  
  if(tecla == 'g')  //se pressionado "g" liga o led verde (green)
  {
      digitalWrite(ledPin13, HIGH);
  }
  else   //Se pressionado "b" liga o led azul (blue)
 
    if(tecla == 'b')
    {
         digitalWrite(ledPin11, HIGH);
    }
    else
      //S pressionado "o" liga o led laranja (orange)
      if(tecla == 'o')
      {
         digitalWrite(ledPin9, HIGH);
      }
      else
        //Se pressionado "y" liga o led amarelo (yellow)
        if(tecla == 'y')
        {
            digitalWrite(ledPin7, HIGH);
        }
        else
          //Se pressionado "w" liga o led branco (white)
          if(tecla == 'w')
          {
              digitalWrite(ledPin5, HIGH);
          }
          else
 
            //Se pressionado "d" desliga todos os leds
            if(tecla == 'd')
            {
                digitalWrite(ledPin13, LOW); // comando LOW coloca o pino correspondente em estado desligado, ou seja, nivel lógico baixo 
                digitalWrite(ledPin11, LOW);
                digitalWrite(ledPin9, LOW);
                digitalWrite(ledPin7, LOW);
                digitalWrite(ledPin5, LOW);
            }
  
}
