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
void PrintPattern(unsigned Number)
{

    for (unsigned i = 65; i <= 64 + Number; i++)
    {

        for (unsigned j = 65; j <= i; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
    cout << endl;
}
int main()
{
    PrintPattern(ReadPositiveNumber("Enter a  positive Number  : "));

    return 0;
}