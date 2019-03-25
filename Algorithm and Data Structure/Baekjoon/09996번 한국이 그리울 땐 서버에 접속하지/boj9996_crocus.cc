#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
 
int main()
{
    fastio();
 
    int n;
    string str;
 
    cin >> n;
    cin >> str;
 
    string s = "", e = "";
    int len = str.size();
    int i = 0;
 
    for (i; str[i] != '*'; i++)
        s += str[i];
 
    i++;
 
    for (i; i < len; i++)
        e += str[i];
 
    reverse(e.begin(), e.end());
    while(n--)
    {
        string tmp;
        cin >> tmp;
 
        int sLen = s.size();
        int eLen = e.size();
        if (tmp.substr(0, sLen).compare(s) == 0)
        {
            tmp = tmp.substr(sLen, tmp.size());
            reverse(tmp.begin(), tmp.end());
 
            if (tmp.substr(0, eLen).compare(e) == 0)
            {
                cout << "DA" << endl;
                continue;
            }
        }
        cout << "NE" << endl;
    }
    return 0;
}
