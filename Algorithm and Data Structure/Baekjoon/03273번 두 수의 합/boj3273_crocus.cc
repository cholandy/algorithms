#include <iostream>
#include <cstdio>
#include <map>
 
using namespace std;
 
map<int, bool> mp;
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        mp[val] = true;
    }
 
    int m;
    int cnt = 0;
    scanf("%d", &m);
 
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 0)
            continue;
 
        int here = it->first;
 
        if (m > here && mp[m - here] && m - here != here)
        {
            cnt++;
            mp[m - here] = 0;
        }        
    }
    printf("%d", cnt);
    return 0;
}