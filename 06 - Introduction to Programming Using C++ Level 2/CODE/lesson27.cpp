#include <iostream>
#include <iomanip>
using namespace std;

void insertMultipleTableFrom1ToN(int arr[][10], int maxMultiNumber)
{

    for (int i = 0; i < maxMultiNumber; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            arr[i][j] = (i + 1) * (j + 1);
        }
    }
}

void print2DArray(int arr[][10], int l, int c)
{

    for (int i = 0; i < l; i++)
    {
        cout << "\n"
             << setw(2);
        for (int j = 0; j < c; j++)
        {

            cout << (j == 0 ? "|" : "") << setw(3) << arr[i][j] << setw(2) << setw(3) << (j == c - 1 ? "|" : "");
        }
    }
    cout << "\n\n";
}

int main()
{

    int arr[10][10];
    insertMultipleTableFrom1ToN(arr, 10);
    print2DArray(arr, 10, 10);

    return 0;
}