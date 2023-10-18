const int upButtonPin = 2;  // the pin that the pushbutton is attached to
int upButtonState;        // current state of the button
bool boolUpButtonState = false;    // previous state of the button

bool getUpButtonPress() {
  upButtonState = digitalRead(upButtonPin);

  if (upButtonState == 1){
    boolUpButtonState = true;
  } else {
    boolUpButtonState = false;
  }
  return boolUpButtonState;
}
