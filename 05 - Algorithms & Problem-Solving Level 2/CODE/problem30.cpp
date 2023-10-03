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

void GetSumOfTwoArray(int Array1[], const unsigned Length1, int Array2[], const unsigned Length2, int ResultArray[])
{

    for (int i = 0; i < Length1 || i < Length2; i++)
    {

        if (i < Length1 && i < Length2)
            ResultArray[i] = Array1[i] + Array2[i];

        else if (i < Length1)
            ResultArray[i] = Array1[i];
        else
            ResultArray[i] = Array2[i];
    }
}

int main()
{
    srand(time(NULL));
    int Array1[100];
    int Array2[100];
    int ResultArray[100];
    unsigned Length1 = 0;
    unsigned Length2 = 0;
    ReadArrayRandomValues(Array1, Length1);
    ReadArrayRandomValues(Array2, Length2);
    PrintArrayValues("Array 1  Element : ", Array1, Length1);
    PrintArrayValues("Array 2  Element : ", Array2, Length2);
    GetSumOfTwoArray(Array1, Length1, Array2, Length2, ResultArray);
    PrintArrayValues("Prime Number in array 3   : ", ResultArray, Length1 > Length2 ? Length1 : Length2);
    return 0;
}
