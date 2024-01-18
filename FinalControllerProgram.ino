// Final program
#include <Joystick.h>

#define joyX A0
#define joyY A1
#define joyButton1 6
#define joyButton2 7
#define joyButton3 8
#define joyButton4 9
#define joyButton5 10
#define joyButton6 11
#define joyButton7 12
#define joyButton8 13
#define joyButton9 A2
#define joyButton10 A3
#define startButton A4
#define selectButton A5

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  16, 0,                  // Button Count, Hat Switch Count
  true, true, false,     // X and Y, but no Z Axis
  true, true, false,      // Rx, Ry, but no Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

const bool initAutoSendState = true;
int RxAxis_ = 0;
int RyAxis_ = 0;

int lastButton1State = 0;
int lastButton2State = 0;
int lastButton3State = 0;
int lastButton4State = 0;
int lastButton5State = 0;
int lastButton6State = 0;
int lastButton7State = 0;
int lastButton8State = 0;
int lastButton9State = 0;
int lastButton10State = 0;
int lastButtonStartState = 0;
int lastButtonSelectState = 0;

void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP); // Left
  pinMode(3, INPUT_PULLUP); // Right
  pinMode(4, INPUT_PULLUP); // Down
  pinMode(5, INPUT_PULLUP); // Up
  pinMode(joyButton1, INPUT_PULLUP);
  pinMode(joyButton2, INPUT_PULLUP);
  pinMode(joyButton3, INPUT_PULLUP);
  pinMode(joyButton4, INPUT_PULLUP);
  pinMode(joyButton5, INPUT_PULLUP);
  pinMode(joyButton6, INPUT_PULLUP);
  pinMode(joyButton7, INPUT_PULLUP);
  pinMode(joyButton8, INPUT_PULLUP);
  pinMode(joyButton9, INPUT_PULLUP);
  pinMode(joyButton10, INPUT_PULLUP);
  pinMode(startButton, INPUT_PULLUP);
  pinMode(selectButton, INPUT_PULLUP);

  // Initialize Joystick Library
  Joystick.begin();
  Joystick.setXAxisRange(-1, 1);
  Joystick.setYAxisRange(-1, 1);
  Joystick.setRxAxisRange(0, 255);
  Joystick.setRyAxisRange(0, 255);
}

// Last state of the buttons
int lastButtonState[10] = {0,0,0,0,0,0,0,0,0,0};

void loop() {
//Axis Runtime
RxAxis_ = analogRead(joyX);
RxAxis_ = map(RxAxis_, 0, 1023, 0, 255);
Joystick.setRxAxis(RxAxis_);

RyAxis_ = analogRead(joyY);
RyAxis_ = map(RyAxis_, 0, 1023, 0, 255);
Joystick.setRyAxis(RyAxis_);

  // Read pin values
  for (int index = 0; index < 4; index++)
  {
    int currentButtonState = !digitalRead(index + 2);
    if (currentButtonState != lastButtonState[index])
    {
      switch (index) {
        case 0: // Left
          if (currentButtonState == 1) {
            Joystick.setXAxis(-1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 1: // Right
          if (currentButtonState == 1) {
            Joystick.setXAxis(1);
          } else {
            Joystick.setXAxis(0);
          }
          break;
        case 2: // Down
          if (currentButtonState == 1) {

            Joystick.setYAxis(1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
        case 3: // Up
          if (currentButtonState == 1) {
              Joystick.setYAxis(-1);
          } else {
            Joystick.setYAxis(0);
          }
          break;
                }
      lastButtonState[index] = currentButtonState;
    }
  }

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
int currentButton5State = !digitalRead(joyButton5);
if(currentButton5State != lastButton5State) {
	Joystick.setButton (4, currentButton5State);
	lastButton5State = currentButton5State;
}
int currentButton6State = !digitalRead(joyButton6);
if(currentButton6State != lastButton6State) {
	Joystick.setButton (5, currentButton6State);
	lastButton6State = currentButton6State;
}
int currentButton7State = !digitalRead(joyButton7);
if(currentButton7State != lastButton7State) {
	Joystick.setButton (6, currentButton7State);
	lastButton7State = currentButton7State;
}
int currentButton8State = !digitalRead(joyButton8);
if(currentButton8State != lastButton8State) {
	Joystick.setButton (7, currentButton8State);
	lastButton8State = currentButton8State;
}
int currentButton9State = !digitalRead(joyButton9);
if(currentButton9State != lastButton9State) {
	Joystick.setButton (8, currentButton9State);
	lastButton9State = currentButton9State;
}
int currentButton10State = !digitalRead(joyButton10);
if(currentButton10State != lastButton10State) {
	Joystick.setButton (9, currentButton10State);
	lastButton10State = currentButton10State;
}
// Start and Select Buttons
int currentButtonStartState = !digitalRead(startButton);
if(currentButtonStartState != lastButtonStartState) {
	Joystick.setButton (10, currentButtonStartState);
	lastButtonStartState = currentButtonStartState;
}
int currentButtonSelectState = !digitalRead(selectButton);
if(currentButtonSelectState != lastButtonSelectState) {
	Joystick.setButton (11, currentButtonSelectState);
	lastButtonSelectState = currentButtonSelectState;
}
  delay(10);
}