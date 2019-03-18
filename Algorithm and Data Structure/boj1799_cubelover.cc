#include<cstdio>
#include<vector>

bool matched[40];
bool graph[40][40];
bool map[10][10];
bool vis[40];
int graphn;
int q[40],qn;
int vi[40];

int main()
{
	int x,y,ans;
	int i,j,k,n,m;
	scanf("%d",&n);
	graphn=n*4;
	for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&map[i][j]);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(map[i][j])
				graph[i+j][n*3+i-j]=true;
		}
	}
	
	for(ans=0;;ans++)
	{
		for(i=0;i<n+n;i++)
		{
			if(!matched[i])
			{
				for(j=0;j<graphn;j++)vis[j]=false;
				qn=0;
				vi[i]=-1;
				vis[i]=true;
				q[qn++]=i;
				for(j=0;j<qn;j++)
				{
					if(q[j]>n+n&&!matched[q[j]])break;
					for(k=0;k<graphn;k++)
					{
						if(graph[q[j]][k]&&!vis[k])
						{
							vi[k]=q[j];
							vis[k]=true;
							q[qn++]=k;
						}
					}
				}
				if(j<qn)
				{
					j=q[j];
					matched[j]=true;
					matched[i]=true;
					while(vi[j]>=0)
					{
						graph[vi[j]][j]=false;
						graph[j][vi[j]]=true;
						j=vi[j];
					}
					break;
				}
			}
		}
		if(i==n+n)break;
	}
	printf("%d",ans);
}