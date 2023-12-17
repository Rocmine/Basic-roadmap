/*
problem 14:
Write a program to read date1, date2 and
check if Date is Less than Date2

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




stDate readDate()
{
    stDate date;

    date.day = input::readIntegerInRange(1, 31, "enter  a day   :  ");
    date.month = input::readIntegerInRange(1, 12, "enter  a Month   :  ");
    date.year = input::readIntegerNumber("enter a Year      :  ");

    return date;
}

string convertDateToString(stDate date)
{

    return to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
}

void  compareTwoDate(stDate date1 , stDate date2){
 int nbrOfDaysDate1= getNbrDaysFromDate(date1.day, date1.month, date1.year);
 int nbrOfDaysDate2= getNbrDaysFromDate(date2.day, date2.month, date2.year);
cout<<"\n"; 
if(nbrOfDaysDate1 == nbrOfDaysDate2){

    cout<<"No, Date1 is equal than Date 2\n";
}

else if(nbrOfDaysDate1 > nbrOfDaysDate2){

    cout<<"Yes, Date1 is Grater than Date 2\n";
}

else{

    cout<<"No, Date1 is less than Date 2\n";
}

}
int main()
{

    try
    {
        stDate date1 = readDate();
         cout<<endl; 
        stDate date2 = readDate();

        compareTwoDate(date1,date2); 

       
    }
    catch (runtime_error &e)
    {

        cerr << "Exception : " << e.what() << endl;
    }

    return 0;
}
