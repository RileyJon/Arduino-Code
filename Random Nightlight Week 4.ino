int RedPin= 11;
int GreenPin= 10;
int BluePin= 9;
int ButtonPin = 2;
int RandNum1;
int RandNum2;
int RandNum3;
int ButtonBoolean;
long LastDebounceTime = 0;
long DebounceDelay = 50;
int BlueState = 0;

void setup() {
  pinMode(ButtonPin, INPUT);
  pinMode(RedPin, OUTPUT);
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);

}
void loop() {

  //sample the state of the button - is it pressed or not?
  ButtonBoolean = digitalRead(ButtonPin);

  //filter out any noise by setting a time buffer
  if ( (millis() - LastDebounceTime) > DebounceDelay) {

    //if the button has been pressed, lets toggle the LED from "off to on" or "on to off"
    if ( (ButtonBoolean == HIGH) && (BlueState == 2) ) {

      delay(100);
      digitalWrite(RedPin, LOW);
      digitalWrite(GreenPin, LOW);
      digitalWrite(BluePin, HIGH);
  
      

      LastDebounceTime = millis(); //set the current time
      BlueState = 1;
    }
    else if ( (ButtonBoolean == HIGH) && (BlueState == 1) ) {
      delay(100);
      const int RandNum1 = random(0,255);
      const int RandNum2 = random(0,255);
      const int RandNum3 = random(0,255);
      analogWrite(RedPin, RandNum1);
      analogWrite(GreenPin, RandNum2);
      analogWrite(BluePin, RandNum3);

      
      LastDebounceTime = millis(); //set the current time
      BlueState =0;
    }
     else if ( (ButtonBoolean == HIGH) && (BlueState == 0) ) {
      delay(100);
      digitalWrite(RedPin, LOW);
      digitalWrite(GreenPin, LOW);
      digitalWrite(BluePin, LOW);
       LastDebounceTime = millis(); //set the current time
      BlueState =2;
     }

  }//close if(time buffer)

}//close void loop
