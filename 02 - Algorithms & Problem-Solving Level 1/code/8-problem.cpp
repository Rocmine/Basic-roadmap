// problem 8 :
/*
write a program to ask the user to enter :
.mark
then print the pass if mark >=50 otherwise print 'fail'
*/

#include <iostream>

using namespace std;
int main()
{

    int mark = 0;

    try
    {
        cout << "entre your mark :";
        cin >> mark;

        if (cin.fail())
            throw runtime_error("invalid mark ");
        if (mark < 0 || mark > 100)
            throw runtime_error("the mark should be between 0 and 100");

        mark >= 50 ? throw string("pass") : throw string("fail");
    }
    catch (runtime_error e)
    {
        cout << "Error " << e.what() << endl;
    }
    catch (string response)
    {
        cout << response << endl;
    }
    return 0;
}