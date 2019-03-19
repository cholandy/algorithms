#include<cstdio>
#include<cstring>
#include<algorithm>
 
const int mod1 = 1000000007, mod2 = 1000000009;
 
char a[2222],b[2222];
 
std::pair<int,int> d[2222222];
int dn;
 
std::pair<int,int> p[33];
 
int isprime(int x)
{
    int i;
    for(i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}
 
int main()
{
    std::pair<int,int> P;
    int i,j,n,m,r=0;
    scanf("%s%s",a,b);
    n=strlen(a);m=strlen(b);
    p[0].first=p[0].second=1;
    for(i=1;i<26;i++)
    {
        p[i].first=2003LL*p[i-1].first%mod1;
        p[i].second=2003LL*p[i-1].second%mod2;
    }
    for(i=0;i<n;i++)
    {
        P.first=P.second=0;
        for(j=i;j<n;j++)
        {
            P.first=(P.first+p[a[j]-97].first)%mod1;
            P.second=(P.second+p[a[j]-97].second)%mod2;
            d[dn++]=P;
        }
    }
    std::sort(d,d+dn);
    for(i=0;i<m;i++)
    {
        P.first=P.second=0;
        for(j=i;j<m;j++)
        {
            P.first=(P.first+p[b[j]-97].first)%mod1;
            P.second=(P.second+p[b[j]-97].second)%mod2;
            if(std::binary_search(d,d+dn,P))r=std::max(r,j-i+1);
        }
    }
    printf("%d\n",r);
}