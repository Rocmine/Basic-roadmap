#include <iostream>
#include <string>
using namespace std;

/*
   0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua

    

*/

enum enScreenColor
{
    Black,
    Blue,
    Green,
    Aqua
};

string arrColorsCode[4] = {"color 0F", "color 1F", "color 2F", "color 3F"};
void PrintScreen()
{

    cout << "------------------";
    cout << "Enter your Color :"
         << "\n";
    cout << "(0)  Black\n";
    cout << "(1)  Blue\n";
    cout << "(2)  Green \n";
    cout << "(3)  Aqua \n";
    cout << "Your Choice\n";
}

enScreenColor GetUserColor()
{
    unsigned short UserColor = 0;
    PrintScreen();
    cin >> UserColor;
    return enScreenColor(UserColor);
}

void ApplyUserColor(enScreenColor UserColor)
{

    if (UserColor > enScreenColor::Aqua || UserColor < enScreenColor::Black)
    {
        cout << "Invalid Color :" << endl;
    }
    else
    {
        system(arrColorsCode[UserColor].c_str());
    }
}
int main()
{
    enScreenColor UserColor = GetUserColor();
    ApplyUserColor(UserColor);

    return 0;
}