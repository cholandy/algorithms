#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string str;
    int low[26] = {
        0,
    },
        up[26] = {
            0,
        },
        i;

    getline(cin, str);
    for (i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            low[str[i] - 'a']++;
        if (isupper(str[i]))
            up[str[i] - 'A']++;
    }
    for (i = 0; i < 26; i++)
    {
        if (low[i] > 0)
        {
            cout << char('a' + i) << " = " << low[i] << endl;
        }
    }
    for (i = 0; i < 26; i++)
    {
        if (up[i] > 0)
        {
            cout << char('A' + i) << " = " << up[i] << endl;
        }
    }

    return 0;
}