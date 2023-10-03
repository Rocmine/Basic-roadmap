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

    for (unsigned i = int(64 + Number); i > 64; i--)
    {

        for (unsigned j = 64; j < i; j++)
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