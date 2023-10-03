#include <iostream>

using namespace std;

unsigned GetPositiveNumber(string UserText)
{
    unsigned int num = 0;

    do
    {
        cout << UserText;
        cin >> num;
    } while (num <= 0);
    return num;
}

enum enDivided
{
    NotDivided,
    isDivided
};
enDivided isDividedByNum2(unsigned num1, unsigned num2)
{
    return num1 % num2 == 0 ? enDivided::isDivided : enDivided::NotDivided;
}

unsigned GetSumOfDivisors(unsigned Number)
{
    unsigned SumOfDivisors = 0;
    for (unsigned i = 1; i < Number; i++)

        if (isDividedByNum2(Number, i) == enDivided::isDivided)  SumOfDivisors += i;

    return SumOfDivisors;
}

void isPrefect(unsigned Number)
{

    Number == GetSumOfDivisors(Number) ? cout << Number << " is Perfect" : cout << Number << " is Not Perfect";
}
int main()
{
    isPrefect(GetPositiveNumber("Enter a positive Number :"));
    return 0;
}