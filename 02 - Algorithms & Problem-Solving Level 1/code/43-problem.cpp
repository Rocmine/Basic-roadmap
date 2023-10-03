#include <iostream>
#include <string>
#include<cmath>

#include <iomanip>

using namespace std;

// problem 43 :
/*
write a program that inputs the number of seconds and changes it days,hours,minutes,seconds
*/

struct Task
{
    float days;
    float hours;
    float minutes;
    float Seconds;
};

int getTaskInfo()
{

    float seconds;

    cout << "enter the number of seconds  : ";
    cin >> seconds;
    if (cin.fail() || seconds < 0)
        throw runtime_error("you should enter a positive digit : ");
    return seconds;
}

void numberOfWeeksDays(float TSeconds)
{
    Task ob1;
    ob1.days = TSeconds / 24 / 60 / 60.0;
    ob1.hours = ((ob1.days - int(ob1.days))) * 24.0;
    ob1.minutes = (ob1.hours - int(ob1.hours)) * 60.0;
    ob1.Seconds = (ob1.minutes - int(ob1.minutes)) * 60.0;
    cout<<ob1.Seconds<<endl; 

    throw Task(ob1);
}

int main()
{

    try
    {

        float secondes = getTaskInfo();
        numberOfWeeksDays(secondes);
    }
    catch (runtime_error e)
    {
        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (Task ob1)
    {
        //system("cls");
        cout << int(ob1.days) << ":" << int(ob1.hours) << ":" << int(ob1.minutes) << ":" << round(ob1.Seconds) << endl;
    }
    return 0;
}