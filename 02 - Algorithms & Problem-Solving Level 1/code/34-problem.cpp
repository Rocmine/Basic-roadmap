#include <iostream>
using namespace std;

// problem 34 :
/*
write a problem to ask the user to enter totalSales
the commission is calculated as one percentage * the total sales amount, all you need is to decide which percentage to use of the
following :

TotalSales> 1k => 1%
500k to 1M => 2%
100k to 500k => 3%
50k to 100k => 5%
otherwise => 0%
*/

int getNumber()
{
    int Ts = 0;

    cout << "enter the total Sales : ";
    cin >> Ts;

    if (cin.fail())
        throw runtime_error(" invalid value you should enter a digit");
    if (Ts < 0)
        throw string("you have to enter a number grater than 0 ");

    return Ts;
}

void ThrowResult(int Ts = 0)
{
    if (Ts >= 500000 && Ts <= 1000000)
        throw float(Ts*0.02);
    if (Ts >= 100000)
        throw float(Ts*0.03);
    if (Ts >= 50000)
        throw float( Ts*0.05);
    if (Ts >= 1000)
        throw float(Ts*0.01);
    else
        throw float(0);
}

int main()
{

    int ts = 0;
    try
    {

        ts = getNumber();
        ThrowResult(ts);
    }
    catch (runtime_error e)
    {
        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (float Per)
    {
        // warning message
        cout << Per<< endl;
    }
    return 0;
}