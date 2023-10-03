#include <iostream>
#include <string>
#include <ctime>
using namespace std;

unsigned ReadPositiveNumber(string UserText)
{
    unsigned num = 0;

    do
    {
        cout << UserText;
        cin >> num;
    } while (num <= 0);
    return num;
}
int ReadNumberInRange(string UserText, const int Max, const int Sum)
{
    int num = 0;
    do
    {
        cout << UserText;
        cin >> num;

    } while (Max > num || Sum < num);

    return num;
}

void ReadNumbersUntilUserStop(int Array[50], unsigned &Length)
{

    bool Stat = false;

    do
    {
        system("cls");
        Array[Length++] = ReadNumberInRange("Enter a Number : ", 0, 1000);

        cout << "Do you want ti add more Numbers : ? [0]:No,[1]:yes?  : ";
        cin >> Stat;

    } while (Stat);
    {
        /* code */
    }
}

void PrintArrayValues(const string TextToShow, int Array[], const unsigned Length)
{
    cout << TextToShow << "\n ";
    for (unsigned i = 0; i < Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main()
{

    int Array[50];
    unsigned Length = 0;

    ReadNumbersUntilUserStop(Array, Length);
    PrintArrayValues("Array Length " + to_string(Length), Array, Length);
}