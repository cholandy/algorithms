#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcd";
    int i;

    for (i = 0; i < str.length(); i++)
    {
        cout << str[i] << endl;
    }

    return 0;
}