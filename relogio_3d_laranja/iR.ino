   
/***********************************************************************************
 *****************************INICIO DE RECEPTOR************************************
 **********************************************************************************/

 
   void iniciar_IR(){
    ir_recebe.enableIRIn(); // inicia a recepção  
  
 
  /*
    pinMode(ledverde, OUTPUT); //declarado led como saída   
    pinMode(ledamarelo, OUTPUT);   
    pinMode(ledvermelho, OUTPUT);   
   */
 }
   
   
   
   void exec_IR() {   
////////////////////////////////////////////////////////
// comando para ler o codigo de cada tecla e enviar para o Terminal do arduino
  if (ir_recebe.decode(&codigo_recebido)) {  //verifica se um codigo foi recebido   
     if (codigo_recebido.value != 0 ){  
     Serial.println(codigo_recebido.value, HEX); //mostra no serial o resultado  
      analogWrite(10,200);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Comando recebido");
      lcd.setCursor(0, 1);
     lcd.print(codigo_recebido.value,HEX); 
      //delay (1000);   //mostra no lcd o resultado  
   }  
 
/**********************************************************************************
*************************AJUSTE HORARIO POR COMANDO IR*****************************
**********************************************************************************/



  if (codigo_recebido.value == 0xFFE21D) //tecla mode
  {               //Menu para apenas ajuste do horario
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Menu ajuste ");
      lcd.setCursor(0, 1);
      lcd.print("      de horario");
      serial();
      delay (1900);   //mostra no lcd o resultado  
      }
 
 
  if (codigo_recebido.value == 0xFF629D) //tecla mode
  {       ajustaSegundo(+1);      //Menu para apenas ajuste do horario
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Segundos Zerados ");
      lcd.setCursor(0, 1);
      //lcd.print("      de horario");
      delay (1900);   //mostra no lcd o resultado  
      }
 
      
       
 
 if (codigo_recebido.value == 0xFFA857){// verifica qual tecla foi pressionada
      ajustaHora(+1);
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX); 
      lcd.print(" +1 Hora ");
      delay (900);   //mostra no lcd o resultado  
      
      
      
  }
  
   if (codigo_recebido.value == 0xFFE01F){// verifica qual tecla foi pressionada
      ajustaHora(-1);
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX);
      lcd.print(" -1 Hora ");
      delay (900);   //mostra no lcd o resultado  
      
      
       
  }
  
  
  if (codigo_recebido.value == 0xFF9867){// verifica qual tecla foi pressionada
      ajustaMinuto(+1);
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX); 
      lcd.print(" +1 Minuto ");
      delay (900);   //mostra no lcd o resultado  
      
      
      
  }
  
   if (codigo_recebido.value == 0xFF6897){// verifica qual tecla foi pressionada
      ajustaMinuto(-1);
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX);
      lcd.print(" -1 Minuto ");
      delay (900);   //mostra no lcd o resultado  
      
       
  }
  
  
  
  
  
  
  if (codigo_recebido.value == 0xFF02FD){// verifica qual tecla foi pressionada
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX); 
      lcd.print(" +5 Minuto ");
      delay (900);   //mostra no lcd o resultado  
      
      
      ajustaMinuto(+1);
      ajustaMinuto(+1);
      ajustaMinuto(+1);
      ajustaMinuto(+1);
      ajustaMinuto(+1);
      
      
      
      
  }
  
   if (codigo_recebido.value == 0xFF22DD){// verifica qual tecla foi pressionada
      
      lcd.setCursor(0, 1);
      //lcd.print(codigo_recebido.value,HEX);
      lcd.print(" -5 Minuto ");
      delay (900);   //mostra no lcd o resultado  
      
      ajustaMinuto(-1);
      ajustaMinuto(-1);
      ajustaMinuto(-1);
      ajustaMinuto(-1);
      ajustaMinuto(-1);
      
       
  }
   
////////////////////////////////////////////////////////
 if (codigo_recebido.value == 0xFFA25D){// verifica qual tecla foi pressionada
      
      lcd.setCursor(0, 0);
      lcd.print("In Stand By mode");
      lcd.setCursor(0, 1);
      lcd.print("in 3............");
      delay (1000);    
      lcd.setCursor(0, 1);
      lcd.print("in 3...2........");
      delay (1000);    
      lcd.setCursor(0, 1);
      lcd.print("in 3...2...1....");
      delay (1000);    
      
       adormecer();
  }
  
   ir_recebe.resume(); // recebe o próximo código  
   delay(200);   
  }   
  }  
  
  
/***********************************************************************************
 *************************FIM DE RECEPTOR*******************************************
 **********************************************************************************/

