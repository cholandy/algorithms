#include<cstdio>
#include<algorithm>

#define SIVAL 0

std::pair<int,int> a[444444];

int main()
{
    int i,n,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
        if (x == y) {
            a[i].first = x;
            a[i].second = SIVAL;
            a[i+n].first = y;
            a[i+n].second = SIVAL;
        }
        else {
            a[i].first=x;
            a[i].second=1;
            a[i+n].first=y;
            a[i+n].second=-1;
        }
	}
	std::sort(a,a+n+n);
	x=0;
	y=1;
	for(i=0;i<n+n;i++)
	{
        if (a[i].second == SIVAL) {
            y=std::max(y,x+1);
        }
        else {
		    x+=a[i].second;
            y=std::max(y,x);
        }
	}
	printf("%d",y);
}
