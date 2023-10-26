int getSunIntensity(){
  Serial.println("")
  return int(lightMeter.readLightLevel() * 10);
}