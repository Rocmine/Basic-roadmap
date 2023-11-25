/*
problem 8:
write a program to print month calender
*/

#include <iostream>
#include <string>
#include "myLib.h"
#include <iomanip>
using namespace std;

enum enIsLeapYear
{
    noLeap,
    isLeap
};

enIsLeapYear checkIfYearIsLeap(int year)
{

    return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0) ? enIsLeapYear::isLeap : enIsLeapYear::noLeap;
}

int getMonthDaysInYear(int year, int month)
{
    int numberOfDays[12] = {31, month == 2 && checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month - 1];
}

short calculateDayOfWeek(int year, short month, short day)
{
    short a = (14 - month) / 12;
    short m = month + 12 * a - 2;

    short d = (day + year + year / 4 - year / 100 + year / 400 + ((31 * m) / 12)) % 7;

    return d;
}
void printCalender(int year, int month)
{
    string arrDays[] = {"Sunday", "Monday", "tuesday", "Wednesday", "Thursday", "Friday", "saturday"};
    string arrMonths[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int daysInMonth = getMonthDaysInYear(year, month);
    int dayOrder = calculateDayOfWeek(year, month, 1);

    cout << "\n\n_________________________________________" << arrMonths[month] << "_________________________________________\n\n";

    for (int i = 0; i <= 6; i++)
        cout << setw(12) << arrDays[i];
    cout << "\n";

   int i=1; 
    for(;i<=dayOrder;i++){
        cout <<right<<setw(12)<<"";
    }
     int dayCounter = 1;
    while (dayCounter <= daysInMonth)
    {
       
      cout <<right<<setw(12)<<dayCounter++; 
        if (i++ % 7==0)  cout << "\n";
    }
    cout << "\n_______________________________________________________________________________________\n\n";
}

int main()
{

    int year = input::readIntegerNumber("\nenter a Year      :  ");
    short month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    printCalender(year, month);
    system("pause>0"); 
    return 0;
}