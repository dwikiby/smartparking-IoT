#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>


#define FIREBASE_HOST "nodemcudht11-14d34-default-rtdb.firebaseio.com" //Without http:// or https:// schemes
#define FIREBASE_AUTH "nxrTlBv5ETOgBCRhEBcnLcPBlKPfUEXmrXWgnpwc"
#define WIFI_SSID "przival"
#define WIFI_PASSWORD "rahasia123"

const int infrared1 = D3; //pin sensor infrared
const int infrared2 = D4;
const int infrared3 = D5;
const int infrared4 = D6;

FirebaseData firebaseData;
FirebaseJson json;
void setup() {
  Serial.begin(115200);

  pinMode(infrared1, INPUT);
  pinMode(infrared2, INPUT);
  pinMode(infrared3, INPUT);
  pinMode(infrared4, INPUT);


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void sensorUpdate(){
  String ir1, ir2, ir3, ir4 ;
  ir1 = digitalRead(infrared1);
  ir2 = digitalRead(infrared2);
  ir3 = digitalRead(infrared3);
  ir4 = digitalRead(infrared4);

  // kirim data slot parkir (1)
    if (Firebase.setString(firebaseData, "/IOT/slotparkir1", ir1))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  // kirim data slot parkir (2)

    if (Firebase.setString(firebaseData, "/IOT/slotparkir2", ir2))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  }

  // kirim data slot parkir(3)

  if (Firebase.setString(firebaseData, "/IOT/slotparkir3", ir3))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  } 

  // kirim data slot parkir(4)

  if (Firebase.setString(firebaseData, "/IOT/slotparkir4", ir4))
  {
    Serial.println("PASSED");
    Serial.println("PATH: " + firebaseData.dataPath());
    Serial.println("TYPE: " + firebaseData.dataType());
    Serial.println("ETag: " + firebaseData.ETag());
    Serial.println("------------------------------------");
    Serial.println();
  }
  else
  {
    Serial.println("FAILED");
    Serial.println("REASON: " + firebaseData.errorReason());
    Serial.println("------------------------------------");
    Serial.println();
  } 
}

void loop() {
  sensorUpdate();
  delay(1000);
}
