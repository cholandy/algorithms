#include<cstdio>
#include<algorithm>

int d[1111][22][22];

int main()
{
    int i,j,k,a,b;
    for(i=0;i<1111;i++)for(j=0;j<33;j++)for(k=0;k<33;k++)d[i][j][k]=-1e9;
    d[0][0][0]=0;
    for(i=0;~scanf("%d%d",&a,&b);i++)
    {
    	for(j=0;j<=i&&j<=15;j++)for(k=0;k<=i&&k<=15;k++)
		{
			d[i+1][j][k]=std::max(d[i+1][j][k],d[i][j][k]);
			d[i+1][j+1][k]=std::max(d[i+1][j+1][k],d[i][j][k]+a);
			d[i+1][j][k+1]=std::max(d[i+1][j][k+1],d[i][j][k]+b);
		}
    }
    printf("%d",d[i][15][15]);
}
