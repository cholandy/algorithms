#include<cstdio>
#include<algorithm>

long long a[55];
long long f(long long x,long long y) {
    return x ? f(y%x,x) : y;
}

int main()
{
    long long r=1;
    int i,j,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        r*=a[i]/f(r,a[i]);
    }
    std::sort(a,a+n);
    if(r==a[n-1])r*=a[0];
    printf("%lld",r);
}