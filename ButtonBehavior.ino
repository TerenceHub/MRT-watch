// Define the behavior of 2 buttons

void buttonSwitch() {
  // read button status  
  int btn1 = digitalRead(7);
  int btn2 = digitalRead(6);
  int debounceTime = 110;
  
  // pressing button 1 to change screen page from A -> B -> C -> A when screen on
  if(btn1 == LOW && pageNumber == 0 && sleep == 0) {
    //Serial.println("Button 1 is pressed");
    delay(debounceTime);                                      // delay to avoid button debounce
    pageNumber = pageB;
    screenOnTime = millis();                                  // record current millis when button pressed
  }
  else if(btn1 == LOW && pageNumber == 1 && sleep == 0) {
    //Serial.println("Button 1 is pressed");
    delay(debounceTime);
    pageNumber = pageC;
    screenOnTime = millis();                                  // record current millis when button pressed
  }
  else if(btn1 == LOW && pageNumber == 2 && sleep == 0) {
    delay(debounceTime);
    pageNumber = pageA;
    screenOnTime = millis();                                  // record current millis when button pressed
  }
  else if(btn1 == LOW && sleep == 1) {
    // if screen off, press button 1 to wake it up
    delay(debounceTime);
    sleep = 0;
    screenOnTime = millis();                                  // record current millis when button pressed
  }
  
  // pressing button 2 to switch screen on and off, auto screen off after 30s
  if(sleep == 0 && millis() - screenOnTime > screenSaverDuration) {
    // if millis() is bigger than screen on time recode -> screen off
    sleep = 1;
  }    
  else if(btn2 == LOW && sleep == 0) {
    //press button 2 to set screen off
    delay(debounceTime);
    sleep = 1;
  }
  else if(btn2 == LOW && sleep == 1) {
    //press button 2 to set screen on
    delay(debounceTime);
    sleep = 0;
    screenOnTime = millis();                // record current millis when button pressed
  }   
}

