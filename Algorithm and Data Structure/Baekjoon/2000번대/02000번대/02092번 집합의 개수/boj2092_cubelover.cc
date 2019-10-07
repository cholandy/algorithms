#include<cstdio>
#include<algorithm>

const int mod=1000000;

int a[222];
int d[2][4444];

int main()
{
	int i,j,k,n,m,l;
	scanf("%*d%d%d%d",&n,&m,&l);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		a[j]++;
	}
    d[0][0]=1;
    for(i=1;i<=200;i++)
	{
		k=0;
		for(j=0;j<=l;j++)
		{
			(k+=d[!(i&1)][j])%=mod;
			if(j>a[i])(k+=mod-d[!(i&1)][j-a[i]-1])%=mod;
            d[i&1][j]=k;
		}
	}
	k=0;
	for(j=m;j<=l;j++)(k+=d[0][j])%=mod;
    printf("%d",k);
}
