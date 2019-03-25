#include <iostream>
#include <cstdio>
 
using namespace std;
 
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
 
    int n;
    cin >> n;
 
    int ans = 0;
    while (1)
    {
        if (a % 10 == n || a / 10 == n || b % 10 == n || b / 10 == n )
            ans++;
        if (a == c && b == d)
            break;
 
        b++;
        if (b == 60)
        {
            b = 0;
            a++;
        }
    }
 
    cout << ans << endl;
 
    return 0;

}