#include <iostream>
using namespace std;

// lesson 49 :

void PrintMultiplicationTable()
{
    cout << endl;

    for (unsigned i = 1; i <= 10; i++)
    {

        cout << "\n\ni= " << i << "\n";

        for (unsigned j = 1; j <= 10; j++)
        {
            cout << "  " << i << " *"
                 << j
                 << "=" << i * j << "\n";
        }
    }
}

void PrintSquare()
{

    cout << endl;
    for (unsigned i = 0; i < 10; i++)
    {
        for (unsigned j = 0; j < 10; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

void PrintDuplicateLetter()
{

    for (char i = 'A'; i <= 'Z'; i++)
    {
        for (char j = 'A'; j <= 'Z'; j++)
        {
            cout << i << j << "\n";
        }
        cout << endl;
    }
}

void PrintInvertedTriangle()
{

    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    cout << endl;
}

void PrintTriangleUsingNumber()
{
    for (int i = 1; i <= 10; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void PrintInvertedTriangleUsingNumber()
{
    for (int i = 1; i <= 10; i++)
    {

        for (int j = 1; j <= 11 - i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void PrintTriangleUsingDuplicateLetters()
{

    for (char i = 0; i <= 5; i++)
    {
        char k = 'A';
        for (int j = 0; j <= i; j++, k++)
        {

            cout << k << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

void PrintInvertedTriangleUsingNumberDropFirst()
{
    for (int i = 1; i <= 10; i++)
    {

        for (int j = i; j <= 10; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    cout << endl;
}
int main()
{

    cout << "\n\n-------------- Problem 1 : ------------------------------\n\n";
    PrintMultiplicationTable();
    cout << "\n\n-------------- Problem 2 : ------------------------------\n\n";
    PrintSquare();
    cout << "\n\n-------------- Problem 3 : ------------------------------\n\n";
    PrintDuplicateLetter();
    cout << "\n\n-------------- Problem 4 : ------------------------------\n\n";
    PrintInvertedTriangle();
    cout << "\n\n-------------- Problem 5 : ------------------------------\n\n";
    PrintInvertedTriangleUsingNumber();
    cout << "\n\n-------------- Problem 6 : ------------------------------\n\n";
    PrintTriangleUsingNumber();
    cout << "\n\n-------------- Problem 7 : ------------------------------\n\n";
    PrintTriangleUsingDuplicateLetters();
    cout << "\n\n-------------- Problem 8 : ------------------------------\n\n";
    PrintInvertedTriangleUsingNumberDropFirst();

    return 0;
}