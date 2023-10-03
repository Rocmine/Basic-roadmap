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
int ReadNumber(string UserText)
{
    int num = 0;

    cout << UserText;
    cin >> num;

    return num;
}
void ReadArrayValues(int Array[50], unsigned &Length)
{
    Length = ReadPositiveNumber("Enter the length :");
    for (unsigned i = 0; i < Length; i++)
    {
        Array[i] = ReadNumber("Element [" + to_string(i + 1) + "] : ");
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

void Swap(int &a, int &b)
{
    a += b;
    b = a - b;
    a -= b;
}

void ShuffleArray(int Array[], const unsigned Length)
{

    for (unsigned i = 0; i < Length; i++)
    {

        unsigned RandomIndex1 = GetRandomNumber(0, Length - 1);
        unsigned RandomIndex2 = GetRandomNumber(0, Length - 1);
        Swap(Array[RandomIndex1], Array[RandomIndex2]);
    }
}

int main()
{
    srand(time(NULL));
    int Array[100];

    unsigned Length = 0;
    ReadArrayValues(Array, Length);
    PrintArrayValues("Array  Elements before shuffle : ", Array, Length);
    ShuffleArray(Array, Length);
    PrintArrayValues("Array Elements after shuffle   : ", Array, Length);
    return 0;
}
