# rtc-10
imprime um "0" se o numero for inferior a zero



lcd.clear(); // limpa LCD display
  //Mostra a data
  
  lcd.setCursor(0, 0);
  imprime_dia_da_semana_lcd(weekday());
  lcd.setCursor(3, 0);
  lcd.print (", ");
 // Adiciona um 0 caso o valor dos minutos seja <10
  if (day() < 10) {lcd.print(" "); }
  lcd.print(day(), DEC);
  imprime_mes_do_ano_lcd(month());
  lcd.print(year(), DEC);
  
    // Mostra o Horario
  lcd.setCursor(0, 1);
  if (hour() < 10) {lcd.print(" "); }
  lcd.print(hour(), DEC);
  lcd.print(':');
  
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (minute() < 10) {lcd.print("0"); }
  lcd.print(minute(), DEC);
  lcd.print(':');
  
  
  
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (second() < 10) {lcd.print("0"); }
  lcd.print(second(), DEC);
  
  
  //  Apresentação da leitura de temperatura
  

    lcd.setCursor(11, 1);
    lcd.print(GetTemp(),0);  //imprime a string no display do LCD.     
    lcd.write(B11011111); //Simbolo de graus celsius
    lcd.print("C");
     
    
   

 //lcd.print(valorLuzMax(),DEC);
    
    
    
 
}

void duasCasas(int digitos) {
  Serial.print(':');
  if(digitos < 10) Serial.print('0');
  Serial.print(digitos);
}




  
void imprime_dia_da_semana_lcd(int dia_lcd)
{
  switch (dia_lcd)
  {
    case 1: lcd.print("Domingo"); break;
    case 2: lcd.print("Segunda"); break;
    case 3: lcd.print("TerCa"); break;
    case 4: lcd.print("Quarta"); break;
    case 5: lcd.print("Quinta"); break;
    case 6: lcd.print("Sexta"); break;
    case 7: lcd.print("Sabado"); break;
  }

}
  
  
/**********************************************************************************
************fim do void imprime_dia_da_semana**************************************
**********************************************************************************/
 
 
 
 
/**********************************************************************************
*************void imprime_mes_do_ano***********************************************
**********************************************************************************/


void imprime_mes_do_ano_lcd(int mes_lcd) {
  switch (mes_lcd) {
    case 1:  lcd.print(" Jan ");  break;
    case 2:  lcd.print(" Fev ");  break;
    case 3:  lcd.print(" Mar ");  break;
    case 4:  lcd.print(" Abr ");  break;
    case 5:  lcd.print(" Mai ");  break;
    case 6:  lcd.print(" Jun ");  break;
    case 7:  lcd.print(" Jul ");  break;
    case 8:  lcd.print(" Ago ");  break;
    case 9:  lcd.print(" Set ");  break;
    case 10: lcd.print(" Out ");  break;
    case 11: lcd.print(" Nov ");  break;
    case 12: lcd.print(" Dez ");  break;
  }
}

/**********************************************************************************
************fim do void imprime_mes_do_ano*****************************************
**********************************************************************************/
 
 
 
