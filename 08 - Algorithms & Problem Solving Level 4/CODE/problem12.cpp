/*
problem 12:
Write a program to read date and read
how many days to add to it, print the
results on screen

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

short getMonthDaysInYear(short year, short month)
{
    int numberOfDays[] = {0, 31, checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numberOfDays[month];
}

int getNbrDaysFromDate(short day, short month, int year)
{

    short days = 0;
    for (int i = 1; i < month; i++)
    {

        days += getMonthDaysInYear(year, i);
    }

    days += day;

    return days;
}

struct stDate
{
    short year;
    short month;
    short day;
};

short AddDaysMoreThanYearToDate(short year , short remainingDays, stDate &date){

   short arrCheckYearLeap[] = {365, 366};
    short yearStatus = checkIfYearIsLeap(year);

    while (remainingDays > arrCheckYearLeap[yearStatus])
    {

        if (checkIfYearIsLeap(date.year) == enIsLeapYear::isLeap)
        {
            yearStatus = enIsLeapYear::isLeap;

        }
        else
        {
            yearStatus = enIsLeapYear::noLeap;
         
        }
           remainingDays -= arrCheckYearLeap[yearStatus];
            date.year++;
    }
return remainingDays; 
}

stDate daysToDate(short remainingDays, short year)
{
    stDate date;
    date.month = 1;
    date.year = year;
 remainingDays=AddDaysMoreThanYearToDate(year,remainingDays,date); 

    while (true)
    {

        short monthDays = getMonthDaysInYear(year, date.month);

        if (remainingDays > monthDays)
        {
            remainingDays -= monthDays;
            date.month++;
        }
        else
        {
            date.day = remainingDays;
            break;
        }
    }

    return date;
}

stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 30, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");

    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}
int main()
{

    try
    {
        stDate date = readDate();
        int nbrDaysToAdd = input::readIntegerNumber("How Many days to Add :  ");
        int nbrOfDays = getNbrDaysFromDate(date.day, date.month, date.year);

        date = daysToDate(nbrOfDays + nbrDaysToAdd, date.year);
        string strDate = convertDateToString(date);

        cout << "Date after adding [" << nbrDaysToAdd << "] days"
             << " is : " << strDate << endl;
    }
    catch (runtime_error &e)
    {

        cerr << "Exception : " << e.what() << endl;
    }

    return 0;
}
