/**
 * Final thing hopefully
 * dash and dot functions
 * one unit of time is 500ms
 */
int unit = 500;

void dash();
void dot();

//all the letters of the alphabet
void A();
void B();
void C();
void D();
void E();
void FF();
void G();
void H();
void I();
void J();
void K();
void L();
void M();
void N();
void O();
void P();
void Q();
void R();
void S();
void T();
void U();
void V();
void W();
void X();
void Y();
void Z();
void spaceW();
void spaceL();

void dash(){
  //three units of time for dash
  digitalWrite(LED_BUILTIN,HIGH);
  delay(unit*3);
  //one unit of time for space between parts of the letter
  digitalWrite(LED_BUILTIN,LOW);
  delay(unit);
}

void dot(){
  //one unit of time
  digitalWrite(LED_BUILTIN,HIGH);
  delay(unit);
  //one unit of time for space between parts of the letter
  digitalWrite(LED_BUILTIN,LOW);
  delay(unit);
}

void A(){
  dot();
  dash();
}

void B(){
  dash();
  dot();
  dot();
  dot();
}

void C(){
  dash();
  dot();
  dash();
  dot();
}

void D(){
  dash();
  dot();
  dot();
}

void E(){
  dot();
}

void FF(){
  dot();
  dot();
  dash();
  dot();
}

void G(){
  dash();
  dash();
  dot();
}

void H(){
  dot();
  dot();
  dot();
  dot();
}

void I(){
  dot();
  dot();
}

void J(){
  dot();
  dash();
  dash();
  dash();
}

void K(){
  dash();
  dot();
  dash();
}

void L(){
  dot();
  dash();
  dot();
  dot();
}

void M(){
  dash();
  dash();
}

void N(){
  dash();
  dot();
}

void O(){
  dash();
  dash();
  dash();
}

void P(){
  dot();
  dash();
  dash();
  dot();
}

void Q(){
  dash();
  dash();
  dot();
  dash();
}

void R(){
  dot();
  dash();
  dot();
}

void S(){
  dot();
  dot();
  dot();
}

void T(){
  dash();
}

void U(){
  dot();
  dot();
  dash();
}

void V(){
  dot();
  dot();
  dot();
  dash();
}

void W(){
  dot();
  dash();
  dash();
}

void X(){
  dash();
  dot();
  dot();
  dash();
}

void Y(){
  dash();
  dot();
  dash();
  dash();
}

void Z(){
  dash();
  dash();
  dot();
  dot();
}

void spaceW(){
  //space b/t words is supposed to be 7 in MC
  //but that's too long so let's do 
  digitalWrite(LED_BUILTIN,LOW);
  delay(unit*5);
}

void spaceL(){
  digitalWrite(LED_BUILTIN,LOW);
  delay(unit*3);
}


void setup() {
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
