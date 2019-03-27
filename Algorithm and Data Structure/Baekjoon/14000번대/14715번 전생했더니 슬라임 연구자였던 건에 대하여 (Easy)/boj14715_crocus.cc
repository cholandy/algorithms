#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>
 
#define fastio() ios::sync_with_stdio(0),cin.tie(0);
 
using namespace std;
 
typedef pair<int, int> pii;
 
int func(int now)
{
    int cnt = 0;
    int tmp = now;
 
    for (int i = 2; i < now; i++)
        if (now % i == 0)
            while (tmp % i == 0)
                cnt++, tmp /= i;
 
    if (cnt == 0)
        return 1;
 
    return cnt;
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    cout << ceil(log2(func(n)));
 
    return 0;
}