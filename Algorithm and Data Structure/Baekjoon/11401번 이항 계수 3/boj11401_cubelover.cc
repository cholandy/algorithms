#include<cstdio>

const int p = 1000000007;

int d[4000004];

int main()
{
    int i,n,m,r=1;
    scanf("%d%d",&n,&m);
    if(m>n-m)m=n-m;
    d[1]=1;
    for(i=0;i<m;i++)
    {
        r=(long long)r*(n-i)%p;
        if(i)
        {
            d[i+1]=(p-(long long)p/-~i*d[p%-~i]%p)%p;
            r=(long long)r*d[i+1]%p;
        }
    }
    printf("%d",r);
    return 0;
}
