#include<cstdio>
#include<algorithm>

using namespace std;
pair<int,int> a[333333];
int r[111111];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i].first);
    for(i=0;i<m;i++)
	{
        scanf("%d%d",&a[i+n].first,&a[i+n+m].first);
        a[i+n].second=-i-1;
        a[i+n+m].second=i+1;
	}
    sort(a,a+n+m+m);
    j=0;
    for(i=0;i<n+m+m;i++)
	{
		if(a[i].second<0)r[-a[i].second-1]-=j;
		else if(a[i].second>0)r[a[i].second-1]+=j;
		else j++;
	}
    for(i=0;i<m;i++)printf("%d\n",r[i]);
}
