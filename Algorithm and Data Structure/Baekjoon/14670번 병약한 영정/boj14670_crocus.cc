#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
 
using namespace std;
 
map<int, int> mp;
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        mp[a] = b;
    }
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int a;
        bool chk = true;
        vector<int> vc;
        scanf("%d", &a);
 
        for (int j = 0; j < a; j++)
        {
            int b;
            scanf("%d", &b);
 
            if (mp.count(b) != 0)
                vc.push_back(mp[b]);
 
            else
                chk = false;
        }
 
        if(chk)
            for (auto i : vc)
                printf("%d ", i);
        else
            printf("YOU DIED");
 
        printf("\n");
    }
    return 0;
}
