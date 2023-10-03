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
T GetSumArray(T Array[], const unsigned Length)
{
    T Sum = 0;
    for (unsigned i = 0; i < Length; i++)  Sum += Array[i];

    return Sum;
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
    unsigned Length = 0;
    ReadArrayRandomValues(Array, Length);
    PrintArrayValues("Array Element : ", Array, Length);
    PrintResultOnScreen("Sum Of Array is :", GetSumArray(Array, Length));

    return 0;
}
