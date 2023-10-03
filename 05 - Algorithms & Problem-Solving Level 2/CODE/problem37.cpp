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

void AddArrayElement(int Number, int arr[100], unsigned &Length)
{
    arr[Length++] = Number;
}
template <typename T>
void CopyArrayUsingAddArrayElement(T Array[], const unsigned Length, T CopyArray[], unsigned &Length2)
{
    T Sum = 0;
    for (unsigned i = 0; i < Length; i++)
        AddArrayElement(Array[i], CopyArray, Length2);
}

template <typename T>
void PrintResultOnScreen(const string TextToShow, T Result)
{
    cout << TextToShow << Result << "\n";
}

int main()
{
    srand(time(NULL));
    int Array[100];
    int Array2[100];
    unsigned Length = 0;
    unsigned Length2 = 0;
    ReadArrayRandomValues(Array, Length);
    PrintArrayValues("Array 1  Element : ", Array, Length);

    CopyArrayUsingAddArrayElement(Array, Length, Array2, Length2);
    PrintArrayValues("Array 2  Element : ", Array2, Length2);
    return 0;
}
