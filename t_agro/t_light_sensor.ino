void lightRun(int pin){
  unsigned int analogValue;
  analogValue = analogRead(pin);
  Serial.print("Photosensitive : ");
  Serial.println(analogValue);

  lightSn = analogValue;

  if(analogValue<100){
    digitalWrite(pumpPin, HIGH); 
  } else {
    digitalWrite(pumpPin, LOW); 
  }
}
