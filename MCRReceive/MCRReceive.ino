/*
   handles receiving/translating morse code
*/

/*
 *******************************************************
    variables
 *******************************************************
*/

int unit = 500;
int pr = 5;
int led = 1;
static int dstate = 0;
int pos = 0;
int charpos = 0;

int prlow = 400;
int prhigh = 600;

int timer1start;
int timer1stop;
int timer2start;
int timer2stop;
int timer1;
int timer2;

int letter[4];
char message[100]; //going with a 100 char limit here

/*
 *******************************************************
    function declarations
 *******************************************************
*/

int readpr(int prev);
String translate(int timerval, int isletter);

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
  }
  else {
    if (isletter) {
      if (timerval > (unit / 2) && timerval < (unit * 2)) { //giving it some leeway
        //it's a dot
        letter[pos] = 0;
        pos += 1;
      }
      else if (timerval > (unit * 2)) {
        //it's a dash
        letter[pos] = 1;
        pos += 1;
      }
    }
    else {
      if (timerval > (unit * 1.5) && timerval < (unit * 4)) {
        for (int i = pos + 1; i < 4; i++) {
          letter[i] = 2;
        }
        pos = 0;
        message[charpos] = getmorsechar(letter);
        charpos += 1;
      }
      else if (timerval > (unit * 4)) {
        //add space to message
        message[charpos] = ' ';
        charpos += 1;
        pos = 0;
      }
      else {
        //don't do shit
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
                  return '-';
                case 1:
                  return 'F';
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
                  return '?';
                case 1:
                  return 'L';
                default:
                  return 'R';
              }
            case 1:
              switch (letter[3]) {
                case 0:
                  return 'J';
                case 1:
                  return 'P';
                default:
                  return 'W';
              }
            //wjp
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

  //reading only. will likely have to put in another file altogether
  Serial.print(millis() / 1000.0, 0); //for testing (later)
  Serial.print(',');
  Serial.print(analogRead(pr));
  Serial.print("\n");
  delay(10);

  int newstate = readpr(dstate);
  if (dstate == LOW && newstate == HIGH) {
    timer1start = millis();
    timer2stop = millis();
    timer2 = timer2stop - timer2start;
    c = translate(timer2, 0);
  }
  if (dstate == HIGH && newstate == LOW) {
    timer1stop = millis();
    timer2start = millis();
    timer1 = timer1stop - timer1start;
    c = translate(timer1, 1);
  }
  dstate = newstate;
}
