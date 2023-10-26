int getOutTemp(){
  // Read the temperature and the humidity:
  
  return int(AM2320.readTemperature() * 10);
}