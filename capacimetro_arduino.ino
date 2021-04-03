 /*
   Aula Curso Arduino Básico ao Avançado e prototipagem
   Instrutor Otávio Jesus França Oliveira
   Sorocaba - SP
 */


// --- Mapeamento de Hardware ---
#define carga        7          // Digital 11 carrega o capacitor
#define descarga      6          // Digital 10 descarrega o capacitor
#define resistor       2200.0F    // Resistor de carga utilizado no projeto, .0F simboliza um ponto flutuante                                  
#define Vcap        A0         // medida de tensão (carga no capacitor) no pino analógico 0


// --- Variáveis Globais ---
unsigned long Time01;             // Tempo inicial, o formato de variavel utilizado pode armazenar 32 bits, ou seja um numero consideravelmente grande 
                                  // utilizado para se obter grande precisão no tempo transcorrido 
unsigned long Time02;             // Tempo transcorrido
float microFarads;                // Armazena o valor da capacitância em µF
float nanoFarads;                 // Armazana o valor da capacitância em nF


// --- Configurações Iniciais ---
void setup()
{
    pinMode(carga, OUTPUT);         //Configura pino de carga como saída digital
       
    digitalWrite(carga, LOW);       //Inicializa pino de carga
    Serial.begin(9600);             // seta a velocidade de comunicação em 9600 bits/segundo

} //end setup


// --- Loop Infinito ---
void loop()
{
  
  digitalWrite(carga, HIGH);              //Saída de carga em nível alto (carrega o capacitor com a tensão de alimentação do Arduino)
  Time01 = millis();                       //Armazena a contagem de programa em mili segundos em Time01


  while(analogRead(Vcap) < 648){ }      // Aguarda até atingir 63,2% da tensão da fonte
  
                                           /*
                                                 Conversor AD de 10 bits
                                                 
                                                 1024  -  100%      
                                                    n  -  63,2%
                                                    
                                                    n = 1024 x 0,632 ~~ 647
                                           
                                           */
  

  Time02 = millis() - Time01;              // Calcula o tempo transcorrido
  
  
 /*
    tau = RC -> C = tau/R  
    
                                Time02 x 10E-3 (segundos)                        Time02 (segundos)
    C x 10E-6 (micro Farad) = --------------------------- ->  C (micro Farad) = ------------------- x 10E3
                               resistor       (Ohms)                             Resistor (Ohms)
    
 */
 
  microFarads = ((float)Time02 / resistor) * 1000;     // Calcula a Capacitância em Micro Farads

   



  if (microFarads > 1)                //Capacitância maior que 1uF?
  {                                   //Sim...
    
    Serial.print((long)microFarads);    //Imprime valor atual da capacitância em uF
    Serial.println(" uF");                //Imprime "uF"
    
  } //end if
  
  else                                //Senão...
  {
     

    nanoFarads = microFarads * 1000.0;      // Converte uF para nF
    
    
  Serial.print((long)nanoFarads);     //Imprime valor atual da capacitância em nF
  Serial.println(" nF");                //Imprime "nF"
    
  } //end else

   
  digitalWrite(carga, LOW);                //Pino de carga fica em nível baixo
  pinMode(descarga, OUTPUT);               //Pino de descarga configurado temporariamente como saída
  digitalWrite(descarga, LOW);             //Pino de descarga em nível baixo (descarrega o capacitor)
  while(analogRead(Vcap) > 0){ }         //Aguarda até que a tensão no capacitor chegue a zero
  

  pinMode(descarga, INPUT);                //Pino de descarga volta a ser entrada
  
  
  delay(300); //atualização das leituras
  
  
} //end loop






