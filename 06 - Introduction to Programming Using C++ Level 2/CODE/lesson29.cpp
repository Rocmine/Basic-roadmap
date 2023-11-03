/*
write a program to ask user to enter an many numbers as s/he wants, each time a number
entered add it to your vector, ans ask the user if s/he wants to add more numbers until
s/he says No , then print all vector elements on the screen
*/

#include <iostream>
#include "test/myLib.h"
#include <vector>

using namespace std;

enum enUserDecide
{
    no,
    yes
};

void readVectorValuesUntilUserTellNo(vector<int> &vNumbers)
{

    string arrUserDecide[] = {"no", "yes"};
    string userDecide = "";

    do
    {
        int number = input::readIntegerNumber();
        vNumbers.push_back(number);
        userDecide = input::readString("if  you want continue enter [yes] otherwise enter [no] ");

    } while (userDecide == arrUserDecide[enUserDecide::yes]);
}

void printVector(vector<int> &vNumbers)
{
    cout << endl;
    for (int &number : vNumbers)
    {
        cout << number << " ";
    }
    cout << endl;
}
int main()
{

    vector<int> vNumbers;
    readVectorValuesUntilUserTellNo(vNumbers);
    printVector(vNumbers);

    return 0;
}