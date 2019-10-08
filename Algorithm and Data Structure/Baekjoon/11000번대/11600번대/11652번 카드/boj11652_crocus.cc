#include <iostream>
#include <cstdio>
#include <map>
#include <limits.h>
 
using namespace std;
typedef long long ll;
 
map<ll, int> mp;
 
 
int main()
{
    int n, j = 0;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        ll val;
        scanf("%lld", &val);
 
        mp[val]++;
    }
 
    int maxnum = -1;
    ll val;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > maxnum)
        {
            maxnum = it->second;
            val = it->first;
        }
    }
    printf("%lld", val);
    return 0;
}