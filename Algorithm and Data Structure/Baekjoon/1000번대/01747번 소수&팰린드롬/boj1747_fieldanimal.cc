#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int p[2000001];
vector<int> v;
void sieve();
int isPal(int);
int main()
{
    sieve();
    for (int i = 2; i <= 2000000; ++i)
        if (!p[i] && isPal(i))
            v.push_back(i);
    int N;
    scanf("%d", &N);
    printf("%d", *lower_bound(v.begin(), v.end(), N));
}
int isPal(int n)
{
    string s = to_string(n);
    int i = 0;
    int j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return 0;
        ++i;
        --j;
    }
    return 1;
 
}
void sieve()
{
    int s = sqrt(2000000);
    for (int i = 2; i <= s; ++i)
    {    
        if(!p[i])
        for (int j = i * 2; j <= 2000000; j += i)
        {
            p[j] = 1;
        }
    }
}
