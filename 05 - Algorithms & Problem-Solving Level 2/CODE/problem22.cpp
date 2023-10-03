#include <iostream>
#include <string>
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

unsigned GetNumberOfRepeatedINArray(const int Array[50], const unsigned Length, const int SearchValue)
{

    unsigned SearchValueOccurrence = 0;
    for (unsigned int i = 0; i < Length; i++)
        if (Array[i] == SearchValue)
            SearchValueOccurrence++;

    return SearchValueOccurrence;
}

template <typename T>
void PrintResultOnScreen(const string TextToShow, T Result)
{
    cout << TextToShow << Result << "\n";
}

int main()
{
    int Array[50];
    unsigned int Length = 0;

    ReadArrayValues(Array, Length);
    const int SearchValue = ReadNumber("Enter the number you want to check : ");
    PrintResultOnScreen("the Number of repeated of " + to_string(SearchValue) + " is : ", GetNumberOfRepeatedINArray(Array, Length, SearchValue));
}