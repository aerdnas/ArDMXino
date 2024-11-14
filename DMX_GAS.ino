#include <DmxSimple.h>

//const int modeBtnPin = 4;
//const int lockJBtnPin = 5;
//const int colorJBtnPin = 6;
//const int emptyBtnPin = 7;

void setup() {
  Serial.begin(9600);

  DmxSimple.maxChannel(14);
  DmxSimple.usePin(3);      // digital output for DMX serial data
  DmxSimple.write(14, 255);
  DmxSimple.write(14, 0);

  //pinMode(modeBtnPin, INPUT);
  //pinMode(lockJBtnPin, INPUT);
  //pinMode(colorJBtnPin, INPUT);
  //pinMode(emptyBtnPin, INPUT);

  Serial.println("DMX GAS");
  Serial.println();
  Serial.println("Modes:");
  Serial.println("1. => dinner mode");
  Serial.println("2. => party mode");
  Serial.println("3. => joystick mode");
  Serial.println();
}

int rotationX = 0;
int rotationY = 110;
int value = 0;
int mode = 2;

int modeBtnState;           // Stato attuale del bottone
int lastModeBtnState = LOW; // Stato precedente del bottone
int counter = 0;            // Contatore delle pressioni

void loop() {
  int c;

  /*if (modeBtnState == HIGH && lastModeBtnState == LOW) {
    delay(50); // Debounce
    counter++; // Incrementa il contatore

    if (counter > 4) {
      counter = 1;
    }
  }
  if (mode != counter){
    mode = counter;
    DmxSimple.write(14, 255);
    DmxSimple.write(14, 0);
    Serial.println("Switched to mode " + mode);
    Serial.println();
  }
  switchMode();*/
  
  if (Serial.available() > 0) {
    c = Serial.read();
    if ((c >= '0') && (c <= '9')) {
      value = 10 * value + c - '0';
    } else {
      if (c == '.') {
        mode = value;
        DmxSimple.write(14, 255);
        DmxSimple.write(14, 0);
        Serial.println("Switched to mode " + mode);
        Serial.println();
        switchMode();
      }
      value = 0;
    }
  } else {
    switchMode();
  }
}

void switchMode(){
  rotationX = (rotationX == 0) ? 255 : 0;
  rotationY = (rotationY == 110) ? 150 : 110;
  switch(mode) {
    case 1: dinnerMode(); break;
    case 2: partyMode(); break;
    case 3: joystickMode(); break;
    default: delay(1000); break;
  }
}

void dinnerMode(){
  DmxSimple.write(1, rotationX);
  DmxSimple.write(3, rotationY);
  DmxSimple.write(5, 230);
  DmxSimple.write(6, 255);
  DmxSimple.write(7, 190);
  DmxSimple.write(8, 130);
  DmxSimple.write(9, 40);
  DmxSimple.write(10, 10);
  DmxSimple.write(11, 0);
  DmxSimple.write(13, 0);
  delay(18000);
}

void partyMode(){
  DmxSimple.write(1, rotationX);
  DmxSimple.write(3, 128);
  DmxSimple.write(5, 200);
  DmxSimple.write(6, 255);
  DmxSimple.write(7, 0);
  DmxSimple.write(8, 0);
  DmxSimple.write(9, 0);
  DmxSimple.write(10, 0);
  DmxSimple.write(11, 255);
  DmxSimple.write(12, 190);
  DmxSimple.write(13, 0);
  delay(8000);
}

void joystickMode(){
  DmxSimple.write(1, rotationX);
  DmxSimple.write(3, rotationY);
  DmxSimple.write(5, 255);
  DmxSimple.write(6, 255);
  DmxSimple.write(7, 190);
  DmxSimple.write(8, 130);
  DmxSimple.write(9, 40);
  DmxSimple.write(10, 10);
  DmxSimple.write(11, 0);
  DmxSimple.write(13, 0);
  delay(18000);
}