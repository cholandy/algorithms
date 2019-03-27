#include<cstdio>

char d[202][26];
char v[202];

char dfs(int x)
{
	if(v[x])return 0;
	if(d[x][25]&2)
	{
        d[x][25]=0;
        return 1;
	}
    int i;
    v[x]=1;
    if(x<100)
	{
		for(i=100;i<200;i++)if((d[x][i>>3]>>(i&7)&1)&&dfs(i))
		{
			d[x][i>>3]&=~(1<<(i&7));
			d[i][x>>3]|=1<<(x&7);
			return 1;
		}
		return 0;
	}
	for(i=0;i<100;i++)if((d[x][i>>3]>>(i&7)&1)&&dfs(i))
	{
		d[x][i>>3]&=~(1<<(i&7));
		d[i][x>>3]|=1<<(x&7);
		return 1;
	}
	return 0;
}

int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
	{
		d[200][i>>3]|=1<<(i&7);
		d[i+100][25]|=2;
	}
    while(m--)
	{
		scanf("%d%d",&i,&j);
        d[i-1][(j+99)>>3]|=1<<((j+99)&7);
	}
    for(i=0;dfs(200);i++)for(j=0;j<202;j++)v[j]=0;
    printf("%d",i);
}
