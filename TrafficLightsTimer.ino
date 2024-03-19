#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object

int redPin = 0;
int greenPin = 1;
int bluePin = 2;

int long mili = 1000;
int unsigned long zmili = 0;
int number = 30;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  byte numDigits = 4;
  byte digitPins[] = {10, 13, 12, 11};
  byte segmentPins[] = {3, 4, 5, 6, 7, 8, 9};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default 'false' is Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true; // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
}

void loop() {
  unsigned long curmili = millis();
  if (curmili - zmili >= mili) {
    zmili = curmili;
    if (number >= 1) {
      number--;
    } else {number = 30;}
}
  if (number >= 20) {
    setColor(255,0,0);
  }
  
  else if (number >= 10) {if ((number % 2) == 0) {setColor(0,0,0);}
  else {setColor(255,255,0);}}

  else if (number >= 0) {setColor(0,255,0);}

  sevseg.refreshDisplay();
  sevseg.setNumber(number);
}


void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}