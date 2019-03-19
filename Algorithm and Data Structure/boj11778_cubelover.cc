#include<cstdio>

const int m = 1000000007;

int f(long long n)
{
    int i,a,b,c,d;
    a=0;b=1;
    for(i=60;i>=0;i--)
	{
        c=(2LL*a*b-1LL*a*a%m+m)%m;
		d=(1LL*a*a+1LL*b*b)%m;
		a=c;
		b=d;
		if(n>>i&1)
		{
			b+=a;
			a=b-a;
			if(b>=m)b-=m;
		}
	}
	return a;
}

long long g(long long a,long long b){return a?g(b%a,a):b;}

int main()
{
	long long a,b;
	scanf("%lld%lld",&a,&b);
    printf("%d",f(g(a,b)));
}
