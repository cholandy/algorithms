#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int tc;
    scanf("%d", &tc);
    
    while (tc--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
 
        int a1 = a*a;
        int b1 = b*b;
 
        int ans = a1 / b1;
        if (a1 % b1)
            ans++;
 
        cout << ans << endl;
    }
    return 0;
}
 