#pragma once
#include <iostream>
#include <vector>
using namespace std;
class cString
{

    string value;

protected:
    static char invertCase(char character)
    {

        if (isupper(character))
            return tolower(character);
        else
            return toupper(character);
    }
    static void shiftLeft(const int shiftIndex, string &str)
    {

        for (int i = shiftIndex; i < str.length() - 1; i++)
        {

            str[i] = str[i + 1];
        }
        str.resize(str.length() - 1);
    }

public:
    // empty constructor :
    cString() : value("") {}

    // parametrized constructor :
    cString(const char *value) : value(value)
    {
    }

    // copy constructor :
    cString(const cString &copy) : value(copy.value) {}

    // cout operator :
    friend ostream &operator<<(ostream &out, const cString &ob)
    {

        cout << ob.value;
        return out;
    }

    // cin operator :
    friend istream &operator>>(istream &inp, cString &ob)
    {

        cin >> ob.value;
        return inp;
    }

    // operator [] :
    char &operator[](const int &index)
    {
        if (index < 0 || index >= value.length())
        {
            cerr << "Error: Index out of bounds char& operator[](const int& index)  cString class " << std::endl;
            exit(1);
        }

        return value[index];
    }

    // operator  += :
    void operator+=(const cString &ob2)
    {
        value += ob2.value;
    }
    void operator+=(const char *value)
    {
        this->value += value;
    }
    void operator+=(const char value)
    {
        this->value += string(1, value);
    }

    // operator   + :
    cString operator+(const cString &ob)
    {

        cString temp;
        temp.value = value + ob.value;

        return temp;
    }
    cString operator+(const char *value)
    {

        cString temp;
        cout << "temp 2: " << temp.value << "\n";
        temp.value = this->value + string(value);

        return temp;
    }

    cString operator+(const char value)
    {

        cString temp;

        temp.value = this->value + string(1, value);
        cout << "temp 3: " << temp.value << "\n";

        return temp;
    }
    cString operator+(string value)
    {

        cString temp;
        cout << "temp : " << temp.value << "\n";
        temp.value = this->value + value;

        return temp;
    }

    // operator = :

    void operator=(const string &value)
    {

        this->value = value;
    }
    void operator=(const char *value)
    {

        this->value = value;
    }
    void operator=(const char value)
    {

        this->value = string(1, value);
    }
    static string camelCase(string &str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            if ((i == 0 || str[i - 1] == ' '))
                str[i] = toupper(str[i]);
        }
        return str;
    }
    static string camelCase(char *c)
    {
        string str(c);
        camelCase(str);
        return str;
    }
    string camelCase()
    {
        return camelCase(value);
    }

    static void lowerFirstLetter(string &str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            if ((i == 0 || str[i - 1] == ' '))
                str[i] = tolower(str[i]);
        }
    }
    static string lowerFirstLetter(char *c)
    {
        string str(c);

        lowerFirstLetter(str);
        return str;
    }

    void lowerFirstLetter()
    {

        lowerFirstLetter(value);
    }
    static void toLower(string &str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            str[i] = tolower(str[i]);
        }
    }
    static string toLower(char *c)
    {
        string str(c);
        toLower(str);
        return str;
    }
    static void toUpper(string &str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]);
        }
    }
    static string toUpper(char *c)
    {
        string str(c);
        toUpper(str);
        return str;
    }

    void toLower()
    {
        toLower(value);
    }
    void toUpper()
    {
        toUpper(value);
    }

    static void invert(string &str)
    {

        for (int i = 0; i < str.length(); i++)
        {
            str[i] = invertCase(str[i]);
        }
    }
    static string invert(char *c)
    {

        string str(c);
        invert(str);
        return str;
    }
    void invert()
    {

        invert(value);
    }

    static int NumberOfCapitaLetter(const string &str)
    {

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {

            if (isupper(str[i]))
                count++;
        }

        return count;
    }
    static int NumberOfCapitaLetter(const char *c)
    {

        string str(c);
        return NumberOfCapitaLetter(str);
    }
    void NumberOfCapitaLetter() const
    {
        NumberOfCapitaLetter(value);
    }

    static int NumberOfSmallLetter(const string &str)
    {

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {

            if (islower(str[i]))
                count++;
        }

        return count;
    }
    static int NumberOfSmallLetter(const char *c)
    {

        string str(c);

        return NumberOfSmallLetter(str);
    }
    void NumberOfSmallLetter() const
    {
        NumberOfSmallLetter(value);
    }

    static int NumberOfFrequencyOfLetter(const string &str, const char &letter)
    {

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {

            if (str[i] == letter)
                count++;
        }

        return count;
    }
    static int NumberOfFrequencyOfLetter(const char *c, const char &letter)
    {
        string str(c);
        return NumberOfFrequencyOfLetter(str, letter);
    }
    int NumberOfFrequencyOfLetter(const char &letter)
    {

        return NumberOfFrequencyOfLetter(value, letter);
    }

    static int NbrFrequencyOfLetterNoCase(const string &str, const char &letter)
    {

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {

            if (toupper(str[i]) == toupper(letter))
                count++;
        }

        return count;
    }
    static int NbrFrequencyOfLetterNoCase(const char *c, const char &letter)
    {
        string str(c);
        return NbrFrequencyOfLetterNoCase(str, letter);
    }

    int NbrFrequencyOfLetterNoCase(const char &letter) const
    {

        return NbrFrequencyOfLetterNoCase(value, letter);
    }

    static bool checkIfLetterIsVowel(const char &letter)
    {

        char UppLetter = tolower(letter);
        return (UppLetter == 'a' || UppLetter == 'e' || UppLetter == 'i' || UppLetter == 'o' || UppLetter == 'u') ? true : false;
    }

    static int countVowels(const string &str)
    {

        int count = 0;
        for (int i = 0; i < str.length(); i++)
        {

            if (checkIfLetterIsVowel(str[i]))
                count++;
        }

        return count;
    }
    static int countVowels(const char *c)
    {
        string str(c);
        return countVowels(str);
    }

    int countVowels()
    {
        return countVowels(value);
    }

    static int countWord(string str, const string delim = " ")
    {
        short counter = 0;
        short pos = 0;
        string word;

        while ((pos = str.find(delim)) != string::npos)
        {

            word = str.substr(0, pos);
            if (word != "")
                counter++;

            str.erase(0, pos + delim.length());
        }

        // counts the last word :
        if (str != "")
            counter++;

        return counter;
    }
    static int countWord(const char *c, const string delim = " ")
    {
        string str(c);
        return countWord(str, delim);
    }

    int countWord(const string delim = " ") const
    {

        return countWord(value, delim);
    }

    static vector<string> getSplitStringToVector(string str, const string delim = " ")
    {
        vector<string> vstr;
        short counter = 0;
        short pos = 0;
        string word;

        while ((pos = str.find(delim)) != string::npos)
        {

            vstr.push_back(str.substr(0, pos));

            str.erase(0, pos + delim.length());
        }

        // counts the last word :
        if (str != "")
            vstr.push_back(str);

        return vstr;
    }
    static vector<string> getSplitStringToVector(const char *c, const string delim = " ")
    {
        string str(c);
        return getSplitStringToVector(str, delim);
    }

    vector<string> getSplitStringToVector() const
    {

        return getSplitStringToVector(value);
    }

    static string getTrimLeft(string str)
    {

        for (int i = 0; i < str.length(); i++)
        {

            if (str[i] != ' ')
                return str;

            if (str[i] == ' ')
            {
                shiftLeft(i, str);
                i--;
            }
        }
        return str;
    }
    static string getTrimLeft(const char *c)
    {
        string str(c);
        return getTrimLeft(str);
    }
    string getTrimLeft() const
    {
        return getTrimLeft(value);
    }

    static string getTrimRight(string str)
    {

        for (int i = str.length() - 1; i >= 0; i--)
        {

            if (str[i] != ' ')
                return str;

            if (str[i] == ' ')
                str.resize(str.length() - 1);
        }
        return str;
    }
    static string getTrimRight(const char *c)
    {
        string str(c);
        return getTrimRight(str);
    }

    string getTrimRight() const
    {
        return getTrimRight(value);
    }

    static string getTrim(string str)
    {

        str = getTrimLeft(str);
        str = getTrimRight(str);
        return str;
    }
    static string getTrim(const char *c)
    {
        string str(c);
        return getTrim(str);
    }

    string getTrim() const
    {
        return getTrim(value);
    }

    static string joinString(const vector<string> &vStr, const string delim = " ")
    {

        string resultStr = "";
        for (const string &element : vStr)
        {

            resultStr += element + delim;
        }

        return resultStr.substr(0, resultStr.length() - delim.length());
    }

    static string joinString(const string arrStr[], const int length, const string delim = " ")
    {

        string resultStr = "";

        for (int i = 0; i < length; i++)
        {

            resultStr += arrStr[i] + delim;
        }

        return resultStr.substr(0, resultStr.length() - delim.length());
    }

    static string getReverseString(const string &str)
    {

        vector<string> vStr = getSplitStringToVector(str);

        string resultStr = "";
        for (int i = vStr.size() - 1; i >= 0; i--)
        {

            resultStr += vStr[i] + " ";
        }

        return resultStr;
    }

    static string getReverseString(const char *c)
    {

        string str(c);
        return getReverseString(str);
    }
    string getReverseString() const
    {

        return getReverseString(value);
    }

    static void replaceWordInString(string &str, const string &oldWord, const string &newWord)
    {

        string word = "";
        string resultStr;
        for (int i = 0; i < str.length(); i++)
        {

            if (str[i] != ' ')
                word += str[i];

            if (((i != str.length() - 1) && (str[i] != ' ' && str[i + 1] == ' ' && word != "")) || (i == str.length() - 1 && str[str.length() - 1] != ' '))
            {
                if (word == oldWord)
                    word = newWord;
                resultStr += word + " ";
                word = "";
            }
        }
        str = resultStr;
    }

    static short length(const string &str)
    {
        return str.length();
    }
    static short length(const char *c)
    {
        string str(c);
        return length(str);
    }
    short length() const
    {
        return length(value);
    }

    string getValue()
    {
        return value;
    }
};
