
void adormecer() {  
  attachInterrupt(INT0, interrupcaoRTC, FALLING);
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  // analogWrite(brilho,0);
  sleep_mode();
  // o programa para aqui, indefinidamente  

  // quando alguma interrupcao acordar o Arduino, o programa
  // continua daqui, e a primeira coisa a fazer eh desativar
  // o modo sleep...
  sleep_disable(); 
  Serial.println("Acordando porque o RTC me chamou...");
}



