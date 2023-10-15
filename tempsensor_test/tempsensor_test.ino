/* Example code for AM2320 I2C temperature and humidity sensor with Arduino. More info: www.www.makerguides.com */

//  Include the required libraries:
#include <Adafruit_Sensor.h>
#include <Adafruit_AM2320.h>

// Create a new instance of the Adafruit_AM2320 class:
Adafruit_AM2320 AM2320 = Adafruit_AM2320();

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);

  // Setup the sensor;
  AM2320.begin();
}

void loop() {
  // Read the temperature and the humidity:
  float tempC = AM2320.readTemperature();
  float tempF = tempC * 1.8 + 32; // converts Celsius to Fahrenheit
  float humidity = AM2320.readHumidity();

  // Print the temperature and humidity in the Serial Monitor:
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.print("C  |  ");
  Serial.print(tempF);
  Serial.print(" \xC2\xB0"); // shows degree symbol
  Serial.println("F");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %RH");

  // Wait 2 seconds between readings:
  delay(2000);
}