#include<cstdio>

int d[1111];

int main()
{
    int i,j,t,n;
    scanf("%d",&n);
    d[1]=1;
    for(i=1;i<n;i++)
	{
		scanf("%d",&t);
        if(d[i])for(j=1;j<=t;j++)if(!d[i+j]||d[i]<d[i+j])d[i+j]=d[i]+1;
	}
	printf("%d",d[n]-1);
}
