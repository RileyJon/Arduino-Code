//RGB Light Pin Variables
int RedPin= 11; 
int GreenPin= 10;
int BluePin= 9;

//Button Pin Variable
int ButtonPin = 2;

//Random Number Variables
int RandNum1;
int RandNum2;
int RandNum3;

//Button On or Off Variable
int ButtonBoolean;

//Debounce Variables
long LastDebounceTime = 0;
long DebounceDelay = 150; //Set to 150 milliseconds for each Button Press (If increased it will less likely switch bounce will occur)
int LedMode = 1; //Set to 1 so the Arduino Starts in the "Off Mode"


void setup() {
  pinMode(ButtonPin, INPUT); //Button is an input
  pinMode(RedPin, OUTPUT); //Red Pin is an Output 
  pinMode(GreenPin, OUTPUT); //Green Pin is an Output
  pinMode(BluePin, OUTPUT); //Blue Pin is an Output

}

void loop() {

 
  ButtonBoolean = digitalRead(ButtonPin); //Sets Button On/Off Variable if Pushed


  if ( (millis() - LastDebounceTime) > DebounceDelay)  { //Adds a Time Buffer to Prevent Switch Bouncing

    if ( (ButtonBoolean == HIGH) && (LedMode == 1) ) { //If the Button is Pressed and the LedMode is set to 1 then display the Color Blue Mode

      delay(100); //Delay for 1 second

      //digitalWrite is used to send either Low (0) or High (1) to each RGB pin --> In this case all are Low except for Blue 
      digitalWrite(RedPin, LOW); 
      digitalWrite(GreenPin, LOW);
      digitalWrite(BluePin, HIGH);

      LastDebounceTime = millis(); //LastDebounceTime is set to the Current Time
      
      LedMode = 2; //Change LedMode to 2 for Random to Occur on the Next Button Press
    }
    else if ( (ButtonBoolean == HIGH) && (LedMode == 2) ) { //If the Button is Pressed and the LedMode is set to 2 then display the Random Color Mode

      int RandNum1 = random(0,255); //random number is set on each loop for Red
      int RandNum2 = random(0,255); //random number is set on each loop for Green
      int RandNum3 = random(0,255); //random number is set on each loop for Blue

      delay(100); //Delay for 1 second

      //analogWrite is used to send percentage to each Light Pin based on a random value (This value will be done through PWM)
      analogWrite(RedPin, RandNum1);
      analogWrite(GreenPin, RandNum2);
      analogWrite(BluePin, RandNum3);

      LastDebounceTime = millis(); //LastDebounceTime is set to the Current Time

      LedMode =0; //Change LedMode to 0 for Off to Occur on the Next Button Press
    }
     else if ( (ButtonBoolean == HIGH) && (LedMode == 0) ) { //If the Button is Pressed and the LedMode is set to 0 then display the Off Mode

      delay(100); //Delay for 1 second

      //digitalWrite is used to send either Low (0) or High (1) to each RGB pin --> In this case all are Low 
      digitalWrite(RedPin, LOW);
      digitalWrite(GreenPin, LOW);
      digitalWrite(BluePin, LOW);

      LastDebounceTime = millis(); //LastDebounceTime is set to the Current Time

      LedMode =1; //Change LedMode to 1 for On to Occur on the Next Button Press
     }

  }//Close If for the Time Buffer to Prevent Switch Bouncing

}
