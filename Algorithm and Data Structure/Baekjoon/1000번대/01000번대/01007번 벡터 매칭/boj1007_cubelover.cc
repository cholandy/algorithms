#include<cstdio>
#include<cmath>
#include<algorithm>

int x[22],y[22];

long long f(int n,int m,int sx,int sy)
{
	if(m<-n||m>n)return 1e18;
    if(!n)return 1LL*sx*sx+1LL*sy*sy;
    return std::min(f(n-1,m-1,sx-x[n-1],sy-y[n-1]),f(n-1,m+1,sx+x[n-1],sy+y[n-1]));
}

int main()
{
	int tcn;
	scanf("%d",&tcn);
	while(tcn--)
	{
		int i,n;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
        printf("%f\n",sqrt(f(n,0,0,0)));
	}
}
