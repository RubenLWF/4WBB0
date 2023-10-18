const int downButtonPin = 3;  // the pin that the pushbutton is attached to
int downButtonState;        // current state of the button
bool boolDownButtonState = false;    // previous state of the button

bool getDownButtonPress() {
  downButtonState = digitalRead(downButtonPin);

  if (downButtonState == 1){
    boolDownButtonState = true;
  } else {
    boolDownButtonState = false;
  }
  return boolDownButtonState;
}
