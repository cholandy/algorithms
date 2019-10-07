#include <iostream>
#include <cstdio>
#include <map>
#include <string>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
string str[1002];
map<string, int> mp;
 
int main()
{
    fastio();
 
    int n, m;
    cin >> n >> m;
 
    for (int i = 0; i < n; i++)
        cin >> str[i];
    
    int start = 0, end = n - 1;
    int mid = 0;
 
    bool trace;
    while(start <= end)
    {
        mid = (start + end) / 2;
        bool chk = true;
        for (int j = 0; j < m; j++)
        {
            string tmp = "";
            for (int i = mid; i < n; i++)
                tmp += str[i][j];
            
            if (mp[tmp])
            {
                chk = false;
                break;
            }
            
            mp[tmp]++;
        }
 
        if (!chk)
            end = mid - 1;
        else
            start = mid + 1;
        
        trace = chk;
        mp.clear();
    }
    
    if (!trace)
        cout << mid - 1 << endl;
    else
        cout << mid << endl;
    return 0;
}