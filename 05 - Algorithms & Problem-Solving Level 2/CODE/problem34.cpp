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
        Array[i] = GetRandomNumber(0, 100);
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

int GetSearchValuePosition(const int Array[50], const unsigned Length, const int SearchValue)
{

    for (unsigned int i = 0; i < Length; i++)
        if (Array[i] == SearchValue)
            return i;

    return -1;
}

void printResult(int Position, int SearchValue)
{

    cout << "Number you are looking for is :" << SearchValue << "\n";

    if (Position == -1)
        cout << "The Number is not found :-(" << endl;

    else
    {
        cout << "The number found at position " << Position << "\n";
        cout << "The Number found its order : " << Position + 1 << "\n";
    }
}
int main()
{
    srand(time(NULL));
    int Array[100];
    unsigned Length = 0;
    ReadArrayRandomValues(Array, Length);
    PrintArrayValues("Array 1  Element : ", Array, Length);

    int SearchValue = ReadNumberInRange("Ente a Number to search for :", 0, 100);
    printResult(GetSearchValuePosition(Array, Length, SearchValue), SearchValue);

    return 0;
}