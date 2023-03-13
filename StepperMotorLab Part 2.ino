#include <Stepper.h>

const int stepsPerRevolution = 2048; // change this to fit the number of steps per revolution
const int rolePerMinute = 15; // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

int inputPin = A0; //Potentiomoter is connected to A0
float degreePerStep = 0.1; //Variable is set for how many degree the stepper motor will move per step

int previousStep = 0; //Variable is set for previous Step position
int currentStep = 0; //Variable is set for current Step position

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); // initialize the stepper library on pins 8 through 11:

void setup() {
  myStepper.setSpeed(rolePerMinute);
}

void loop() {
  int potValue = analogRead(inputPin); //Potentiometer is read and value is stored int potValue
  int setAngle = map(potValue, 0, 1023, 0, 180); //Potentiometer value is mapped from 0 to 180 for stepper angle
  int setStep = setAngle / degreePerStep; //Stepper motor is set at at the correct degree based on the angle divided by degreePerStep (0.1)

  if (setStep > currentStep) { //If the Inputted Position value is greater than the Current position then...
    myStepper.step(setStep - currentStep); //Move the step motor to the right
    currentStep = setStep; //In order to prevent the motor from continously rotating the currentStep is set the the setStep
  }
  else if (setStep < currentStep) { //If the Inputted Position value is less than the Current position then...
    myStepper.step(-currentStep + setStep); //Move the step motor to the left
    currentStep = setStep; //In order to prevent the motor from continously rotating the currentStep is set the the setStep
  }
  delay(20); //Delay in order to prevent motor from moving too quickly back and forth
}

