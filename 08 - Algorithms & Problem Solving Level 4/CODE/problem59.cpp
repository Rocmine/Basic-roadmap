/*
problem 59 : 
Write a program to read a Period and
calculate period length in days? 
*/
#include <iostream>
#include <string>
#include <cmath>
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
int getNbrDaysFromDate(stDate date)
{

    short days = 0;
    for (int i = 1; i < date.month; i++)
    {

        days += getMonthDaysInYear(date.year, i);
    }

    days += date.day;

    return days;
}
int yearToDays(int year)
{

    return checkIfYearIsLeap(year) == enIsLeapYear::isLeap ? 366 : 365;
}

float getAvgDaysBetweenTowYear(int year1, int year2)
{

    if (year1 == year2)
        return 0;

    int maxYear = year1 > year2 ? year1 : year2;
    int minYear = year1 < year2 ? year1 : year2;
    float avgDays = 0;

    for (int i = minYear; i <= maxYear; i++)
    {

        avgDays += yearToDays(i);
    }

    avgDays /= (maxYear * 1.0 - minYear) + 1;

    return avgDays;
}

int getDiffDaysFromTwoDate(stDate date1, stDate date2, bool includeToDay = false)
{

    int nbrDays = (round((date2.year - date1.year) * getAvgDaysBetweenTowYear(date2.year, date1.year)) + getNbrDaysFromDate(date2) - getNbrDaysFromDate(date1));

    return includeToDay ?  ++nbrDays : nbrDays;
}

struct stPeriod
{

    stDate startDate;
    stDate endDate;
};
stPeriod readPeriod()
{
    stPeriod period;
    cout << "Enter the Start Day : \n\n";
    period.startDate = readDate();

    cout << "\nEnter the End Day : \n\n";
    period.endDate = readDate();

    return period;
} 

int getLengthOfPeriod(stPeriod period , bool includeEndDate=false){

 
 return  getDiffDaysFromTwoDate(period.startDate,period.endDate,includeEndDate); 
}

int main(){

     stPeriod p1;

    cout << "\nEnter Period 1 :\n";
    p1 = readPeriod();

    cout<<"Period Length is : "<<getLengthOfPeriod(p1)<<"\n"; 
    cout<<"Period Length is (including End Date ) : "<<getLengthOfPeriod(p1,true)<<endl; 

   

}