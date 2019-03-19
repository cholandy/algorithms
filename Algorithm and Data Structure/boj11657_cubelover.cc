#include<cstdio>

int d[555];
int s[6666];
int e[6666];
int x[6666];

int main()
{
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)scanf("%d%d%d",s+i,e+i,x+i);
    for(i=2;i<=n;i++)d[i]=2e9;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)if(d[s[j]]<1e9&&d[e[j]]>d[s[j]]+x[j])d[e[j]]=d[s[j]]+x[j];
    for(j=1;j<=m;j++)if(d[s[j]]<1e9&&d[e[j]]>d[s[j]]+x[j])
	{
		puts("-1");
		return 0;
	}
    for(i=2;i<=n;i++)printf("%d\n",d[i]<1e9?d[i]:-1);
}
