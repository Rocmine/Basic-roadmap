#include <iostream>
using namespace std;

void printAllFromAAAToZZZ()
{

    for (unsigned i = int('A'); i <= int('Z'); i++)
    {
        for (unsigned j = int('A'); j <= int('Z'); j++)
        {
            for (unsigned k = int('A'); k <= int('Z'); k++)
            {

                cout << char(i) << char(j) << char(k) << "\n";
            }
            cout << endl;
        }
    }
}

int main()
{
    printAllFromAAAToZZZ();

    return 0;
}