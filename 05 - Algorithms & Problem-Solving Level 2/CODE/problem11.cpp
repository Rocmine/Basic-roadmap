#include <iostream>
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

unsigned GetReverseNumber(unsigned Number)
{
    unsigned ReversedNumber = 0;
    while (Number != 0)
    {
        ReversedNumber = ReversedNumber * 10 + Number % 10;
        Number /= 10;
    }
    return ReversedNumber;
}

enum enPalindrome
{
    NotPalindrome,
    IsPalindrome
};

enPalindrome isPalindrome(unsigned Number)
{
    return Number == GetReverseNumber(Number) ? enPalindrome::IsPalindrome : enPalindrome::NotPalindrome;
}

void PrintResult(enPalindrome Stat)
{

    Stat == enPalindrome::IsPalindrome ? cout << " Yes It's a Palindrome Number :" : cout << " No It's Not a Palindrome Number :";
}
int main()
{

    PrintResult(isPalindrome(ReadPositiveNumber("Enter a Number : ")));

    return 0;
}