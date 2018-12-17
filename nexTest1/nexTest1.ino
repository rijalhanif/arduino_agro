#include <Nextion.h>

int var = 30;
int currentPage = 0;

NexButton b1 = NexButton(0, 4, "b1");  // Button added
NexButton b0 = NexButton(0, 3, "b0");  // Button added

NexPage page0 = NexPage(0, 0, "page0");

NexTouch *nex_listen_list[] = {&b1, &b0, &page0, NULL};

void b1PushCallback(void *ptr){
  digitalWrite(LED_BUILTIN, LOW);
  var = var - 10;
}

void b0PushCallback(void *ptr){
  digitalWrite(LED_BUILTIN, HIGH);
  var = var + 10;
}

void page0PushCallback(void *ptr){
  int  CurrentPage = 0;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

  delay(500);
  
  b1.attachPush(b1PushCallback);
  b0.attachPush(b0PushCallback);
  page0.attachPush(page0PushCallback);  // Page press event
}

void loop() {
  // put your main code here, to run repeatedly:

//  if(var < 500){
//    var = var + 10;
//  } else{
//    var = 10;
//  }

  Serial.print("n0.val=");
  Serial.print(var);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);

  delay(500);

  nexLoop(nex_listen_list);

}
