/*
 FASHION/TECH HACKATHON
*/

// Connect the S tab of the Temperature Sensor to A3
// If using the LilyPad ProtoSnap Plus, change to A9
 int sensorPin = A3;
 int alertLED = 13;

 int relayPin = 10;

 int heatPin = 9;

// Set temperature threshold variable to check against. If the temperature reading is above
// this number in degrees Fahrenheit, the LED will turn on
 int threshold =  80; // 80 degrees Fahrenheit

void setup()
{
  // Set the temperature sensor pin as an INPUT:
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);

  // Set pin A5 to use as a power pin for the light sensor
  // If using the LilyPad Development Board or the + tab for power, comment out these lines of code
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  pinMode(relayPin, OUTPUT);


// Make the built-in LED an OUTPUT
  pinMode(alertLED, OUTPUT);

// Make 9 a Heat PIN
  pinMode(heatPin, OUTPUT);
  //digitalWrite(heatPin, HIGH);
  
  // Initialize Serial, set the baud rate to 9600 bps.
  Serial.begin(9600);
}

void loop()
{
  // Variable to store raw temperature
  long rawTemp;

  // Variable to store voltage calculation
  float voltage;

  // Variable to store Fahrenheit value
  float fahrenheit;

  // Variable to store Celsius value
  float celsius;

  // Read the raw 0-1023 value of temperature into a variable.
  rawTemp = analogRead(sensorPin);

  Serial.println(rawTemp);

  // Calculate the voltage, based on that value.
  // Multiply by maximum voltage (3.3V) and divide by maximum ADC value (1023).
  // If you plan on using this with a LilyPad Simple Arduino on USB power, change to 4.2
  voltage = rawTemp * (3.3 / 1023.0);
  
  // Calculate the celsius temperature, based on that voltage..
  celsius = (voltage - 0.5) * 100;
  
  // Use a common equation to convert celsius to Fahrenheit. F = C*9/5 + 32.
  fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
  Serial.println(fahrenheit);
  
  // Check the temperature, and turn on the LEDs associated with the hot or cold thresholds
  if (fahrenheit >= threshold) // If the temperature rises above the threshold:
  {
    digitalWrite(alertLED, HIGH); // Turn the LED on
    
  } else {
    digitalWrite(alertLED, LOW);//Turn the LED off
    digitalWrite(heatPin, HIGH);//Heat Pin activates
  }
  // Wait 1 second between readings
  delay(1000);  
}
