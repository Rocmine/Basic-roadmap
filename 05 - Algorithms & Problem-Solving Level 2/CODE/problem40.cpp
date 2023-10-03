#include <iostream>
#include <string>
using namespace std;

void PrintArrayValues(const string TextToShow, int Array[], const unsigned Length)
{
    cout << TextToShow << " ";
    for (unsigned i = 0; i < Length; i++)
    {
        cout << Array[i] << " ";
    }
    cout << endl;
}

void AddArrayElement(int Number, int arr[], unsigned &Length)
{
    arr[Length++] = Number;
}

bool isAlreadyChecked(int Number, int Array[], unsigned CurrentIndex)
{

    for (int i = 0; i < CurrentIndex; i++)
        if (Number == Array[i])
            return true;

    return false;
}

template <typename T>
void AddArrayOfDistinctNumbers(T Array[], const unsigned Length, T CopyArray[], unsigned &Length2)
{

    for (unsigned i = 0; i < Length; i++)
    {

        if (!isAlreadyChecked(Array[i], Array, i))     AddArrayElement(Array[i], CopyArray, Length2);
        
    }
}

int main()
{

    int Array[10] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    int Array2[10];
    unsigned Length = 10;
    unsigned Length2 = 0;
    PrintArrayValues("Array 1  Element : ", Array, Length);

    AddArrayOfDistinctNumbers(Array, Length, Array2, Length2);
    PrintArrayValues("Array 2  Distinct Numbers  : ", Array2, Length2);
    return 0;
}