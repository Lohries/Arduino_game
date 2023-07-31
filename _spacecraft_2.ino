// biblioteca Liquid Crystal //

#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

// setup- nada aqui  //

void setup()
{
}

// loop- vamos escrever no lcd //
void loop()
{
 int contador = 1;
 while (contador <= 1)
 {
   lcd.begin (16,2);
    
  lcd.print ("Bem vindo");
   delay(1000);
 //lcd.clear();
   contador = contador + 1;
 }
   while (contador <= 2)
 {
   lcd.begin (16,2);
   
  lcd.print ("Spacecraft+");
     delay(1000);
      //lcd.clear();
 contador = contador + 1;
 }
   while (contador <= 3)
 {
   lcd.begin (16,2);
  
  lcd.print ("Salve o Universo");
     delay(1000);
 //lcd.clear();
     contador = contador + 1;
     
 }
   while (contador <= 4)
 {
   lcd.begin (16,2);
    
  lcd.print ("Destrua os ETEs");
     delay(1000);
//lcd.clear();
     contador = contador + 1;
     
 }
   while (contador <= 5)
 {
   lcd.begin (16,2);
      
  lcd.print ("BOTUP-sobe");
     delay(1000);
 //lcd.clear();
     contador = contador + 1;
     
 }
   while (contador <= 6)
 {
   lcd.begin (16,2);
     
  lcd.print ("BOTDOWN-desce");
     delay(1000);
 //lcd.clear();
     contador = contador + 1;
      
 }
   while (contador <= 7)
 {
   lcd.begin (16,2);
      
  lcd.print ("BOTSHOOT-atira");
     delay(1000);
  //lcd.clear();
     contador = contador + 1;
   }
     
   while (contador <= 8)
 {
   lcd.begin (16,2);
      
  lcd.print ("Obg por jogar");
     delay(1000);
 //lcd.clear();
     contador = contador + 1;
      
 }
   while (contador <= 9)
 {
   lcd.begin (16,2);
    
     lcd.print ("   Exclusivo    ");
     lcd.setCursor(0,1);
     lcd.print (" de TinkercadBR ");
     delay(1000);
     //lcd.clear();
  contador = contador + 1;
     
 }
   while (contador >= 10)
 {
   lcd.begin (16,2);
      
    lcd.print ("  Oferecimento  ");
    lcd.setCursor(0,1);
     lcd.print ("   Engenhocas   ");
   delay(1000);    
 //lcd.clear();
    contador = contador - 9;
      
   }
}