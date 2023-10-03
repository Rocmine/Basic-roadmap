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

        if (isDividedByNum2(Number, i) == enDivided::isDivided)
            SumOfDivisors += i;

    return SumOfDivisors;
}

enum enPerfect
{
    NotPerfect,
    IsPerfect
};
enPerfect isPrefect(unsigned Number)
{

    return Number == GetSumOfDivisors(Number) ? enPerfect::IsPerfect : enPerfect::NotPerfect;
}

void CheckPrefectNUmbersFrom1ToN(unsigned Number)
{

    for (unsigned i = 1; i <= Number; i++)
    {
        if (isPrefect(i) == enPerfect::IsPerfect)
            cout << i << " is Perfect \n\n";
    }
}
int main()
{

    CheckPrefectNUmbersFrom1ToN(GetPositiveNumber("enter The Range : "));
    return 0;
}