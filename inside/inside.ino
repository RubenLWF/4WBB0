#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

#include "config.h"

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

//Variable to save USER UID
String uid;

String databasePath;
String sunPath;
String inTempPath;
String outTempPath;
String targetTempPath;
String isOpenPath;

int sunIntensity;
int outTemp;
int inTemp;
int tTemp;
bool isOpen;

unsigned long sendDataPrevMillis = 0;
unsigned long timerDelay = 60000;

void initWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

int getInt(String path){
  if (Firebase.RTDB.getInt(&fbdo, path.c_str())) {
      if (fbdo.dataType() == "int") {
        int temperature = fbdo.intData();
        return temperature;
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
}

bool getBool(String path){
  if (Firebase.RTDB.getBool(&fbdo, path.c_str())) {
    if (fbdo.dataType() == "bool") {
      bool isOpen = fbdo.boolData();
      return isOpen;
    }
  }
}

void sendInt(String path, int value){
  if (Firebase.RTDB.setInt(&fbdo, path.c_str(), value)){
    Serial.print("Writing value: ");
    Serial.println(value);
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

void setup(){
  Serial.begin(115200);

  initWiFi();

  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;

  Firebase.reconnectWiFi(true);
  fbdo.setResponseSize(4096);

  config.token_status_callback = tokenStatusCallback;

  config.max_token_generation_retry = 5;

  Firebase.begin(&config, &auth);

  Serial.println("Getting User UID");
  while ((auth.token.uid) == "") {
    Serial.print(".");
    delay(1000);
  }

  uid = auth.token.uid.c_str();
  Serial.print("User UID: ");
  Serial.println(uid);

  databasePath = "/UsersData/" + uid;

  outTempPath = databasePath + "/outsideTemperature";
  inTempPath = databasePath + "/insideTemperature";
  sunPath = databasePath + "/lightIntensity";
  targetTempPath = databasePath + "/targetTemperature";
  isOpenPath = databasePath + "/blindsOpen";
}

void loop() {
  if (Firebase.ready() && (millis() - sendDataPrevMillis > timerDelay || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
    
    sunIntensity = getInt(sunPath);
    Serial.print("Sun intensity: ");
    Serial.println(sunIntensity);
    
    inTemp = getInTemp();
    sendInt(inTempPath, inTemp);
    
    outTemp = getInt(outTempPath);
    Serial.print("Outside temperature: ");
    Serial.println(outTemp);

    tTemp = getInt(targetTempPath);
    Serial.print("Target temperature: ");
    Serial.println(tTemp/10);

    isOpen = getBool(isOpenPath);
    Serial.print("Blinds are open: ");
    Serial.println(isOpen);

    isOpenPhysical = getOpenPhysical();

    Serial.println("--------------");

    // Start logic

    
  }
}