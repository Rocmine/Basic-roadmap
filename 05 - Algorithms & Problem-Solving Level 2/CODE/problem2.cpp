#include <iostream>

using namespace std;

enum enPrime
{
    NotPrime,
    IsPrime
};
unsigned GetRange()
{
    unsigned  Range = 0;
    cout << "Enter  the Range  :";
    cin >> Range;
    return Range;
}

enPrime isPrimeNumber(unsigned Num)
{
    for (unsigned i = 2; i <= Num / 2; i++)
        if (Num % 2 == 0)
            return enPrime::NotPrime;
    return enPrime::IsPrime;
}

void CheckIfNumbersInRangePrime(unsigned Range)
{


    cout << "the Range Of Prim Number is :";
    for (unsigned i = 1; i <= Range; i++)
    {

        if (isPrimeNumber(i) == enPrime::IsPrime)
            cout << i << " ";
    }
}
int main()
{
    CheckIfNumbersInRangePrime(GetRange()); 

    return 0;
}