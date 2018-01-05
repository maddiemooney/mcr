/**
 * Final thing hopefully
 * dash and dot functions
 * one unit of time is 500ms
 */


 /**
  *Simple test of the functionality of the photo resistor

Connect the photoresistor one leg to pin 0, and pin to +5V
Connect a resistor (around 10k is a good value, higher
values gives higher readings) from pin 0 to GND. (see appendix of arduino notebook page 37 for schematics).

----------------------------------------------------

           PhotoR     10K
 +5    o---/\/\/--.--/\/\/---o GND
                  |
 Pin 0 o-----------

----------------------------------------------------


int lightPin = 0;  //define a pin for Photo resistor
int ledPin=11;     //define a pin for LED

void setup()
{
    Serial.begin(9600);  //Begin serial communcation
    pinMode( ledPin, OUTPUT );
}

void loop()
{
    Serial.println(analogRead(lightPin)); //Write the value of the photoresistor to the serial monitor.
    digitalWrite(ledPin, analogRead(lightPin)/4);  //send the value to the ledPin. Depending on value of resistor 
                                                //you have  to divide the value. for example, 
                                                //with a 10k resistor divide the value by 2, for 100k resistor divide by 4.
   delay(10); //short delay for faster response to light.
}
  */
int unit = 500; // num of miliseconds per unit
int pr = 0; //pin for photoresistor
int led = 1; //pin for the LED
static int dstate = 0; //assuming light starts off

int prlow = 400;
int prhigh = 600;


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
  delay(unit*3);
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

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {

  //uhhhh this is reading stuff. will likely have to put in another function
  Serial.println(analogRead(pr));
  delay(10);

  int newstate = readpr(dstate);
  if(dstate == LOW && newstate == HIGH){
    //determine whether dot or dash
  }
  if(dstate == HIGH && newstate == LOW){
    //determine where in sequence
  }
  dstate = newstate;

}
