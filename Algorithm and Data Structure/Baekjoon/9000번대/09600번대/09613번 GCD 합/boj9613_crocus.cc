#include <iostream>
#include <cstdio>
#include <vector>
 
using namespace std;
 
typedef long long ll;
 
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
 
int main()
{
    int tc;
    scanf("%d", &tc);
 
    while (tc--)
    {
        int n;
        scanf("%d", &n);
 
        vector<int> vc(n);
 
        for (int i = 0; i < n; i++)
            scanf("%d", &vc[i]);
 
        ll ans = 0;
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                ans += gcd(vc[i], vc[j]);
 
        printf("%lld\n", ans);
    }
 
    return 0;
}