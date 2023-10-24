int getInTemp(){
  Serial.print(AM2320.readTemperature());
  return int(AM2320.readTemperature() * 10);
}