#include <Servo.h>

Servo myCoolServo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myCoolServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    myCoolServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       //delay has been changed to 30 ms
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myCoolServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       //delay has been changed to 30 ms
  }
 
}

