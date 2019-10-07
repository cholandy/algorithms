#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    string str;
 
    getline(cin, str);
 
    int len = str.size();
 
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        while (i < len && str[i] == ' ')
            i++;
 
        if (i < len && str[i] != ' ')
        {
            ans++;
 
            while (i < len && str[i] != ' ')
                i++;
        }
    }
    cout << ans;
    return 0;
}
