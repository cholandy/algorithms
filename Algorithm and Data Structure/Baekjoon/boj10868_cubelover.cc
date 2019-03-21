#include<cstdio>
#include<algorithm>

const int off = 131072;

int min[333333];

int main()
{
	int tmin;
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)scanf("%d",&min[i+off]);
    for(i=off-1;i>0;i--)min[i]=std::min(min[i<<1],min[i<<1|1]);
	while(m--)
	{
        scanf("%d%d",&i,&j);
        tmin=1e9;
        i+=off;
        j+=off;
        while(i<=j)
		{
            tmin=std::min(tmin,min[i]);
            tmin=std::min(tmin,min[j]);
            i=(i+1)>>1;
            j=(j-1)>>1;
		}
		printf("%d\n",tmin);
	}
}
