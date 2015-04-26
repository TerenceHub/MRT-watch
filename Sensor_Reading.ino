// Function to get and display temperature and pressure for altitude

void showReading() {

  double p0 = 1018.0;                         // local sealevel pressure for BMP180 adjustment
  // You could find your local sealevel pressure in AWC - http://www.aviationweather.gov
  // Note that sealevel pressure would be changed by season or weather status

  char status;
  double T, P, a;
  unsigned long sensorTime = 0;                 // initial sensor update timer

  // draw a horizonal line on screen 
  u8g.drawHLine(3, 50, 124);  

  // set sensor update interval
  if(sensorTime > millis()) sensorTime = millis();
  // update sensor reading every 10s
  if(millis() - sensorTime > 10000) {
  
    // Start temperature measurement first. Note that pressure measurement function required Temperture.
    // If request is successful, the number of ms to wait is returned. If failed, 0 is returned.
    status = pressure.startTemperature();
    if (status != 0) {
      delay(status);                              // wait for the measurement to complete
      status = pressure.getTemperature(T);        // store measured temperature in the vasiable T.
      
      if (status != 0) {
        // print out temperature
          u8g.setFont (u8g_font_6x10);           // set font and position
          u8g.setFontPosTop();
          u8g.drawStr ( 8, 52, "Temp");
          u8g.setPrintPos( 34, 52 );
          u8g.print(T, 1);                   // print temperature in Celsius
          // u8g.print((9.0/5.0)*T+32, 1)    // print temperature in Fahrenheit
          u8g.setPrintPos( 58, 52 );
          u8g.print(char(176));              // draw degree charactor
          u8g.drawStr ( 63, 52, "C");
          // u8g.drawStr (50, 52, "F");
          
          // start pressure measurement (parameter 3 is the oversampleing setting, highest res, longest wait)
          status = pressure.startPressure(3);
          if (status != 0) {
            delay(status);
            status = pressure.getPressure(P, T);    // store measured pressure in the variable P
            a = pressure.altitude(P, p0);           // calculate altitude by pressure difference
            if (status != 0) {
                u8g.drawStr( 76, 52, "Alt");
                u8g.setPrintPos(96, 52);
                u8g.print(a, 0);
                u8g.drawStr (116, 52, "m");
            }
          }
      }
    }
  }
 sensorTime = millis();                            // reset sensor update timer
}
