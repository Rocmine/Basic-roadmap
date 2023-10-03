#include <iostream>
using namespace std;

// problem 38 :
/*
write wa program to read a number and check if it is a prime number or not  :

note : prime number can only divide on one and on itself :

*/

int getNumber()
{

    int number = 0;
    cout << "enter a number :";
    cin >> number;

    if (cin.fail())
        throw runtime_error("invalid number you should enter a digit: ");
   if(number <0)  throw string("you should enter a number grater than 0"); 
     if(number==0 )   throw string("it's not a prime number :");
    return number;
}

void isPrime(int number)
{



    for (int i = 2; i <= number / 2; i++)
    {

        if (number % i == 0)
            throw string("it's not a prime number :");
    }

    throw string("it's a prime number : ");
}

int main()
{

    try
    {

        int number = getNumber();

        isPrime(number);
    }
    catch (runtime_error e)
    {
        cerr << "Error :" << e.what() << endl;
    }
    catch (string result)
    {
        cout << result << endl;
    }

    return 0;
}