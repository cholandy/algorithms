#include<cstdio>
#include<cmath>

int g[22][22][22][22];
int t[33][33];

void f(int a,int b,int c,int d,int x,int y,int z)
{
	if(t[x][y])return;
	if(z==0)
	{
        g[a][b][c][d]++;
        return;
	}
	t[x][y]=1;
	f(a+1,b,c,d,x+1,y,z-1);
	f(a,b+1,c,d,x-1,y,z-1);
	f(a,b,c+1,d,x,y+1,z-1);
	f(a,b,c,d+1,x,y-1,z-1);
	t[x][y]=0;
}

int main()
{
	double res=0;
	int i,j,k;
	int n,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	f(0,0,0,0,16,16,n);
    for(i=0;i<=n;i++)for(j=i;j<=n;j++)for(k=j;k<=n;k++)res+=g[i][j-i][k-j][n-k]*pow(a/100.,i)*pow(b/100.,j-i)*pow(c/100.,k-j)*pow(d/100.,n-k);
    printf("%.12lf\n",res);
}
