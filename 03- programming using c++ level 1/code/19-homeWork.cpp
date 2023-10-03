// lesson 39 :

#include <iostream>

using namespace std;

// Write a program using Array to do the following :
void setGrades(float arrGrades[3])
{
    cout << "Enter Grade1  :";
    cin >> arrGrades[0];

    cout << "Enter Grade2  :";
    cin >> arrGrades[1];

    cout << "Enter Grade3  :";
    cin >> arrGrades[2];
}

float GetAverage(float arrGrades[3])
{

    return ((arrGrades[0] + arrGrades[1] + arrGrades[2]) / 3.0);
}

int main()
{

    float arrGrades[3] = {0, 0, 0};
     setGrades(arrGrades);

    cout << "The average of grades is " << GetAverage(arrGrades) << endl;

    return 0;
}