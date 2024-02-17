#include <iostream>
#include "./lib/cDate.h"
#include "./lib/cPeriod.h"
int main()
{

    cDate date1(10, 12, 2003);
    cout << "enter the  the date : ";
    cin >> date1;

    cout << date1;
    date1.printCalender();

    cPeriod p1(cPeriod(cDate(14,12,2003),cDate(16,2,2003))); 

    cout<<p1<<endl; 
    return 0;
}