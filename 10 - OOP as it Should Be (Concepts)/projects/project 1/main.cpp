#include <iostream>
using namespace std;

//  calculator class :
/*
add();
clear();
divide();
printFinalResult();
multiply();
printResult();
subtract();
*/

class clsCalculator
{

    int cFinalResult = 0;
    string cCurrentOperation = "clearing";
    int cOperationValue = 0;

public:
    void add(int addedValue)
    {
        cCurrentOperation = "adding";
        cOperationValue = addedValue;
        cFinalResult += addedValue;
    }
    void clear()
    {
        cCurrentOperation = "clearing";
        cOperationValue = 0;
        cFinalResult = 0;
    }
    void divide(int dividedValue)
    {

        if (dividedValue == 0)
            dividedValue = 1;
        cCurrentOperation = "dividing";
        cOperationValue = dividedValue;
        cFinalResult /= dividedValue;
    }

    void printFinalResult()
    {
        if (cCurrentOperation == "clear")
            cout << "\nResult after " << cCurrentOperation << " is " << cFinalResult << endl;

        else

            cout << "\nResult after " << cCurrentOperation << " " << cOperationValue << " is " << cFinalResult << endl;
    }

    void subtract(int subtractedValue)
    {
        cCurrentOperation = "subtracting";
        cOperationValue = subtractedValue;
        cFinalResult -= subtractedValue;
    }

    void multiply(int subtractedValue)
    {
        cCurrentOperation = "multiplying";
        cOperationValue = subtractedValue;
        cFinalResult *= subtractedValue;
    }
};

int main()
{
    clsCalculator cal1;
    cal1.add(10);
    cal1.printFinalResult();

    cal1.subtract(5);
    cal1.printFinalResult();

    cal1.divide(0);
    cal1.printFinalResult();

    cal1.multiply(2);
    cal1.printFinalResult();

    cal1.clear();
    cal1.printFinalResult();

    return 0;
}