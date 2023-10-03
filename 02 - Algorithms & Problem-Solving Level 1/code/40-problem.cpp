#include <iostream>
#include <iomanip>

using namespace std;

// problem 40 :
/*
a restaurant changes 10% services fee and 16% sales tax
Write a program to read a BillValue and  add  service fee and sales tax to it,  then print the totalBill on the Screen :
*/

int getBill()
{
    float bill;
    cout << "enter the bill :";
    cin >> bill;
    if (cin.fail() || bill < 0)
        throw runtime_error("you should enter a positive digit : ");
    return bill;
}

void addTaskAndFee(float bill)
{

    float TotalBill = (bill * 1.1) * 1.16;
    throw float(TotalBill);
}

int main()
{

    try
    {
        float bill = getBill();
        addTaskAndFee(bill);
    }
    catch (runtime_error e)
    {
        cin.clear();
        cin.ignore();
        cout << "Error :" << e.what() << endl;
    }
    catch (float result)
    {
        cout << "the total  Bill is :" << fixed << setprecision(2) << result << endl;
    }
    return 0;
}