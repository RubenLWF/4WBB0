const int pin = 3;

void controlBlinds(bool open){
  if (open){
    Serial.println("Opening blinds");
  } else{
    Serial.println("Closing blinds");
  }
  //Stand by decision for 1 minute
  delay(5000);
}