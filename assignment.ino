// Temperature sensor
const float B = 3435;

const float R0 = 10000;
const float ABS_ZERO = -273.15;
const float T0 = 25-ABS_ZERO;

float calculateTemperature(float resistance) {
  return 1.0 / (log(resistance/R0)/B+1.0/T0) + ABS_ZERO;
}

float convertTemperatureFahrenheit(float tDegree) {
  return tDegree/5.0*9.0 + 32.0;
}

// Fixed resistor in voltage divider
const float R_FIXED = 10000;

float calculateSensorResistance(float voltage) {
  return R_FIXED / (5.0/voltage - 1);
}

void setup() {
  // Init Serial Port
  Serial.begin(9600);
}

void loop() {
  // Measurements and Calculations

  digitalWrite(A0, HIGH);
  //delay(30);
  //float voltage = analogRead(A0)*5/1024.0;
  //digitalWrite(A0, LOW);
  //delay(30);
  float resistance = calculateSensorResistance(voltage);
  float temperature = calculateTemperature(resistance);
  float temperatureF = convertTemperatureFahrenheit(temperature);
  
  // Print out result
  Serial.print("Voltage (V): ");
  Serial.println(voltage);
  
  Serial.print("Resistance (Ohm): ");
  Serial.println(resistance);
  
  Serial.print("Temperature (°C): ");
  Serial.println(temperature);

  Serial.print("Temperature (°F): ");
  Serial.println(temperatureF);

  // Wait for 1s
  delay(1000);
}