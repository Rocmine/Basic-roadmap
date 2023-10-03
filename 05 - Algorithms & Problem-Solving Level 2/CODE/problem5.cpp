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

void PrintReversedNumber(unsigned Number)
{
    if (Number == 0)
        return;

    cout << Number% 10 << endl;
    PrintReversedNumber(Number / 10);
}
int main()
{
    PrintReversedNumber(ReadPositiveNumber("Enter a  positive Number  : "));
 
    return 0;
}