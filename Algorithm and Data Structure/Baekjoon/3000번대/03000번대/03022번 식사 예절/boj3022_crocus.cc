#include <iostream>
#include <cstdio>
#include <map>
#include <string>
 
using namespace std;
 
map<string, int> mp;
 
int main()
{
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
 
        if (!i)
            mp[str]++;
 
        else
        {
            int other = 0;
            for (auto it = mp.begin(); it != mp.end(); it++)
                if (it->first != str)
                    other += it->second;
 
            if (mp[str] > other)
                ans++;
 
            mp[str]++;
        }
 
    }
    printf("%d", ans);
 
    return 0;
}