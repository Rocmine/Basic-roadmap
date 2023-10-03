#include <iostream>
#include<string>
using namespace std;
const int balance = 7500;
const int RightPin = 1234;

// problem 49 :

/*
write a program to read ATM PIN code from the user, then check if pin code =1234,then show the balance to user ,otherwise print "Wrong pin " and ask the user
to enter the PIN again :

Assume User balance is 7500
*/

int  getPIN(int pin)
{
    cout << "enter the pin : ";
    cin >> pin;

    if (cin.fail())  throw runtime_error("invalid pin value you should enter a digit : ");

    return pin; 
}

bool CheckPin(int pin)
{

    if (pin == RightPin)  throw string("your balance is :"+ to_string(balance));
    return true; 
}
int main()
{
    int pin = 0;
    try
    {

        
      do{
           pin=getPIN(pin);
        }while( CheckPin(pin)); 
    }
    catch (runtime_error e)
    {

        cout << "Error :" << e.what() << endl;
    }
    catch (string msg)
    {

        cout << msg << endl;
    }
}