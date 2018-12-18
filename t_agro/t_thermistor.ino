void thermistorRun(unsigned int pin){
  unsigned int analogValue;
  analogValue = analogRead(pin);
  Serial.print("Thermistor : ");
  Serial.println(analogValue);

  thermSn = analogValue;
}
