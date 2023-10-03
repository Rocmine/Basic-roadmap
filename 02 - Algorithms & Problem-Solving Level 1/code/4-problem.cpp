
/*
write a program to ask the user to entre his/her
.age
.driver license
then print hired if his\her age is grater than 21 and she/he has a driver license, otherwise  'Rejected'

*/

#include <iostream>
using namespace std;

int main()
{

    int age;
    bool haveADriveLIcense = false;

    try
    {

        cout << "entre your age :";
        cin >> age;
        // clear the buffer (if the  user enter 2d the int(2d) => 2  then I need to clear the d in the buffer)
        cin.ignore();
        if (cin.fail())
            throw runtime_error("invalid  age value User input  :");

        cout << " do you have a licence  \n 1 : yes  \n 0: no " << endl;
        cin >> haveADriveLIcense;

        if (haveADriveLIcense != 1 && haveADriveLIcense != 0)
            throw runtime_error("invalid  input you have to choice just 1:yes or 0:no  ");

        if (haveADriveLIcense && age >= 21)
            throw string("hired");
        else
            throw string("rejected");
    }
    catch (runtime_error e)
    {
        cerr << "Error " << e.what() << endl;
    }
    catch (string response)
    {
        system("cls");
        cout << response << endl;
    }

    return 0;
}