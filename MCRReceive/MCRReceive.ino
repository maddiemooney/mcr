/*
 * handles receiving/translating morse code
 */

int unit = 500;
int pr = 5;
int led = 1;
static int dstate = 0;

int prlow = 400;
int prhigh = 600;

int timer1start;
int timer1stop;
int timer2start;
int timer2stop;
int timer1;
int timer2;

int letter[4];

int readpr(int prev);

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

}

void loop() {
  char c;

  //reading only. will likely have to put in another file altogether
  Serial.print(millis()/1000.0,0); //for testing (later)
  Serial.print(',');
  Serial.print(analogRead(pr));
  Serial.print("\n");
  delay(10);

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
