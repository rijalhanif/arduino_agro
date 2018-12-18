// void phRun(int pin) {
//   for(int i=0;i<10;i++) { 
//     buf[i]=analogRead(pin);
//     delay(10);
//   }
//   for(int i=0;i<9;i++){
//     for(int j=i+1;j<10;j++){
//       if(buf[i]>buf[j]){
//           temp=buf[i];
//           buf[i]=buf[j];
//           buf[j]=temp;
//       }
//     }
//   }
  
//   avgValue=0;
  
//   for(int i=2;i<8;i++)
//   avgValue+=buf[i];
//   float pHVol=(float)avgValue*5.0/1024/6;
//   float phValue = -5.70 * pHVol + 21.34;
//   Serial.print("ph sensor = ");
//   Serial.println(phValue);
// }

void phRun(int pin){
  float phValue = pin * (7/512);
  Serial.print("ph sensor = ");
  Serial.println(phValue);

  phSn = phValue;
}
