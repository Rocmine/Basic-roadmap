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

int GetRandomNumber(const int From, const int To)
{

    return rand() % (To - From + 1) + From;
}

void ReadArrayRandomValues(int Array[50], unsigned &Length)
{
    Length = ReadNumberInRange("Enter the length :", 0, 100);
    for (unsigned i = 0; i < Length; i++)
    {
        Array[i] = GetRandomNumber(-100, 100);
    }
}

void PrintArrayValues(const string TextToShow, int Array[], const unsigned Length)
{
    cout << TextToShow << " ";
    for (unsigned i = 0; i < Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

bool isNegative(int Number)
{
    return Number < 0 ;
}

int GetNumberOfNegativeInArray(int Array[], const unsigned Length)
{
    int Counter = 0;
    for (unsigned i = 0; i < Length; i++)
        if (isNegative(Array[i]))
            Counter++;
    return Counter;
}

int main()
{
    srand(time(NULL));
    int Array[100];

    unsigned Length = 0;

    ReadArrayRandomValues(Array, Length);
    PrintArrayValues("Array 1  Element : ", Array, Length);

    cout << "Negative Numbers count is : " << GetNumberOfNegativeInArray(Array, Length);

    return 0;
}
