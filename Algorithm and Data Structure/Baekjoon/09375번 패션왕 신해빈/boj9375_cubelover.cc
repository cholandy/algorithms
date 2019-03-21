#include<cstdio>
#include<algorithm>

struct thing
{
	char a[100];
	char b[100];
} d[100];

inline bool operator <(const thing &a,const thing &b)
{
	int i;
	for(i=0;a.b[i]||b.b[i];i++)if(a.b[i]!=b.b[i])return a.b[i]<b.b[i];
	for(i=0;a.a[i]||b.a[i];i++)if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
	return false;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int i,j,k,n,r=1;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%s%s",d[i].a,d[i].b);
		std::sort(d,d+n);
		k=2;
		for(i=1;i<n;i++)
		{
			for(j=0;d[i-1].b[j]||d[i].b[j];j++)if(d[i-1].b[j]!=d[i].b[j])break;
			if(d[i-1].b[j]||d[i].b[j])
			{
				r*=k;
				k=2;
			}
			else k++;
		}
		printf("%d\n",n?r*k-1:0);
	}
}