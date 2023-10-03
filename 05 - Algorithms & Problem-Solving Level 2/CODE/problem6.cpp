

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

unsigned GetSumOfNumber(unsigned Number)
{
    unsigned sum = 0;
    while (Number != 0)
    {
        sum += Number % 10;
        Number /= 10;
    }
    return sum;
}
void PrintSumOfNumber(unsigned Number)
{
    unsigned Sum = GetSumOfNumber(Number);
    cout << "the sum of Digit is : " << Sum << endl;
}
int main()
{

    PrintSumOfNumber(ReadPositiveNumber("Enter a Number : "));
    return 0;
}