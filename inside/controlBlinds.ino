void controlBlinds(bool open){
  if (open) {
    Serial.println("Opening blinds");
    digitalWrite(dirPin,HIGH);
    for(int x = 0; x < 3200; x++) {
      digitalWrite(stepPin,HIGH); 
      delayMicroseconds(200);    
      digitalWrite(stepPin,LOW); 
      delayMicroseconds(200);
    }
  } else {
    Serial.println("Closing blinds");
    digitalWrite(dirPin,LOW);
    for(int x = 0; x < 3200; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(200);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(200);
    }
  }
  //Stand by decision for 1 minute
  delay(5000);
}