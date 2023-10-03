#include <iostream>
#include <string>
using namespace std;

int main()
{

    string userName = "undefined";

    cout << "entre your name :";
    getline(cin >> ws, userName);

    cout << "your name is " << userName << endl;
}