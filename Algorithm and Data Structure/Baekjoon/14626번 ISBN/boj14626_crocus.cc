#include <iostream>
#include <cstdio>
#include <string>
 
using namespace std;
 
int main()
{
    string str;
 
    cin >> str;
 
    int ans = 0;
    int chk = 1;
 
    int pos, val;
    for (int val = 0; val <= 9; val++)
    {
        ans = 0;
        chk = 1;
        for (int i = 0; i < str.size() - 1; i++)
        {
            if (str[i] == '*')
                ans += val * chk;
            
            else
                ans += (str[i] - '0') * chk;
 
            chk == 1 ? chk = 3 : chk = 1;
        }
        ans += str[str.size() - 1] -'0';
 
        if (ans % 10 == 0)
        {
            cout << val << endl;
            break;
        }
    }
 
    return 0;
}
