#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
typedef long long ll;
 
int main()
{
    ll n;
    cin >> n;
 
    ll start = 0;
    ll end = sqrt(n); 
    ll mid;
 
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (mid >= sqrt(n))
            end = mid - 1;
        
        else
            start = mid + 1;
    }
 
    if (mid * mid == n)
        cout << mid;
    else
        cout << mid + 1;
 
    return 0;
}
