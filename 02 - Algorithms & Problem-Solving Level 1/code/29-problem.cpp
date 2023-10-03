#include <iostream>
using namespace std;

// problem 29 :
/*
write a program  to sum even numbers from 1 to n 
*/


int getNumber()
{
    int number = 0;
    cout << "enter a number  :";
    cin >> number;

    return number;
}

void isValid(int number)
{
    if (cin.fail())
        throw runtime_error("invalid number :");
    if (number < 0 || number > 10000)
        throw string("you should enter a number between 0 and  10000");
}

int  sumOfOdd(int n)
{
    int sum=0 ; 
    for (int i = 1; i <=10; i++)
    {
    if(i%2==0) sum+=i; 
    }
    return sum; 
}

int main()
{

    try
    {
        int number = getNumber();
        isValid(number);
        int sum=sumOfOdd(number);
        cout<<"the sum of even numbers is :"<<sum<<endl; 
    }
    catch (runtime_error e)
    {
        cerr << "Error " << e.what() << endl;
    }
    catch (string msg)
    {
        cout << msg << endl;
    }

    return 0;
}