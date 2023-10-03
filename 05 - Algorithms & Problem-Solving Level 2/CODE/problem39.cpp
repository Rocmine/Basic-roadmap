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
enum enPrime
{
    NotPrime,
    IsPrime
};
enPrime isPrimeNumber(unsigned Num)
{
    for (unsigned i = 2; i <= Num / 2; i++)
        if (Num % 2 == 0)
            return enPrime::NotPrime;
    return enPrime::IsPrime;
}
template <typename T>
void AddArrayOfOddNumbers(T Array[], const unsigned Length, T CopyArray[], unsigned &Length2)
{

    for (unsigned i = 0; i < Length; i++)
        if (isPrimeNumber(Array[i]) == enPrime::IsPrime)
            AddArrayElement(Array[i], CopyArray, Length2);
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

    AddArrayOfOddNumbers(Array, Length, Array2, Length2);
    PrintArrayValues("Array 2  Prime Numbers  : ", Array2, Length2);
    return 0;
}
