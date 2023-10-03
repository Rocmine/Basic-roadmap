#include <iostream>

using namespace std;

// problem 44 :
/*
write a program to ask the user to enter day
then print the day as follows
1- sunday
.....
7- saturday

otherwise print "wrong day " and ask the user again : 

*/
int getDay()
{
    int Today;
    cout << "enter a day:";
    cin >> Today;

    if (cin.fail())
        throw runtime_error("invalid day value you should enter a  digit :  ");
    if (Today < 1 || Today > 7) return 0; 

    return Today;
}

void evaluateDay(int Today)
{
    const string weekDays[] = {"", "sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};
    cout << weekDays[Today];
}

int main()
{

    try
    {
        int Today=-1;
        do{
            system("cls"); 
            if(!Today) cout<<"Wrong day : "<<endl; 
          Today = getDay();  
        }while(!Today); 
       
        evaluateDay(Today);
    }
    catch (runtime_error e)
    {
        cerr << "Error :" << e.what() << endl;
    }
    catch (string msg)
    {
        cout << msg << endl;
    }

    return 0;
}