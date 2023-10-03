// problem 11:
/*
write a program to ask the user to entre
.mark 1 ,mark 2 ,mark 3
then print the  average of entered marks, and print 'pass if average>=50 otherwise  print "fail"
*/

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float mark1 = 0, mark2 = 0, mark3 = 0;
    cout << "enter three number : ";
    cin >> mark1 >> mark2 >> mark3;
    float avg = (mark1 + mark2 + mark3) / 3;
    cout << fixed << setprecision(2) << avg << " ";
    avg >= 50 ? cout << "pass" : cout << "fail";

    return 1;
}