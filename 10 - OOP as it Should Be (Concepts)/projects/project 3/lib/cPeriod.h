#pragma once
#include <iostream>
using namespace std;
#include "./cDate.h"

class cPeriod
{
    cDate start;
    cDate end;

public:
    //  parametrized  constructor :
    cPeriod(cDate start=cDate(1,1,1), cDate end=cDate(1,1,1)) : start(start), end(end)
    { 
        if (start > end)
        {
            this->end = start;
        }
    }
    // copy constructor :
    cPeriod(cPeriod &copy) : start(copy.start), end(copy.end)
    {
    }

    // cout operator :
    friend ostream &operator<<(ostream &out,const cPeriod &p)
    {
        cout << "Start Period : " << p.start << endl;
        cout << "End  Period  : " << p.end;

        return out;
    }

    // cin operator  :
    friend istream &operator>>(istream &inp, cPeriod &p)
    {
        cout << "Enter the start Day : ";
        cin >> p.start;
        do
        {
            cout << "Enter the end Day : ";
            cin >> p.end;
        } while (p.start > p.end);
        return inp;
    }

    // get Period Days  function :
    static int getPeriodDays(cPeriod p)
    {
        return cDate::getDiffDaysFromTwoDate(p.start, p.end);
    }
    int getPeriodDays()
    {

        return getPeriodDays(*this);
    }
    static int getNumberOfVacationDays(cPeriod p)
    {

        return cDate::GetNumberOfVacationDaysFromTwoDate(p.start, p.end);
    }
    int getNumberOfVacationDays()
    {
        return getNumberOfVacationDays(*this);
    }
};