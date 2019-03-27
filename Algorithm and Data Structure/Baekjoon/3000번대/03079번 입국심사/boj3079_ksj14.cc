#include <cstdio>
#include <algorithm>
using namespace std;
 
int n, m;
int time[100001];
 
bool cmp(const int &first, const int &second)    {
    return first > second;
}
 
int ispossible(long long t)
{
    int num = m;
    int i = 0;
 
    while (i < n && num > 0) {
        num = num - t / time[i];
        i++;
    }
    if (i >= n && num > 0)    return 0;
    return 1;
}
 
long long bsearch()
{
    long long s = 0, e = 1e9 * n;
    long long m;
 
    while (s <= e) {
        m = (s + e) / 2;
 
        if (!ispossible(m)) s = m + 1;
        else                e = m - 1;
    }
 
    return e + 1;
}
 
int main()
{
    scanf("%d %d", &n, &m);
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &time[i]);
    }
 
    sort(time, time + n, cmp);
 
    printf("%lld\n", bsearch());
 
    return 0;
}

