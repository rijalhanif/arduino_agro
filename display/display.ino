#include <Nextion.h>

int var = 1000;
int varEdit = var*(0.005)*1000;
int calValueTemp = 0;
int calValue = 0;

int currentPage = 0;
int pageSign = 0;

// Page 1
NexButton b1 = NexButton(0, 4, "b1");  // Button added
NexButton b0 = NexButton(0, 3, "b0");  // Button added
NexButton b2 = NexButton(0, 5, "b2");
// Page 2
NexButton bHome = NexButton(1, 5, "bHome");
NexButton bUp  = NexButton(1,8,"bUp");
NexButton bDown = NexButton(1,9,"bDown");
NexButton bCalibrate = NexButton(1,10,"bCalibrate");

NexPage page0 = NexPage(0, 0, "page0");
NexPage page1 = NexPage(1, 0, "page1");

NexTouch *nex_listen_list[] = {
  &b1, 
  &b0, 
  &b2, 
  &bHome, 
  &page0, 
  &page1, 
  &bUp,
  &bDown,
  &bCalibrate,
  NULL
};

void b1PushCallback(void *ptr){
  digitalWrite(LED_BUILTIN, LOW);
  var = var - 10;
}

void b0PushCallback(void *ptr){
  digitalWrite(LED_BUILTIN, HIGH);
  var = var + 10;
}

void b2PushCallback(void *ptr){
  pageSign = 1;
}

void bHomePushCallback(void *ptr){
  pageSign = 0;
}

void bUpPushCallback(void *ptr){
  calValueTemp = calValueTemp + 1;
  if(calValueTemp > 14){
    calValueTemp = 0;
  }
}

void bDownPushCallback(void *ptr){
  calValueTemp = calValueTemp - 1;
  if(calValueTemp < 0){
    calValueTemp = 14;
  }
}

void bCalibratePushCallback(void *ptr){
  calValue = calValueTemp;
}

void page0PushCallback(void *ptr){
  currentPage = 0;
}

void page1PushCallback(void *ptr){
  currentPage = 1;
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(500);
  
  b1.attachPush(b1PushCallback);
  b0.attachPush(b0PushCallback);
  b2.attachPush(b2PushCallback);
  bHome.attachPush(bHomePushCallback);
  bUp.attachPush(bUpPushCallback);
  bDown.attachPush(bDownPushCallback);
  bCalibrate.attachPush(bCalibratePushCallback);
  page0.attachPush(page0PushCallback);  // Page press event
  page1.attachPush(page1PushCallback);
}

void loop() {
  if(pageSign == 0){
    Serial.print("n0.val=");
    Serial.print(var);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  } else if(pageSign == 1){
    Serial.print("nVoltValue.val=");
    Serial.print(var);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    delay(30);
    
    Serial.print("nPHValue.val=");
    Serial.print(calValue);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);

    delay(30);
    
    Serial.print("nCalValue.val=");
    Serial.print(calValueTemp);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
  }
  
  delay(30);

  nexLoop(nex_listen_list);

}
