int getSunIntensity()
{
  return int(lightMeter.readLightLevel() * 10);
}