#include<cstdio>

int a[111];

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%d",&m);
    while(m--)
	{
		scanf("%d%d",&i,&j);
		if(i==1)for(i=j;i<=n;i+=j)a[i]^=1;
		else
		{
			a[j]^=1;
			for(i=1;j-i>=1&&j+i<=n&&a[j-i]==a[j+i];i++)
			{
				a[j-i]^=1;
				a[j+i]^=1;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
		if(i%20==0)puts("");
	}
}
