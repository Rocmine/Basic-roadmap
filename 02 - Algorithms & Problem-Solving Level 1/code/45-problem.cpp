#include <iostream>

using namespace std;

// problem 45 :
/*
write a program to ask the user to enter month
then print the day as follows
1- january
.....
7- december

otherwise print "wrong month " and ask the user again : 

*/
int getMonth()
{
    int month=0;
    
    cout << "enter a month:";
    cin >> month;

    if (cin.fail())  throw runtime_error("invalid month value you should enter a  digit :  ");
   
    if (month < 1 || month < 12) return 0; 

    return month;
}

void evaluateMonth(int month)
{
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << months[month];
}

int main()
{

    try
    {
        int month=-1;
        do{
            system("cls"); 
            if(!month) cout<<"Wrong month : "<<endl; 
          month = getMonth();  
        }while(!month); 
       
       evaluateMonth(month);
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