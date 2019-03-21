#include<cstdio>

int a[1000];
int d[1000];

int main()
{
	int i,j,n,m,t,max=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		scanf("%d",&t);
		for(j=0;a[j]>t;j++);
		d[j]++;
	}
	for(i=1;i<n;i++)if(d[i]>d[max])max=i;
	printf("%d",max+1);
}