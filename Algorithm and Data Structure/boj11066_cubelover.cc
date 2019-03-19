#include<cstdio>

int a[512];
int d[512][512];
short v[512][512];

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
	{
        int i,j,k,n;
        scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]+=a[i-1];
			v[1][i]=i;
		}
		for(i=2;i<=n;i++)for(j=i;j<=n;j++)
		{
            int td=1e9,tv;
			for(k=v[i-1][j-1];k<=v[i-1][j];k++)if(d[k-j+i][k]+d[j-k][j]<td)
			{
				td=d[k-j+i][k]+d[j-k][j];
                tv=k;
			}
            d[i][j]=td+a[j]-a[j-i];
            v[i][j]=tv;
		}
		printf("%d\n",d[n][n]);
	}
}
