





void ajustaHora(short ajuste) {
  short hora=hour()+ajuste;
  if (hora<0) hora=23;
  if (hora>23) hora=0;
  setTime(hora, minute(), second(), day(), month(), year());
  RTC.set(now());
}  


void ajustaMinuto(short ajuste) {
  short minuto=minute()+ajuste;
  if (minuto<0) minuto=59;
  if (minuto>59) minuto=0;
  setTime(hour(), minuto, second(),  day(), month(), year());
  RTC.set(now());
}  

void ajustaSegundo(short ajuste) {
  short segundo=second()+ajuste;
  
  setTime(hour(), minute(), 0,  day(), month(), year());
  RTC.set(now());
}  


////////////////////////////////////////////////



void ajustaDia(short ajuste) {
  short diaa = day()+ajuste;
  if (diaa<1) diaa=31;
  if (diaa>31) diaa=1;
  setTime(hour(), minute(), second(), diaa, month(), year());
  RTC.set(now());
}






void ajustaMes(short ajuste) {
  short mes = month()+ajuste;
  if (mes<1) mes=12;
  if (mes>12) mes=1;
  setTime(hour(), minute(), second(),  day(), mes, year());
  RTC.set(now());
}  

void ajustaAno(short ajuste) {
  short ano = year()+ajuste;
  //if (ano<2000) ano=1999;
  //if (ano>1999) ano=2000;
  setTime(hour(), minute(), second(),  day(), month(), ano);
  RTC.set(now());
}  


