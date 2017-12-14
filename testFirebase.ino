#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#define FIREBASE_HOST "test1-dae3c.firebaseio.com"
#define FIREBASE_KEY "8q5RIWzDq3f6sO68vgP0XABSvF4VChtb8608YHDv"
#define WIFI_SSID "iPad"
#define WIFI_PASSWORD "mimimiml2"
int up = D1;
int down = D2;
void setup() {

pinMode(up,OUTPUT);
pinMode(down,OUTPUT);

Serial.begin(115200);
WiFi.mode(WIFI_STA);
WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
while (WiFi.status() != WL_CONNECTED){
    delay(500);
}
Firebase.begin(FIREBASE_HOST, FIREBASE_KEY);
Firebase.set("up",0);
Firebase.set("down",0);
Firebase.set("lift",0);
Firebase.set("rigth",0);
}
void loop() {
  int upFirebase = Firebase.getInt("up");
  int downFirebase = Firebase.getInt("down");
  if(upFirebase == 1 && downFirebase == 0){
    analogWrite(up,1024);
    analogWrite(down,0);
  }else if (upFirebase == 0 && downFirebase == 1){
    analogWrite(up,0);
    analogWrite(down,1024);
  }else if (upFirebase == 0 && downFirebase == 0){
    analogWrite(up,0);
    analogWrite(down,0);
  }
}
