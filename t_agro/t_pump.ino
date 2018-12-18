void runPump(){
  if(pumpState){
    digitalWrite(pumpPin, HIGH); 
  } else{
    digitalWrite(pumpPin, LOW); 
  }
}
