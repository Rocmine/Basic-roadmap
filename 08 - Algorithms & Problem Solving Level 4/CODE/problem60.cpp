/*
problem 60 : 
Write a program to read a Period and
Date, then check if date is within this
period or not?
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
bool isDate1EqualDate2(const stDate &date1, const stDate &date2)
{

    return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

bool isDate1BeforeDate2(const stDate &date1, const stDate &date2)
{
    if (date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) ||
        (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isDate1AfterDate2(const stDate &date1, const stDate &date2)
{

    return isDate1EqualDate2(date1, date2) ? false : (isDate1BeforeDate2(date1, date2) ? false : true);
}
enum enCompareTwoDate
{
    eBefore = -1,
    eEqual,
    eAfter

};
enCompareTwoDate compareTwoDate(const stDate &date1, const stDate &date2)
{

    return isDate1EqualDate2(date1, date2) ? enCompareTwoDate::eEqual : (isDate1BeforeDate2(date1, date2) ? enCompareTwoDate::eBefore : enCompareTwoDate::eAfter);
}



bool  isDateWithinPeriod(stPeriod period , stDate date ){

 
 return (  compareTwoDate(period.startDate,date)==enCompareTwoDate::eBefore || compareTwoDate(period.startDate,date)==enCompareTwoDate::eEqual  ) &&
       ( compareTwoDate(period.endDate,date)==enCompareTwoDate::eAfter || compareTwoDate(period.endDate,date)==enCompareTwoDate::eEqual);


}



int main(){

     stPeriod p1;

    cout << "\nEnter Period 1 :\n";
    p1 = readPeriod();

    cout<< "\n enter date to check :\n  "; 
    stDate date=readDate();

cout<<"\n"<<(isDateWithinPeriod(p1,date) ? "Yes, Date is within period ":"No, Date is not within the period ")<<endl; 
      

 

   

}