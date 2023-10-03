
// problem 15 :
/*
write a program to calculate rectangle area and print it on the screen :
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    float width = 0;
    float height = 0;

    cout << "enter the  width :";
    cin >> width;
    cout << "enter the height :";
    cin >> height;
    int aria = width * height;
    cout << "the aria is :" << fixed << setprecision(2) << aria << endl;

    return 0;
}