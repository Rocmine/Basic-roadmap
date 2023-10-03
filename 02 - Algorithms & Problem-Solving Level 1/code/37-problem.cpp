#include <iostream>
#include <string>

// ignore the using of std :
using namespace std;

// problem 37 :
/*
write a program to read numbers from user and sum then keep reading until the user enters -99  then print the sum
on screen :
*/

int getValue()
{
    int value = 0;
    cout << "enter the value :";
    cin >> value;
    cin.ignore();
    return value;
}

void AddNewValue(int value, int &sum)
{
    sum += value;
}

void Evaluate()
{
    int sum = 0;
    int value = 0;
    do
    {
        value = getValue();
        if (cin.fail())
            throw runtime_error("invalid input Value your sum is : " + to_string(sum));

        AddNewValue(value, sum);
    } while (value != -99);
    throw string(to_string(sum));
}

// ignore the using of std::
using namespace std;
int main()
{

    try
    {
        Evaluate();
    }
    catch (runtime_error e)
    {
        cerr << e.what() << endl;
    }
    catch (string result)
    {
        cout << "your result is :" << result << endl;
    }
    return 0;
}