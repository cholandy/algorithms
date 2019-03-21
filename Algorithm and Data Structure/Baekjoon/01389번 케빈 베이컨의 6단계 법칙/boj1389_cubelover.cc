#include<cstdio>
#include<algorithm>

int d[111][111];

int main()
{
	int mx,mxi;
	int i,j,k,n,m,t;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(i!=j)d[i][j]=1e9;
	while(m--)
	{
		scanf("%d%d",&i,&j);
		d[i][j]=d[j][i]=1;
	}
	for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(d[i][j]>d[i][k]+d[k][j])d[i][j]=d[i][k]+d[k][j];
	mx=1e9;
    for(i=1;i<=n;i++)
	{
		t=0;
		for(j=1;j<=n;j++)t+=d[i][j];
		if(t<mx)
		{
			mx=t;
			mxi=i;
		}
	}
	printf("%d",mxi);
}
