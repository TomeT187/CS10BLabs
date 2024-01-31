#include <iostream>
#include <string>

using namespace std;

class Date {
 private:
   unsigned day;
   unsigned month;
   string monthName;
   unsigned year;

 public:
   // creates the date January 1st, 2000.
   Date();


   /* parameterized constructor: month number, day, year 
       - e.g. (3, 1, 2010) will construct the date March 1st, 2010

       If any of the arguments are invalid (e.g. 15 for month or 32 for day)
       then the constructor will construct instead a valid Date as close
       as possible to the arguments provided - e.g. in above example,
       Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
       In case of such invalid input, the constructor will issue a console error message: 

       Invalid date values: Date corrected to 12/31/2010.
       (with a newline at the end).
   */
   Date(unsigned m, unsigned d, unsigned y);


   /* parameterized constructor: month name, day, year
      - e.g. (December, 15, 2012) will construct the date December 15th, 2012

       If the constructor is unable to recognize the string argument as a valid month name,
       then it will issue a console error message: 

       Invalid month name: the Date was set to 1/1/2000.
       (with a newline at the end).
 
       If the day argument is invalid for the given month (but the month name was valid),
       then the constructor will handle this error in the same manner as the other
       parameterized constructor. 

       This constructor will recognize both "december" and "December"
       as month name.
   */
   Date(const string &mn, unsigned d, unsigned y);


   /* Outputs to the console (cout) a Date exactly in the format "3/15/2012". 
      Does not output a newline at the end.
   */
   void printNumeric() const;


   /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
      The first letter of the month name is upper case, and the month name is
      printed in full - January, not Jan, jan, or january. 
      Does not output a newline at the end.
   */
   void printAlpha() const;

 private:

   /* Returns true if the year passed in is a leap year, otherwise returns false.
   */
   bool isLeap(unsigned y) const;


   /* Returns number of days allowed in a given month
      -  e.g. daysPerMonth(9, 2000) returns 30.
      Calculates February's days for leap and non-leap years,
      thus, the reason year is also a parameter.
   */
   unsigned daysPerMonth(unsigned m, unsigned y) const;

   /* Returns the name of a given month
      - e.g. name(12) returns the string "December"
   */
   string name(unsigned m) const;

   /* Returns the number of a given named month
      - e.g. number("March") returns 3
   */
   unsigned number(const string &mn) const;
};


// Implement the Date member functions here

Date::Date(){
   day = 1;
   month = 1;
   monthName = "January";
   year = 2000;
}

Date::Date(unsigned m, unsigned d, unsigned y){
   unsigned maxdays = daysPerMonth(m,y);
   bool neededCorrection = false;
   if (m > 12){
      month = 12;
      monthName = name(12);
      
      neededCorrection = true;
   } else if(m < 1){
      month = 1;
      monthName = name(1);
      maxdays = daysPerMonth(1,y); 
      neededCorrection = true;
   }else {
      month = m;
      monthName = name(m);
   }

   if (d > maxdays){
      day = maxdays;
      neededCorrection = true;
   } else if(d < 1){
      day = 1;
      neededCorrection = true;
   }else{
      day = d;
   }

   year = y;

   if (neededCorrection){
      cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
   }

}

 
Date::Date(const string &mn, unsigned d, unsigned y){
   bool neededCorrection = false;

   if(number(mn) == 0){
      month = 1;
      monthName = name(1);
      day = 1;
      year = 2000;
      cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
   } else {
      unsigned maxdays = daysPerMonth(number(mn),y);
      monthName = name(number(mn)); //used to upercase anything inputed as lower case
      month = number(mn);
      if (d > maxdays){
         day = maxdays;
         neededCorrection = true;
      } else if(d < 1){
         day = 1;
         neededCorrection = true;
      }else{
         day = d;
      }

      year = y;

      if (neededCorrection){
         cout << "Invalid date values: Date corrected to " << month << "/" << day << "/" << year << "." << endl;
      }
   }

}

void Date::printNumeric() const{
   cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const{
   cout << monthName << " " << day << ", " << year;
}


bool Date::isLeap(unsigned y) const{
   bool isLeapYear = (y % 4 == 0); // isLeapYear = if year is divisible by 4
   if ((y % 100 == 0)){            // if divisible by 100:
       isLeapYear = (y % 400 == 0);//     isLeapYear = if divisible 400 
   }
   return isLeapYear;
}

unsigned Date::daysPerMonth(unsigned m, unsigned y) const{
   if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
      return 31;
   } else if (m != 2){
      return 30;
   } 
   if (isLeap(y)){
      return 29;
   }
   return 28;
}

string Date::name(unsigned m) const{
   string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
   return months[m - 1];
}
unsigned Date::number(const string &mn) const{
      string monthsupperCase[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
      string monthsLowerCase[12] = {"january","february","march","april","may","june","july","august","september","october","november","december"};
      for (int i = 0; i < 12;i ++){
         if ( mn == monthsLowerCase[i] || mn == monthsupperCase[i]){
            return i + 1;
         }
      }
      return 0;          
}






// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {
   
   Date testDate;
   testDate = getDate();
   cout << endl;
   cout << "Numeric: ";
   testDate.printNumeric();
   cout << endl;
   cout << "Alpha:   ";
   testDate.printAlpha();
   cout << endl;
   
   return 0;
}

Date getDate() {
   int choice;
   unsigned monthNumber, day, year;
   string monthName;

   cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
      << "1 - Month Number" << endl
      << "2 - Month Name" << endl
      << "3 - default" << endl;
   cin >> choice;
   cout << endl;

   if (choice == 1) {
      cout << "month number? ";
      cin >> monthNumber;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthNumber, day, year);
   } else if (choice == 2) {
      cout << "month name? ";
      cin >> monthName;
      cout << endl;
      cout << "day? ";
      cin >> day;
      cout << endl;
      cout << "year? ";
      cin >> year;
      cout << endl;
      return Date(monthName, day, year);
   } else {
      return Date();
   }
}
