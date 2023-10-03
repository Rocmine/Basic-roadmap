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

template <typename T>
void copyReverseArray(T Array[], const unsigned Length, T ReverseArray[])
{

    int CopyArrayCounter = Length - 1;
    for (int i = 0; i < Length; i++)
        ReverseArray[CopyArrayCounter--] = Array[i];
}

int main()
{
    srand(time(NULL));
    int Array[100];
    int Array2[100];
    unsigned Length = 0;
    ReadArrayRandomValues(Array, Length);
    PrintArrayValues("Array 1  Element : ", Array, Length);

    copyReverseArray(Array, Length, Array2);
    PrintArrayValues("Array 2  Element  after copying in reverse order : ", Array2, Length);
    return 0;
}
