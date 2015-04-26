// Utilities to display number format

void printDigits(int digits) {
  // utility function for clock display: print preceding colon and leading 0
  if(digits < 10) {
    u8g.print('0');
  }
    u8g.print(digits);
}

void drawWeekday(int myWeekday) {
  // print Sunday instead of 1 (2 for Monday...etc) for Weekday
  char* weekdayStr[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
  u8g.print(weekdayStr[weekday() - 1]);
}

void drawMonth(int myMonth) {
  // print month with short name instead of number
  char* monthStr[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
  u8g.print(monthStr[myMonth - 1]);
}
