void dhtRun() {
   dht.read();
    Serial.print("Temperature = ");
    Serial.print(dht.getTemperatureC());
    Serial.println(" C \t");
    Serial.print("Humidity = ");
    Serial.print(dht.getHumidity());
    Serial.println(" %");

    dhtTemp = dht.getTemperatureC(); 
    dhtHum = dht.getHumidity();
}  
