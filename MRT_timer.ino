// Show current time and left minutes to next MRT

void showCurrentTime () {
  // show current time on the top
  u8g.setFont(u8g_font_7x13_67_75);    // draw a clock symbal
  u8g.setFontPosTop();
  u8g.setPrintPos(8, 0);
  u8g.print(char(244));
  
  u8g.setFont(u8g_font_6x10);          // show current time (hour, mins, weekday)
  u8g.setFontPosTop();
  u8g.setPrintPos(19, 3);
  u8g.print("Time ");
  printDigits(hour());
  u8g.print(":");
  printDigits(minute());
  u8g.print(" ");
  drawWeekday(weekday());
  // u8g.drawHLine(4, 14, 124);        // draw a horizonal line under current time
  
}


void showLeftMin(int mins) {  
  // show left minutes
  u8g.setFont(u8g_font_courB24n);
  u8g.setFontPosBaseline();         // align with baseline
  u8g.setPrintPos(8, 44);
  printDigits(mins);
  // change minutes left font size
  u8g.setFont(u8g_font_6x10);
  u8g.setFontPosBaseline();         // align with baseline
  u8g.setPrintPos(50, 44);
  if(mins == 0 || mins == 1) {
    u8g.print("Minute left");      // show "minute" when mins = 0 or 1
  }
  else {
    u8g.print("Minutes left");
  }  
}

void showNextTrain(int mrtHour, int mrtMins, char station) {
  // show Next MRT Train time
  u8g.drawHLine(4, 50, 124);        // draw a horizonal line upper next train
  u8g.setFont(u8g_font_7x13_67_75); // draw a "To" arrow symbal
  u8g.setFontPosBaseline();
  u8g.setPrintPos(8, 62);
  u8g.print(char(112));
  
  u8g.setFont(u8g_font_6x10);
  u8g.setFontPosBaseline();
  u8g.setPrintPos(18, 61);
  if(station == 'X') {
    u8g.print("Qizhang ");
  }
  else if(station == 'Q') {
    u8g.print("Xiaobitang ");
  }
  printDigits(mrtHour);
  u8g.print(":");
  printDigits(mrtMins);
}

void noMRTnow(char station) {
  // show No MRT now
  u8g.setFont(u8g_font_courR10r);
  u8g.setFontPosBaseline();
  u8g.setPrintPos(8, 44);
  u8g.print("No MRT now");
  if(station == 'X') {
    showNextTrain(6, M61[0], station);                  // show tomorrow first train from Xiaobitan
  }
  else if(station == 'Q') {
    showNextTrain(6, MQ61[0], station);                 // show tomorrow first train from Qizhang
  }
}


// function to calculate left minutes to next MRT
void leftMin(int mins, int array[], int arr_size, char station) {  
  int num = arr_size -1;
  
  if(mins <= array[0]) {
     showLeftMin(array[0]-mins);
     showNextTrain(hour(), array[0], station);
     }
  else if(mins > array[0] && mins < array[num-1]) {
     for(int i=0 ; i<=num-1; i++) {
         if(mins >= array[i] && mins < array[i+1]) {
              showLeftMin(array[i+1]-mins);
              showNextTrain(hour(), array[i+1], station);
              }
          }
      }
  else if(mins >= array[num-1]) {
    // exception for last MRT on 23:57 from Xiaobitan to Qizhang
    if(hour() == 23 && station == 'X') {
      noMRTnow(station);
      }
    // exception for last MRT on 00:09 from Qizhang to Xiaobitan
    else if(hour() == 0 && station == 'Q') {
      noMRTnow(station);
    }
    else {
      // calculate the first MRT in next hour
      showLeftMin(60-mins+array[num]);
      // show 00 instead of 24 for latest MRT from Qizhang
      if(hour() == 23 && station == 'Q') {
        showNextTrain(0, array[num], station);
        }
      else {
        showNextTrain(hour()+1, array[num], station);
        }
      }
    }
}


// next MRT main function for Xiaobitan to Qizhang, read data from timeTable_X2Q
void nextMRT(int day, int hour, int mins) {
  char station = 'X';
  
  switch(hour) {
    case 6:
      // Sunday = 1, Monday = 2 ... Saturday = 7
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M61, M61Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M62, M61Size, station);
      }
      break;
      
    case 7:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M71, M71Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M72, M72Size, station);
      }
      break;
      
    case 8:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M81, M81Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M82, M82Size, station);
      }
      break;
      
    case 9:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M91, M91Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M92, M91Size, station);
      }
      break;

    case 10:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M101, M101Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M102, M101Size, station);
      }
      break;

    case 11:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M111, M111Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M112, M112Size, station);
      }
      break;

    case 12:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M121, M121Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M122, M122Size, station);
      }
      break;

    case 13:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M131, M131Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M132, M131Size, station);
      }
      break;

    case 14:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M141, M141Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M142, M141Size, station);
      }
      break;

    case 15:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M151, M151Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M152, M152Size, station);
      }
      break;

    case 16:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M161, M161Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M162, M161Size, station);
      }
      break;

    case 17:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M171, M171Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M172, M172Size, station);
      }
      break;

    case 18:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M181, M181Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M182, M181Size, station);
      }
      break;

    case 19:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M191, M191Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M192, M192Size, station);
      }
      break;

    case 20:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M201, M201Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M202, M201Size, station);
      }
      break;

    case 21:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M211, M211Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M212, M212Size, station);
      }
      break;

    case 22:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M221, M221Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M222, M222Size, station);
      }
      break;

    case 23:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, M231, M231Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, M232, M231Size, station);
      } 
      break;
      
    default:
      noMRTnow(station);                        // show "No MRT now" and tomorrow first train 
  }
}


// next MRT main function for Qizhang to Xianbitan, read data from timeTable_Q2X.h 
void nextMRT_Q(int day, int hour, int mins) {
  char station = 'Q';
  
  switch(hour) {
    case 6:
      // Sunday = 1, Monday = 2 ... Saturday = 7
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ61, MQ61Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ62, MQ62Size, station);
      }
      break;
      
    case 7:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ71, MQ71Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ72, MQ72Size, station);
      }
      break;
      
    case 8:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ81, MQ81Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ82, MQ82Size, station);
      }
      break;
      
    case 9:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ91, MQ91Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ92, MQ92Size, station);
      }
      break;

    case 10:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ101, MQ101Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ102, MQ101Size, station);
      }
      break;

    case 11:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ111, MQ111Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ112, MQ111Size, station);
      }
      break;

    case 12:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ121, MQ121Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ122, MQ121Size, station);
      }
      break;

    case 13:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ131, MQ131Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ132, MQ132Size, station);
      }
      break;

    case 14:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ141, MQ141Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ142, MQ142Size, station);
      }
      break;

    case 15:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ151, MQ151Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ152, MQ151Size, station);
      }
      break;

    case 16:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ161, MQ161Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ162, MQ161Size, station);
      }
      break;

    case 17:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ171, MQ171Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ172, MQ172Size, station);
      }
      break;

    case 18:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ181, MQ181Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ182, MQ182Size, station);
      }
      break;

    case 19:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ191, MQ191Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ192, MQ191Size, station);
      }
      break;

    case 20:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ201, MQ201Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ202, MQ202Size, station);
      }
      break;

    case 21:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ211, MQ211Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ212, MQ211Size, station);
      }
      break;

    case 22:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ221, MQ221Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ222, MQ222Size, station);
      }
      break;

    case 23:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ231, MQ231Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ232, MQ231Size, station);
      } 
      break;
    
    case 0:
      if(day == 2 || day == 3 || day == 4 || day == 5 || day == 6) {
        leftMin(mins, MQ241, MQ241Size, station);
      }
      else if(day == 7 || day == 1) {
        leftMin(mins, MQ242, MQ241Size, station);
      } 
      break;
      
    default:
      noMRTnow(station);                  // show "No MRT Now" and tomorrow first train
  }
}

