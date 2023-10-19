int getInTemp(){
  return int(AM2320.readTemperature() * 10);
}