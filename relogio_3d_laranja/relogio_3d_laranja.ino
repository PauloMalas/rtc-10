//  So compilou na versao 1.5.2



/*************************************************************************************************************
**********************************************   Bibliotecas   ***********************************************
**************************************************************************************************************/
  



#include <DS3232RTC.h>
#include <Time.h>  
#include <Wire.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <LiquidCrystal.h>
#include <IRremote.h>
#include <Process.h>




/*************************************************************************************************************
*************************************   Declaraçoes    *******************************************************
**************************************************************************************************************/
  
// definicoes do RTC
#define SQW 2
#define CLK 6
#define DIO 7

volatile boolean interrupcaoRTCfoiChamada = false;
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

  int ledverde = 9;
 // int ledamarelo = 10;   // led no pino 10   
  int ledvermelho = A2;
  
  int contraste = 6;               //pino de contraste do display
  int brilho = 10;                //pino de brilho do Anodo do display
  int LcdLed = 9;                 //pino digital 9 Katodos leds do lcd

  int sensorTemperatura    = A1;   //Pino analógico em que a medição da temperatura.
  int sensorLuz    = A0;   //Pino analógico em que a medição da luz.
  int segundos=0;
  float valorLuz;           //Variável usada para armazenar valor da Luz.
  float valorLuzMin = 999;
  float valorLuzMax = 0;
 
  const int RECEBE_PINO = A3; // pino 6 no arduino 
  IRrecv ir_recebe(RECEBE_PINO); // declarando a variável do sensor   
  decode_results codigo_recebido; // resultado   



 
 
/*************************************************************************************************************
*******************************FUNÇÃO TIME********************************************************************
mais detalhes: http://fabianoallex.blogspot.com.br/2015/09/arduino-como-substituir-delay-pelo.html
*************************************************************************************************************
**************************************************************************************************************/
     
int time(long timeHigh, long timeLow, long atraso, long mref = 0) {
  long ajuste = mref % (timeHigh + timeLow);
  long resto  = (millis() + timeHigh + timeLow - ajuste - atraso) % (timeHigh + timeLow);
  return (resto < timeHigh ? HIGH : LOW);
}
/*************************************************************************************************************
*******************************FIM FUNÇÃO TIME****************************************************************
**************************************************************************************************************/
  
 
 
 

 
 
 





/**********************************************************************************
*****************************Inicio Void Setup*************************************
**********************************************************************************/


void setup() { 

  pinMode(contraste, OUTPUT); 
  pinMode(brilho, OUTPUT);
  pinMode(LcdLed, OUTPUT);        //leds do lcd como saida

  digitalWrite(LcdLed, LOW);      //acende leds do lcd 
  analogWrite(contraste,80);
       
  valorLuz = analogRead(sensorLuz);   // leia o valor do sensor (valor entre 0 e 1023)

  lcd.begin(16, 2);
  iniciar_IR();
  
 
  Serial.begin(9600);
  Serial.setTimeout(1000);    
  setSyncProvider(RTC.get);
  if (timeStatus() != timeSet) 
    Serial.println("Erro: Nao recebi horario do RTC");
  else Serial.println("Horario foi obtido do RTC normalmente");  
   
  
  // desativa a frequencia no pino SQW para podermos usa-lo como alarme:
  RTC.squareWave(SQWAVE_NONE);
  pinMode(SQW, INPUT_PULLUP);
  RTC.setAlarm(ALM1_MATCH_SECONDS, 10, 0, 0, 1);
  RTC.alarm(ALARM_1);
  RTC.alarmInterrupt(ALARM_1, true);
  //display.setBrightness(0x0f);
}


/**********************************************************************************
*****************************Inicio Void Loop**************************************
**********************************************************************************/


void loop () {
  
  
  analogWrite(brilho,valorLuz);
  
  
  
   //mostra por 5 milisegundos a hora e por 500 milisegundos a data

  if ( time(5, 500, 0) ) {
  exec_IR();
  atualizaDisplay();
  // serial();
  //adormecer();
  } else {
  exec_IR();
  }


}




 
/**********************************************************************************
*****************************fim do void loop**************************************
**********************************************************************************/
 
 
    
