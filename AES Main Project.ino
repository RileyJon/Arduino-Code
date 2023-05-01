#include <DHT.h> //DHT library for the sensor
#include <LiquidCrystal.h> //LiquidCrystal library for the 16x2 display

#define SENSOR_PIN 7 //Temp Sensor Pin
#define FAN_PIN 10 //Fan Pin
#define POT_PIN A0 //Potentiometer Pin

#define DHT_TYPE DHT11 // Define the DHT sensor type (DHT11)

DHT dht(SENSOR_PIN, DHT_TYPE); //Instance of the DHT library for the sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Instance of the LiquidCrystal library for the display


void setup() {
 
  lcd.begin(16, 2);// Set up the display

  pinMode(FAN_PIN, OUTPUT); // Set up the fan pin

  dht.begin(); // Initialize the DHT sensor
}

void loop() {
  float temperatureC = dht.readTemperature(); // Read the temperature and humidity from the sensor

  float temperatureF = (temperatureC * 1.8) + 32; // Convert Celsius to Fahrenheit - (To account for sensor error I had to adjust 32 to 22 in the Temp Conversion Formula)

  float potValue = analogRead(POT_PIN);   // Read the potentiometer value

  float fanThreshold = map(potValue, 0, 1023, 15, 32); // Map the potentiometer value to the fan threshold temperature range (20-32 degrees Celsius)

  float settemperatureF = (fanThreshold * 1.8) + 32; // Convert Celsius to Fahrenheit - (To account for sensor error I had to adjust 32 to 22 in the Temp Conversion Formula)

  // Print the temperature and fan threshold values to the display
  lcd.setCursor(0, 0); //First Row
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print("F");

  lcd.setCursor(0, 1); //Second Row
  lcd.print("Set Temp: ");
  lcd.print(settemperatureF);
  lcd.print("F");

  // Check if the temperature is above the fan threshold
  if (temperatureF > settemperatureF) {
    digitalWrite(FAN_PIN, HIGH);     // Turn on the fan
  } else {
    digitalWrite(FAN_PIN, LOW);  // Turn off the fan
  }
  delay(500); //Delay before Repeating
}
