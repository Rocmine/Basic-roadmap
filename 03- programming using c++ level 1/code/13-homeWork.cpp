#include <iostream>
#include <string>
using namespace std;
 // lesson #31 : 
int main()
{

    string str1, str2, str3;
    cout << "enter string 1 : ";
    getline(cin, str1);

    cout << "enter string 2 : ";
    cin >> str2;

    cout << "enter string 3 : ";
    cin >> str3;

    cout << "the length of string is :" << str1.length() << endl;
    cout << "characters at 0,2,4,7 are " << str1.at(0) << " " << str1[2] << " " << str1[4] << " " << str1[7] << "\n";
    cout << "concatenating string 2  and string 3 " << str2 + str3 << "\n";
    cout << str2 << "*" << str3 << "=" << stoi(str2) * stoi(str3) << endl;

    return 0;
}