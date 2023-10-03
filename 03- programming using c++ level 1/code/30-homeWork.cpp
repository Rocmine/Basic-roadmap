#include <iostream>
using namespace std;

// lesson 52 :

void Find20(const unsigned short arr[10])
{

    for (int i = 0; i < 10; i++)
    {

        if (arr[i] == 20)
        {

            cout << i << endl;
            break;
        }
    }
}

int main()
{

    unsigned short arr[10] = {10, 20, 44, 55, 33, 99, 88, 100};

    Find20(arr);
    return 0;
}