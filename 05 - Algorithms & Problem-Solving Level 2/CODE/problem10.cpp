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

void PrintNumberDigits(unsigned Number)
{
    if (Number == 0)
        return;

    PrintNumberDigits(Number / 10);
    cout << Number % 10 << endl;
}
int main()
{
    PrintNumberDigits(ReadPositiveNumber("Enter a  positive Number  : "));

    return 0;
}