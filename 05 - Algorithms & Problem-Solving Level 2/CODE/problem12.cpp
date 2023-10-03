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

    for (unsigned i = Number; i > 0; i--)
    {

        for (unsigned j = 0; j < i; j++)
        {
            cout << i;
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