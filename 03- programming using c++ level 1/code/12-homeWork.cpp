#include <iostream>
#include <string>

using namespace std;
/*
convert string str1="43.22" to double float and int
convert integer n1-20 to string
convert double n2=33.5 to string
convert float n3=55.23 to string, and integer
*/

int main()
{

    string str = "43.33";

    int intNum = stoi(str);
    float flNUm = stof(str);
    double dblNum = stod(str);

    cout << "string to int     :" << intNum << "\n";
    cout << "string to  float  :" << flNUm << "\n";
    cout << "string to  double :" << dblNum << "\n\n";

    int n1 = 20;
    str = to_string(n1);
    cout << "int to string :" << str << "\n";
    double n2 = 33.5;
    str = to_string(n2);
    cout << "double to string :" << str << "\n";

    float n3 = 55.23;
    str = to_string(n3);
    cout << "double to string :" << str <<endl;

    return 0;
}