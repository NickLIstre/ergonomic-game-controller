#include<Keyboard.h>


const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
int x, y;


void setup() 
{
  pinMode(SW_pin, INPUT); // SW pin set as input
  digitalWrite(SW_pin, HIGH); // A high value is written to SW pin
  Serial.begin(115200);

  //Configure pins as an input and enable the internal pull-up resistor,
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  Keyboard.begin();
}


void loop() 
{
  //If corresponding button is pressed
  if (digitalRead(3) == LOW) {
    //Send an ASCII 'W',
    Keyboard.write('u');
   // Serial.println(“w was pushed”);
  }
 if (digitalRead(4) == LOW) {
    //Send an ASCII 'A'
    Keyboard.write('i');
   // Serial.println(“a was pushed”);
  }
 if (digitalRead(5) == LOW) {
    //Send an ASCII 'S',
    Keyboard.write('o');
    //Serial.println(“S was pushed”);
  }

 if (digitalRead(6) == LOW) {
    //Send an ASCII 'D',
    Keyboard.write('p');
   // Serial.println(“D was pushed”);
  }
 else {
    Keyboard.releaseAll();
}

  x = analogRead(X_pin); // output of X_pin is read
  if (x == 1023) // check whether the value of x = 1023
  {
    Serial.println("Up:");
    Keyboard.press(218); // key moves up
  }
  else
  {
   Keyboard.release(218);  // release the key
  }
  x = analogRead(X_pin);  // output of X_pin is read
  if (x == 0) // check whether the value of x = 0
  {
    Serial.println("Down:");
    Keyboard.press(217); // key moves down
  }
  else
  {
    Keyboard.release(217);  // release the key
  }
  y = analogRead(Y_pin);  // output of Y_pin is read
    if (y == 1023) // check whether the value of  y = 1023
    {
      Serial.println("Right:"); 
      Keyboard.press(216); // key moves right
    }
    else
    {
     Keyboard.release(216);  // release the key
    }
  y = analogRead(Y_pin); // output of Y_pin is read
    if (y == 0) // check whether the value of y = 0
    {
      Serial.println("Left:");
      Keyboard.press(215); // key moves left
  }
  else
  {
    Keyboard.release(215);  // release the key
  }
  int z = digitalRead(SW_pin); // read the value of SW pin
    if (z == 0) //check whether the value of z = 0
    {
      Serial.println("Enter:");
      Keyboard.println(); //enter key is pressed
   }
  delay(500);
}
