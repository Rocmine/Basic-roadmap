#include <iostream>
#include <ctime>
using namespace std;

int GetRandomNumber(int From, int To)
{

    return rand() % (To - From + 1) + From;
}

void Print3RandomNumbersFrom1To10()
{

    for (int i = 0; i < 3; i++)
        cout << GetRandomNumber(1, 10) << "\n";
}
int main()
{
    srand(time(0));
    Print3RandomNumbersFrom1To10();
    Print3RandomNumbersFrom1To10();
    Print3RandomNumbersFrom1To10();

    return 0;
}