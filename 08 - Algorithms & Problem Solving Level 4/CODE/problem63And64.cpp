/*
problem 63 to 64  :
Write a program to :
. Read Date String.
. Convert it to date structure
. Print Day, Mont, Year separately.
. Then convert Date Structure to string and
print it on the screen.

Note: write the following functions:
. String ToDate.
. Date ToString.
*/
#include <iostream>
#include <string>
#include <cmath>
#include "myLib.h"
#include <iomanip>
#include <cctype>
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

short getMonthDaysInYear(short year, short month)
{
    int numberOfDays[] = {0, 31, checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month];
}

struct stDate
{
    short year;
    short month;
    short day;
};
bool checkIfValidDay(stDate date)
{

    return date.day <= getMonthDaysInYear(date.year, date.month);
}
stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");
    if (!checkIfValidDay(date))
        date.day = getMonthDaysInYear(date.year, date.month);
    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}
 

 
bool  isAValidDate(stDate date){
 

  return   ( (checkIfValidDay(date)) && (date.month<=12  && date.month >=1));     
 

}

stDate convertStringToDate(string strDate)
{

    stDate date;


    int separatorCounter = 0;

    string content = "";
    for (int i = 0; i < strDate.length(); i++)
    {

        content += strDate[i];
        if (strDate[i] == '/')
        {

            if (separatorCounter == 0)
                date.day = stoi(content);

            else
                date.month = stoi(content);

                content=""; 

            separatorCounter++;
        }
    }
   
 // push the year :
    date.year += stoi(content);

  if(separatorCounter!=2 || !isAValidDate(date)){
 date.day=0;
    date.month=0;
    date.year=0;

  }


    return date;
}
int main()
{

    cout << "enter  the date info : \n";

    string strDate = input::readString("enter the date : ");

    stDate date = convertStringToDate(strDate);
     

    
    cout << convertDateToString(date) << endl;

    return 0;
}
