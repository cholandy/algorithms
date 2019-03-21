#include<cstdio>

unsigned int rnd(unsigned int mx)
{
	static unsigned int x = 987654321;
	return 1LL*mx*(x=1664525*x+1013904223)/4294967296LL;
}

int x[111111],y[111111];

int chk(int i,int j,int k)
{
	return 1LL*x[i]*y[j]+1LL*x[j]*y[k]+1LL*x[k]*y[i]==1LL*y[i]*x[j]+1LL*y[j]*x[k]+1LL*y[k]*x[i];
}

int main()
{
    int i,j,k,l,t,n,m;
    scanf("%d%d",&n,&m);
    if(n<2)
	{
		puts("possible");
		return 0;
	}
	for(i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
    for(i=0;i*m*m<25000;i++)
	{
		do
		{
			j=rnd(n);
			k=rnd(n);
		}while(j==k);
        t=0;
        for(l=0;l<n;l++)if(chk(j,k,l))t++;
        if(t*100>=n*m)
		{
			puts("possible");
			return 0;
		}
	}
	puts("impossible");
	return 0;
}
