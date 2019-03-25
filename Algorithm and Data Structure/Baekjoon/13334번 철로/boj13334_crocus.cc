#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <functional>
 
using namespace std;
 
map<pair<int, int>, int> mp;
 
int main()
{
    int n;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        a > b ? mp[{a, b}]++ : mp[{b, a}]++;
    }
 
    int d;
    scanf("%d", &d);
 
    int ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
 
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        int hereE = it->first.first; // end
        int hereS = it->first.second; // start
        int hereC = hereE - hereS; // cost
        int cnt = it->second;
 
        for(int i = 0 ; i < cnt; i ++)
            pq.push(hereS);
 
        while (!pq.empty())
        {
            int top = pq.top();
            if (hereE - d <= top)
                break;
 
            pq.pop();
        }
 
        ans = max(ans, (int)pq.size());
    }
 
    printf("%d", ans);
    return 0;
}

