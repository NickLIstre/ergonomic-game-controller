// The digital pins 9, 10, 11, and 12 are grounded when they are pressed.

#include <Joystick.h>

#define joyX A0
#define joyY A1
#define joyButton1 9
#define joyButton2 10
#define joyButton3 11
#define joyButton4 12

Joystick_ Joystick(0x15,JOYSTICK_TYPE_JOYSTICK,
  4, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

const bool initAutoSendState = true;
int xAxis_ = 0;
int yAxis_ = 0;

int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;

void setup() {
  // Initialize Button Pins

  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(0, 255);
  Joystick.setYAxisRange(0, 255);
}

void loop() {
//Axis Runtime
xAxis_ = analogRead(joyX);
xAxis_ = map(xAxis_, 0, 1023, 0, 255);
Joystick.setXAxis(xAxis_);

yAxis_ = analogRead(joyY);
yAxis_ = map(yAxis_, 0, 1023, 0, 255);
Joystick.setYAxis(yAxis_);

  // Buttons
int currentButton1State = !digitalRead(joyButton1);

if(currentButton1State != lastButton1State) {
	Joystick.setButton (0, currentButton1State);
	lastButton1State = currentButton1State;
}
int currentButton2State = !digitalRead(joyButton2);
if(currentButton2State != lastButton2State) {
	Joystick.setButton (1, currentButton2State);
	lastButton2State = currentButton2State;
}
int currentButton3State = !digitalRead(joyButton3);
if(currentButton3State != lastButton3State) {
	Joystick.setButton (2, currentButton3State);
	lastButton3State = currentButton3State;
}
int currentButton4State = !digitalRead(joyButton4);
if(currentButton4State != lastButton4State) {
	Joystick.setButton (3, currentButton4State);
	lastButton4State = currentButton4State;
}
// Pole Delay/Debounce
delay(10);
}