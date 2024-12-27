/* =============== Joystick Callbacks =============== */

const int joyMin = -100;    // Joystick min input range
const int joyMax = 100;     // Joystick max input range

const int panCenter = 170;  // Pan centre
const int panRange = 45;    // Range Pan (+-45)

const int tiltCenter = 127; // Tilt centre
const int tiltRange = 127;  // Range Tilt (+-125)

const int panChannel = 1;   // Pan channel
const int tiltChannel = 3;  // Tilt channel

void center() {
  DmxSimple.write(3, 127);
}

void notCenter() {
  int joyX = joystickShield.xAmplitude();
  int joyY = joystickShield.yAmplitude();

  joyX = -joyX;
  joyY = -joyY;

  // Mappa i valori normalizzati al range DMX
  int panValue = constrain(panCenter + (joyX * panRange / joyMax), panCenter - panRange, panCenter + panRange);
  int tiltValue = constrain(tiltCenter + (joyY * tiltRange / joyMax), tiltCenter - tiltRange, tiltCenter + tiltRange);

  Serial.print("JoyX:\t");
  Serial.print(joyX);
  Serial.print("\tJoyY:\t");
  Serial.print(joyY);
  Serial.print("\tPan:\t");
  Serial.print(panValue);
  Serial.print("\tTilt:\t");
  Serial.println(tiltValue);

  DmxSimple.write(panChannel, panValue);
  DmxSimple.write(tiltChannel, tiltValue);
}