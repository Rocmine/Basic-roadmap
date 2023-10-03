#include <iostream>

using namespace std;

// lesson 48 :
void ReadArrayData(int Arr1[100], unsigned short &Length)
{

    cout << "How many Numbers do yo Wanna to enter?\n ";
    cin >> Length;

    for (int i = 0; i < Length; i++)
    {
        cout << "enter the Number :";
        cin >> Arr1[i];
    }
}

void PrintArrayData(const int Arr1[100], const unsigned short Length)
{
    for (int i = 0; i < Length; i++)
    {
        cout << "[" << i << "]"
             << "= " << Arr1[i] << "\n";
    }
    cout << endl;
}

int CalculateArraySum(const int Arr1[100], const unsigned short Length)
{
    int SumOfArrayData = 0;

    for (int i = 0; i < Length; i++)
    {
        SumOfArrayData += Arr1[i];
    }

    return SumOfArrayData;
}

float CalculateArrayAverage(const int Arr1[100], const unsigned short Length)
{

    return CalculateArraySum(Arr1, Length) / float(Length);
}

int main()
{

    int Arr1[100];
    unsigned short Length = 0;

    ReadArrayData(Arr1, Length);
    PrintArrayData(Arr1, Length);
    int SumOfArray = CalculateArraySum(Arr1, Length);
    cout << "Sum = " << SumOfArray << "\n";
    cout << "Average = " << (float)SumOfArray / Length << endl;
    // or  cout << "Average = " << CalculateArrayAverage(Arr1, Length) << endl;

    return 0;
}