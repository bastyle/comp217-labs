// Exercise 9.4 Solution: Time.cpp
// Member-function definitions for class Time.
#define  _CRT_SECURE_NO_WARNINGS
#include <iomanip> // for setw and setfill stream manipulators
#include <stdexcept> // for invalid_argument exception class     
#include <sstream> // for ostringstream class
#include <string>
#include <ctime>
//#include <stdexcept> // for illegal_argument exception class
#include "Time.h" // include definition of class Time from Time.h
using namespace std;

Time::Time() : hour(0), minute(0), second(0) {
   const time_t currentTime{time(0)};
   const tm *localTime{localtime(&currentTime)};
   setTime(localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
} 

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
   // validate hour, minute and second
   if ((h < 0 || h >= 24) || (m < 0 || m >= 60) || (s < 0 || s >= 60)) {
      throw invalid_argument(
         "hour, minute and/or second was out of range");
   }

   hour = h;
   minute = m;
   second = s;
} 

// return Time as a string in universal-time format (HH:MM:SS)
string Time::toUniversalString() const {
   ostringstream output;
   output << setfill('0') << setw(2) << hour << ":"
      << setw(2) << minute << ":" << setw(2) << second;
   return output.str(); // returns the formatted string
}

// return Time as string in standard-time format (HH:MM:SS AM or PM)
string Time::toStandardString() const {
   ostringstream output;
   output << ((hour == 0 || hour == 12) ? 12 : hour % 12) << ":"
      << setfill('0') << setw(2) << minute << ":" << setw(2)
      << second << (hour < 12 ? " AM" : " PM");
   return output.str(); // returns the formatted string
}

/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/


