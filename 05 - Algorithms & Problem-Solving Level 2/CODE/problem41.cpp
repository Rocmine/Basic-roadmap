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

void ReadArrayValues(int Array[50], unsigned &arrLength)
{
    arrLength = ReadPositiveNumber("Enter the length :");
    for (unsigned i = 0; i < arrLength; i++)
    {
        Array[i] = ReadNumber("Element [" + to_string(i + 1) + "] : ");
    }
}
void PrintArrayValues(const string TextToShow, int Array[], const unsigned arrLength)
{
    cout << TextToShow << " ";
    for (unsigned i = 0; i < arrLength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

enum enPalindrome
{
    NotPalindrome,
    IsPalindrome
};
enPalindrome CheckIfArrayIsPalindrome(const int Array[], const unsigned arrLength)
{

    for (int i = 0, j = arrLength - 1; i < arrLength / 2; i++, j--)

        if (Array[i] != Array[j])
            return enPalindrome::NotPalindrome;

    return enPalindrome::IsPalindrome;
}

int main()
{
    int Array[50];
    unsigned int arrLength = 0;

    ReadArrayValues(Array, arrLength);
    PrintArrayValues("Array elements", Array, arrLength);
    CheckIfArrayIsPalindrome(Array, arrLength) == enPalindrome::IsPalindrome ? cout << "Yes Array is Palindrome" : cout << "NO Array is not Palindrome ";
    return 0;
}