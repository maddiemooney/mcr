/*
   handles receiving/translating morse code
*/

/*
 *******************************************************
    variables
 *******************************************************
*/

int unit = 100;
int pr = A0;
int led = 6;
static int dstate = 0;
int pos = 0;
int charpos = 0;

int prlow = 950;
int prhigh = 980;

int timer1start;
int timer1stop;
int timer2start;
int timer2stop;
int timer1;
int timer2;

int letter[4];
char message[6] = {' ',' ',' ',' ',' ',' '}; //going with a 6 char limit here

/*
 *******************************************************
    function declarations
 *******************************************************
*/

int readpr(int prev);
String translate(int timerval, int isletter);
char getmorsechar(int letter[]);

/*
 *******************************************************
    subroutines
 *******************************************************
*/

int readpr(int prev) {
  int state = analogRead(pr);
  if (prev == LOW && state >= prhigh) {
    return HIGH;
  }
  else if (prev == HIGH && state  < prlow) {
    return LOW;
  }
  else {
    return prev;
  }
}

String translate(int timerval, int isletter) {
  if (charpos > 98) {
    //Serial.println("shouldn't");
  }
  else {
    if (isletter) {
      if (timerval > (unit / 2) && timerval < (unit * 2)) { //giving it some leeway
        //it's a dot
        Serial.println("dot");
        letter[pos] = 0;
        pos += 1;
      }
      else if (timerval > (unit * 2)) {
        //it's a dash
        Serial.println("dash");
        letter[pos] = 1;
        pos += 1;
      }
    }
    else {
      if (timerval > (unit * 1.5) && timerval < (unit * 4)) {
        for (int i = pos + 1; i < 4; i++) {
          letter[i] = 2;
        }
        Serial.println("eol");
        pos = 0;
        message[charpos] = getmorsechar(letter);
        charpos += 1;
      }
      else if (timerval > (unit * 4)) {
        //add space to message
        Serial.println("eow");
        message[charpos] = ' ';
        for(int k = 0;k<=5;k++){
          Serial.print(message[k]);
        }
        Serial.print("\n");
        charpos += 1;
        pos = 0;
      }
      else {
        //don't do shit
        //Serial.println("waiting");
      }
    }
  }
}

char getmorsechar(int letter[]) {
  switch (letter[0]) {
    case 0:
      switch (letter[1]) {
        case 0:
          switch (letter[2]) {
            case 0:
              switch (letter[3]) {
                case 0:
                  return 'H';
                case 1:
                  return 'V';
                default:
                  return 'S';
              }
            case 1:
              switch (letter[3]) {
                case 0:
                  return 'F';
                case 1:
                  return '?';
                default:
                  return 'U';
              }
            default:
              return 'I';
          }
        case 1:
          switch (letter[2]) {
            case 0:
              switch (letter[3]) {
                case 0:
                  return 'L';
                case 1:
                  return '?';
                default:
                  return 'R';
              }
            case 1:
              switch (letter[3]) {
                case 0:
                  return 'P';
                case 1:
                  return 'J';
                default:
                  return 'W';
              }
            default:
              return 'A';
          }
        default:
          return 'E';
      }
    case 1:
      switch (letter[1]) {
        case 0:
          switch (letter[2]) {
            case 0:
              switch (letter[3]) {
                case 0:
                  return 'B';
                case 1:
                  return 'X';
                default:
                  return 'D';
              }
            case 1:
              switch (letter[3]) {
                case 0:
                  return 'C';
                case 1:
                  return 'Y';
                default:
                  return 'K';
              }
            default:
              return 'N';
          }
        case 1:
          switch (letter[2]) {
            case 0:
              switch (letter[3]) {
                case 0:
                  return 'Z';
                case 1:
                  return 'Q';
                default:
                  return 'G';
              }
            case 1:
              return 'O';
            default:
              return 'M';
          }
        default:
          return 'T';
      }
    default:
      return '?';

  }
}


void setup() {
  Serial.begin(9600);

}

void loop() {
  String c;
  
  /*Serial.print(millis() / 1000.0, 2); //for testing (later)
  Serial.print(',');
  Serial.print(analogRead(pr));
  Serial.print("\n");
  delay(1000);*/

  
  int newstate = readpr(dstate);
  if (dstate == LOW && newstate == HIGH) {
    //Serial.print("on");
    timer1start = millis();
    timer2stop = millis();
    timer2 = timer2stop - timer2start;
    //Serial.print(timer2);
    //Serial.print("\n");
    c = translate(timer2, 0);
  }
  if (dstate == HIGH && newstate == LOW) {
    //Serial.print("off");
    timer1stop = millis();
    timer2start = millis();
    timer1 = timer1stop - timer1start;
    //Serial.print(timer1);
    //Serial.print("\n");
    c = translate(timer1, 1);
  }
  dstate = newstate;
  
}
