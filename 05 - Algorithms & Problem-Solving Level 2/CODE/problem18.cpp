#include <iostream>
using namespace std;
const unsigned short enCryptCode = 20;
string ReadString(string UserText)
{
    string str = "";
    cout << UserText;
    cin >> str;

    return str;
}

void enCrypt(string &UserText)
{

    for (int i = 0; i < UserText.length(); i++)
    {
        UserText[i] += enCryptCode;
    }
}

void PrintText(string UserText, string Message)
{

    cout << Message << " " << UserText << endl;
}

void DecCrypt(string &UserText)
{

    for (int i = 0; i < UserText.length(); i++)
    {
        UserText[i] -= enCryptCode;
    }
}
int main()
{
    string UserText = ReadString("Enter  A Text: ");

    enCrypt(UserText);
    PrintText(UserText, "Text Before Encryption :");
    DecCrypt(UserText);

    PrintText(UserText, "Text After Encryption :");

    return 0;
}