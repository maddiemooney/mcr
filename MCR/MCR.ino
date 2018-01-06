/**
 * Final thing hopefully
 * dash and dot functions
 * one unit of time is 500ms
 */
 
int unit = 500; // num of miliseconds per unit
int pr = 5; //pin for photoresistor
int led = 1; //pin for the LED
static int dstate = 0; //assuming light starts off

int prlow = 400;
int prhigh = 600;

int timer1start;
int timer1stop;
int timer2start;
int timer2stop;
int timer1;
int timer2;


void dash();
void dot();
int readpr(int prev);

//all the letters of the alphabet
void A();
void B();
void C();
void D();
void E();
void FF(); //called this because F() is already a function
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
  digitalWrite(led,HIGH);
  delay(unit*3);
  //one unit of time for space between parts of the letter
  digitalWrite(led,LOW);
  delay(unit);
}

void dot(){
  //one unit of time
  digitalWrite(led,HIGH);
  delay(unit);
  //one unit of time for space between parts of the letter
  digitalWrite(led,LOW);
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
  digitalWrite(led,LOW);
  delay(unit*5);
}

void spaceL(){
  digitalWrite(led,LOW);
  delay(unit*2);
}

int readpr(int prev){
  int state = analogRead(pr);
  if(prev == LOW && state >= prhigh){
    return HIGH;
  }
  else if(prev == HIGH && state  < prlow){
    return LOW;
  }
  else{
    return prev;
  }
}

char translate(int timerval, int isletter){
  if(isletter){
    if(timerval > (unit/2) && timerval < (unit*2)){ //giving it some leeway
      //it's a dot
    }
    else if (timerval > (unit*2)){
      //it's a dash
    }
  }
  else{
    if(timerval > (unit*1.5) && timerval < (unit*4)){ 
      //go to next letter
      //clear cache for letters
    }
    else if(timerval > (unit*4)){
      //go to next word
    }
    //else it's just a space between a dash/dot, ignore
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {

  char c;

  //reading only. will likely have to put in another file altogether
  Serial.println(analogRead(pr)); //for testing (later)
  delay(250);

  /*int newstate = readpr(dstate);
  if(dstate == LOW && newstate == HIGH){
    timer1start = millis();
    timer2stop = millis();
    timer2 = timer2stop - timer2start;
    c = translate(timer2,0);
  }
  if(dstate == HIGH && newstate == LOW){
    timer1stop = millis();
    timer2start = millis();
    timer1 = timer1stop - timer1start;
    c = translate(timer1,1);
  }
  dstate = newstate;*/

}

