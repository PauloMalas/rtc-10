 void serial(){
   
  
  boolean teclou;
  
  
  do {
    teclou=false;
    if (RTC.alarm(ALARM_1)) 
    
    
    Serial.print(hour());
    duasCasas(minute());
    duasCasas(second());
    Serial.print(' ');
    Serial.print(day());
    Serial.print(' ');
    Serial.print(month());
    Serial.print(' ');
    Serial.print(year()); 
    Serial.println();
     Serial.println();
     Serial.println();
    
    Serial.println("entrar hh  para adiantar a hora.");
    Serial.println("entrar h para retroceder a hora.");
    Serial.println("_________________");
    Serial.println("entrar mm para adiantar os minutos.");
    Serial.println("entrar m para retroceder os minutos.");
    
    Serial.println("entrar z para zerar os segundos.");
    
    Serial.println("_________________");
    
    
    
    Serial.println("entrar dd para adiantar o Dia.");
    Serial.println("entrar d para retroceder o Dia.");
    Serial.println("_________________");
    Serial.println("entrar MM para adiantar o Mes.");
    Serial.println("entrar M para retroceder o Mes.");
    Serial.println("_________________");
    Serial.println("entrar yy para adiantar o Ano.");
    Serial.println("entrar y para retroceder o Ano.");
    String S=Serial.readStringUntil(10);
    if (S!="") {
      teclou=true;
           if (S.startsWith("hh")) ajustaHora(+1);
      else if (S.startsWith("h")) ajustaHora(-1);
      else if (S.startsWith("mm")) ajustaMinuto(+1);
      else if (S.startsWith("m")) ajustaMinuto(-1);
      else if (S.startsWith("z")) ajustaSegundo(+1);
      else if (S.startsWith("x")) ajustaSegundo(-1);
      
      else if (S.startsWith("dd")) ajustaDia(+1);
      else if (S.startsWith("d")) ajustaDia(-1);
      else if (S.startsWith("MM")) ajustaMes(+1);
      else if (S.startsWith("M")) ajustaMes(-1);
      else if (S.startsWith("yy")) ajustaAno(+1);
      else if (S.startsWith("y")) ajustaAno(-1);
      Serial.println(S);
     
    }
  } while(teclou);  
}

