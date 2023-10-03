#include <iostream>

using namespace std;


void PrintListOfMultiplication()
{
    cout << "\t\t\tMultiplication Table From 1 To 10\n\n";
    cout << "  \t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
    cout << "-----------------------------------------------------------------------------------\n";
}
void ManageSpaces(int Index)
{
    if (Index == 10)
        cout << Index << " |\t";
    else
        cout << Index << "  |\t";
}

void PrintMultiplicationTable()
{
    PrintListOfMultiplication();
    for (unsigned short i = 1; i <= 10; i++)
    {

        ManageSpaces(i);
        for (unsigned short j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }

        cout << "\n";
    }
    cout << endl;
}

int main()
{

    PrintMultiplicationTable();

    return 0;
}