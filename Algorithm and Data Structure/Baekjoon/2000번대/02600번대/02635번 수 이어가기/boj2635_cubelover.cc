#include<cstdio>
#include<cmath>

const double x = (1+sqrt(5))/2;

int cnt(int x,int y)
{
    return y<0?1:cnt(y,x-y)+1;
}

int main()
{
	int mx=-1,mxi;
    int i,j,n,m;
    scanf("%d",&n);
	m=n/x+.5;
    for(i=m-2;i<=m+2;i++)
	{
		j=cnt(n,i);
		if(j>mx)
		{
			mx=j;
			mxi=i;
		}
	}
    printf("%d\n",mx);
    i=n;j=mxi;
    while(i>=0)
	{
		printf("%d ",i);
        j=i-j;
        i-=j;
	}
}
