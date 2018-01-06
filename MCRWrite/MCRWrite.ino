/**
   handles LED and writing morse code
*/

/*
 *******************************************************
    variables
 *******************************************************
*/

int unit = 500; // num milliseconds per unit
int pr = A0; //pin for photoresistor
int led = 1; //pin for LED


/*
*******************************************************
   function declarations
*******************************************************
*/

void dash();
void dot();

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

/*
 *******************************************************
    subroutines
 *******************************************************
*/

void dash() {
  //three units of time for dash
  digitalWrite(led, HIGH);
  delay(unit * 3);
  //one unit of time for space between parts of the letter
  digitalWrite(led, LOW);
  delay(unit);
}

void dot() {
  //one unit of time
  digitalWrite(led, HIGH);
  delay(unit);
  //one unit of time for space between parts of the letter
  digitalWrite(led, LOW);
  delay(unit);
}

void A() {
  dot();
  dash();
}

void B() {
  dash();
  dot();
  dot();
  dot();
}

void C() {
  dash();
  dot();
  dash();
  dot();
}

void D() {
  dash();
  dot();
  dot();
}

void E() {
  dot();
}

void FF() {
  dot();
  dot();
  dash();
  dot();
}

void G() {
  dash();
  dash();
  dot();
}

void H() {
  dot();
  dot();
  dot();
  dot();
}

void I() {
  dot();
  dot();
}

void J() {
  dot();
  dash();
  dash();
  dash();
}

void K() {
  dash();
  dot();
  dash();
}

void L() {
  dot();
  dash();
  dot();
  dot();
}

void M() {
  dash();
  dash();
}

void N() {
  dash();
  dot();
}

void O() {
  dash();
  dash();
  dash();
}

void P() {
  dot();
  dash();
  dash();
  dot();
}

void Q() {
  dash();
  dash();
  dot();
  dash();
}

void R() {
  dot();
  dash();
  dot();
}

void S() {
  dot();
  dot();
  dot();
}

void T() {
  dash();
}

void U() {
  dot();
  dot();
  dash();
}

void V() {
  dot();
  dot();
  dot();
  dash();
}

void W() {
  dot();
  dash();
  dash();
}

void X() {
  dash();
  dot();
  dot();
  dash();
}

void Y() {
  dash();
  dot();
  dash();
  dash();
}

void Z() {
  dash();
  dash();
  dot();
  dot();
}

void spaceW() {
  //space b/t words is supposed to be 7 in MC
  //but that's too long so let's do
  digitalWrite(led, LOW);
  delay(unit * 5);
}

void spaceL() {
  digitalWrite(led, LOW);
  delay(unit * 2);
}


void setup() {
  pinMode(led, OUTPUT);

}

void loop() {


}
