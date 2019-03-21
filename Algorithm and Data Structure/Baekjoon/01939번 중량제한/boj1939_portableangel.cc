#include <stdio.h>
#include <map>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

map<int, int> e[100001];

int main()
{
	int n, m;

	scanf("%d %d",&n,&m);

	int a, b, c;

	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		if(e[a].count(b)==0 || e[a][b]<c)
			e[a][b]=e[b][a]=c;
	}

	int S, E;

	scanf("%d %d",&S,&E);

	queue<int> q;
	int d[100001]={0};
	d[S]=1000000001;

	q.push(S);

	while(!q.empty())
	{
		for(auto i: e[q.front()])
		{
			if(d[i.first]==0 || d[i.first]<min(i.second,d[q.front()]))
			{
				d[i.first]=min(i.second,d[q.front()]);
				q.push(i.first);
			}
		}
		q.pop();
	}

	printf("%d",d[E]);

	return 0;
}