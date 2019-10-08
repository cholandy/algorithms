#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
 
using namespace std;
 
int main()
{
    while (1)
    {
        int n;
        scanf("%d", &n);
 
        if (!n)
            break;
 
        map<double, vector<string>> mp;
 
        for (int i = 0; i < n; i++)
        {        
            string name;
            double height;
            cin >> name >> height;
 
            mp[height].push_back(name);
        }
        auto it = mp.end();
        it--;
 
        for (auto i : it->second)
            cout << i << endl;
    }
    return 0;
}
