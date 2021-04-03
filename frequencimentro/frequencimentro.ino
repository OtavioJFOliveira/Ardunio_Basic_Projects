 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
   otaviojf_oliveira@outlook.com
 */
 
// --- Mapeamento de Hardware ---
#define inFreq   5  //entrada para medir a frequência no pino digital 5


// --- Variáveis Globais ---
long freq, counter;
int pulseCount;
boolean pulse;


// --- Configurações Iniciais ---
void setup() 
{
  
  pinMode(inFreq,INPUT);    //Configura como entrada

  Serial.begin(9600);
  pulse = 0x01;             //Seta variável de controle
  
} //end setup


// --- Loop Infinito ---
void loop() 
{
  
  counter = millis();      //counter recebe o valor do tempo em ms
  
  if(digitalRead(inFreq))  //Entrada de frequência em nível alto?
  {                        //Sim...
  
    if(pulse) pulseCount++;  //incrementa pulseCount se variável de controle for verdadeira
     
    pulse = 0x00;            //limpa variável de controle

  }
  else                     //Não...
  {
    pulse = 0x01;          //Seta variável de controle
  }


  if(counter%200 == 0x00)  //Passaram-se 200 ms?
  {                        //Sim...
    freq = pulseCount*5;   //Atualiza frequência (200 x 5 = 1000ms)
    Serial.print(freq);      //Imprime valor atual da frequência
    Serial.println("Hz");      //Imprime "Hz"
    
    pulseCount = 0x00;     //Reinicia contador
  }
  
  
} //end loop

