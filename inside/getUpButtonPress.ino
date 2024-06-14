int upButtonPin = 9;
bool getUpButtonPress()
{
  int buttonValue = digitalRead(upButtonPin);
  if (buttonValue == LOW)
  {
    return true;
  }
  else
  {
    return false;
  }
}
