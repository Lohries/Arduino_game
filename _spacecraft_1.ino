// incluindo a biblioteca liquid crystal //

#include <LiquidCrystal.h>
LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

// definindo botões e leds //
#define BOTUP     6
#define BOTDOWN   5
#define BOTSHOT   4
#define MAXSCORE 50
#define SPEED     150
#define LEDOFF   7
#define LEDON    8

// definindo variaveis inteiras //
int pxnave;
int pynave;
int pxaste;
int pyaste;
int pxenergia;
int pyenergia;
int pxtiro;
int pytiro;
int pontos;
int vtela;
double venergia;
bool game,vtiro,vpilha;

// definindo caracteres especiais //
byte nave[8]={
  B01110,
  B00100,
  B10110,
  B11111,
  B11111,
  B10110,
  B00100,
  B01110
};
byte asteroide[8]={   

  B00000,
  B00000,
  B00000,
  B01110,
  B10101,
  B11111,
  B01010,
  B10001
};
byte explosao[8]={
  B10001,
  B10101,
  B01010,
  B10100,
  B00101,
  B01010,
  B10101,
  B10001
};
byte energia[8]={
  B01110,
  B11011,
  B10001,
  B10101,
  B10101,
  B10101,
  B10001,
  B11111
};
byte tiro[8]={
  B00000,
  B00000,
  B00000,
  B00111,
  B00111,
  B00000,
  B00000,
  B00000
};

void desenhaNave(int px, int py);
void desenhaAsteroide(int px, int py);
void desenhaEnergia(int px, int py);
void desenhaTiro(int px, int py);
void desenhaExplosaoNave(int px, int py);
void desenhaExplosaoAsteroide(int px, int py);
void reset();
void painel(int px);
void tela(int cond);                      

// setup //
void setup() 
{
  lcd.begin(16,2);
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("Processando");
  delay(200);
  lcd.clear();
 
  
  pinMode(BOTDOWN ,INPUT_PULLUP);
  pinMode(BOTUP  ,INPUT_PULLUP);
  pinMode(BOTSHOT  ,INPUT_PULLUP);
  pinMode(LEDOFF, OUTPUT);
  pinMode(LEDON, OUTPUT);
  
  lcd.createChar(1,nave);
  lcd.createChar(2,asteroide);
  lcd.createChar(3,explosao);
  lcd.createChar(4,energia);
  lcd.createChar(5,tiro);
  
  pxnave=pynave=pyaste=pontos=pxenergia=pyenergia=pytiro=0;
  pxtiro=-1;
  pxaste=12;
  venergia=100;
  vtela=0;
  game=false;
  vtiro=vpilha=false;
  delay(100);
}

// loop- controles //
void loop()
{
  if(game)
  {
    venergia-=0.10;  // mecanismo de ajustar a dificuldade//
    lcd.clear();
    
    if(venergia<=0){
      game = 0;
      desenhaExplosaoNave(pxnave, pyaste);
      vtela = 2;
    }
    
    painel(13);
    
    if(!digitalRead(BOTUP))
    {
      pynave=0;
    }
    
    if(!digitalRead(BOTDOWN))
    {
      pynave=1;
    }
    
    if(!digitalRead(BOTSHOT))
    {
      pxtiro=1;
      vtiro=true;
      pytiro=pynave;
    }
    
    pxaste-=1;
    desenhaNave(pxnave,pynave);
    desenhaAsteroide(pxaste,pyaste);
    
    if(vtiro)
    {
      desenhaTiro(pxtiro,pytiro);
      pxtiro+=1;
    }
    
    if(pxaste<0)
    {
      pxaste=12;
      pyaste=random(0,2);
    }
    
    if(pxtiro>16)
    {
      vtiro=false;
      pxtiro=-1;
    }
    
    if(((pxtiro==pxaste+1)&&(pytiro==pyaste))||((pxtiro==pxaste)&&(pytiro==pyaste)))
    {
      vtiro=false;
      pxtiro=-1;
      desenhaExplosaoAsteroide(pxaste,pyaste);
      pyaste=random(0,2);
      pxaste=12;
      pontos+=2;
      if(pontos>=MAXSCORE){
        game = 0;
        vtela = 1;
      }
    }
    
    if(((pxnave==pxaste)&&(pynave==pyaste)))  // Condição de derrota //
    {
      game=0;
      desenhaExplosaoNave(pxnave,pyaste);
      vtela=2;
    }
    
    if(!vpilha)
    {
      if(random(0,60)>58)
      {
        pxenergia=12;
        vpilha=true;
        pyenergia=random(0,2);
     }
    }
    else
    {
      pxenergia-=1;
      desenhaEnergia(pxenergia,pyenergia);
      if(((pxnave==pxenergia+1)&&(pynave==pyenergia))||((pxnave==pxenergia)&&(pynave==pyenergia))){
        vpilha=false;
        pxenergia=-1;
        venergia=100;
      }
    }
    digitalWrite(LEDON, !digitalRead(LEDON));
    digitalWrite(LEDOFF,LOW);
    delay(SPEED);
  }
  else
  {
    digitalWrite(LEDON, LOW);
    digitalWrite(LEDOFF,HIGH);
    tela(vtela);
    if(!digitalRead(BOTSHOT)){
      reset();
    }
  }
  
}



void desenhaNave(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(1);
}


void desenhaAsteroide(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(2);
}


void desenhaEnergia(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(4);
}


void desenhaTiro(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(5);
}


void desenhaExplosaoNave(int px, int py)
{
  lcd.clear();
  lcd.setCursor(px,py);
  lcd.write(3);
  delay(500);
  lcd.clear();
}


void desenhaExplosaoAsteroide(int px, int py)
{
  lcd.setCursor(px,py);
  lcd.write(3);
  delay(500);
  lcd.clear();
}


void reset()
{
  pontos=0;
  venergia=100;
  game=true;
  vtela=0;
}


void painel(int px)
{
  lcd.setCursor(px,0);
  lcd.print(pontos);
  lcd.setCursor(px,1);
  lcd.print(venergia);
}


void tela(int cond)                         // 0=TelaInicial |  1=Ganhou  |  2=Perdeu //
{
  if(cond<1){
    lcd.setCursor(2,0);
    lcd.print("SPACECRAFT");
    lcd.setCursor(0,1);
    lcd.print("APERTE TIRO");
  }
  else
  {
    String txt= cond>1 ? "GAME OVER" : "VITORIA";
    lcd.setCursor(11,0);
    lcd.print("P:");
    lcd.setCursor(13,0);
    lcd.print(pontos);
    lcd.setCursor(1,0);
    lcd.print(txt);
    lcd.setCursor(0,1);
    lcd.print("APERTE TIRO");
  }
}