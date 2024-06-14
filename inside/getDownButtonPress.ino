int downButtonPin = 8;
bool getDownButtonPress()
{
  int buttonValue = digitalRead(downButtonPin);
  if (buttonValue == LOW)
  {
    return true;
  }
  else
  {
    return false;
  }
}