#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
 
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
 
    int m = gcd(x, y);
 
    int ans = x + y - m;
 
    cout << ans;
    return 0;
}
 
