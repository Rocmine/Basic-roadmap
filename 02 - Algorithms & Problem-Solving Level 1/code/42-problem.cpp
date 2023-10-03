#include <iostream>
#include <string>

#include <iomanip>

using namespace std;


// problem 42 : 
/*
write a program to calculate the task duration in seconds and print it on screen 
-> given the time duration  of the task in the number of days,hours,minutes,seconds  
*/


void getTaskInfo(float &days,float &hours,float &minutes, float &seconds )
{
  
    cout << "enter the number Days  : ";
    cin >> days;cin.ignore(); 
    if (cin.fail() || days < 0)  throw runtime_error("you should enter a positive digit : ");

        cout << "enter the number of hours  : ";
    cin >> hours;cin.ignore(); 
    if (cin.fail() || days < 0)  throw runtime_error("you should enter a positive digit : ");

        cout << "enter the number of minute  : ";
    cin >> minutes;cin.ignore();  if (cin.fail() || minutes < 0)  throw runtime_error("you should enter a positive digit : ");


        cout << "enter the number of seconds  : ";
    cin >> seconds;if (cin.fail() || seconds < 0)  throw runtime_error("you should enter a positive digit : ");


  
}

void numberOfWeeksDays(float days,float hours,float minutes, float seconds )
{

  float nbrOfSecond=days*24*60*60 +hours*60*60 +minutes*60 + seconds;  

    throw float(nbrOfSecond); 
}

int main()
{

    try
    {
        float days,hours,minutes,seconds; 
        getTaskInfo(days,hours,minutes,seconds); 
        numberOfWeeksDays(days,hours,minutes,seconds);
    }
    catch (runtime_error e)
    {
        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (float result)
    {
        system("cls"); 
        cout <<result<<" Seconds";
    }
    return 0;
}