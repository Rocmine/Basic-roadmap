#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// problem 35

/*
write a program to ask the user to enter
.Pennies,Nickels,Quarters,Dollars:

then Calculate the total pennies ,total dollars and print them on screen :
penny=1 ,
nickel=5 ,
dime=10,
Quarter=25,
dollar=100
*/

int *getValues()

{

    int *arr = new int[5];

    cout << "Pennies,Nickels,Dime,Quarters,Dollars: " << endl;

    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    if (cin.fail())
        throw runtime_error("invalid Values");
    return arr;
}
void evaluate(int arr[5], int &TotalPennies, float &TotalDollar)
{
    TotalPennies = arr[0] + arr[1] * 5 + arr[2] * 10 + arr[3] * 25 + arr[4] * 100;
    TotalDollar = TotalPennies / 100.0;
}

void throwResult(int tP = 0, float tD = 0)
{

    throw string("Total Pennies: " + to_string(tP) + "\n"
                                                     "Total Dollars : " +
                 to_string(tD) + "\n");
}

int main()
{

    try
    {

        int *arr = new int[5];
        arr = getValues();

        int TotalP;
        float TotalD;

        evaluate(arr, TotalP, TotalD);

        throwResult(TotalP, TotalD);
    }
    catch (runtime_error e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const string Result)
    {
        cout << Result << endl;
    }

    return 0;
}