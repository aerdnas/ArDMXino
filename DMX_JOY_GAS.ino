#include <DmxSimple.h>
#include <JoystickShield.h>

JoystickShield joystickShield;

void setup() {
  Serial.begin(9600);

  DmxSimple.maxChannel(14);
  DmxSimple.usePin(10);      // digital output for DMX serial data
  DmxSimple.write(14, 255);
  DmxSimple.write(14, 0);

  joystickShield.calibrateJoystick();
  joystickShield.onJSCenter(&center);
  joystickShield.onJSnotCenter(&notCenter);

  Serial.println("DMX GAS");
  Serial.println();
  Serial.println("Buttons:");
  Serial.println("A. => dinner mode");
  Serial.println("B. => party mode");
  Serial.println("C. => joystick mode");
  Serial.println();
}

int rotationX = 0;
int rotationY = 110;
int previousMode = 2;

void loop() {
  joystickShield.processEvents();
  if(joystickShield.isUpButton()) {
    Serial.println("A - dinner mode");
    dinnerMode();
  }         
  else if(joystickShield.isRightButton()) {
    Serial.println("B - party mode");
    partyMode();
  } 
  else if(joystickShield.isDownButton()){
    Serial.println("C - joystick mode");
    joystickMode();
  }
  else {
    rotationX = (rotationX == 0) ? 255 : 0;
    rotationY = (rotationY == 110) ? 150 : 110;
    switch(previousMode) {
      case 0: dinnerMode();   break;
      case 1: partyMode();    break;
      case 2: joystickMode(); break;
    }
  }
}

void dinnerMode(){
  previousMode = 0;
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
  previousMode = 1;
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
  previousMode = 2;
  DmxSimple.write(1, 170);
  DmxSimple.write(3, 127);
  DmxSimple.write(5, 0);
  joystickShield.processCallbacks();
  delay(500);
}