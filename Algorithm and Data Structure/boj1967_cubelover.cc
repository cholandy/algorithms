#include<cstdio>
#include<vector>

std::vector<std::pair<int,int> > g[11111];
int v[11111];

void dfs(int x,int y,int z)
{
    int i;
    v[x]=z;
    for(i=0;i<g[x].size();i++)if(g[x][i].first!=y)dfs(g[x][i].first,x,z+g[x][i].second);
}

int main()
{
    int i,j,k,l,n;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&j,&k,&l);
        g[j].push_back(std::make_pair(k,l));
        g[k].push_back(std::make_pair(j,l));
    }
    dfs(1,0,0);
    j=1;
    for(i=1;i<=n;i++)if(v[i]>v[j])j=i;
    dfs(j,0,0);
    j=0;
    for(i=1;i<=n;i++)j=std::max(j,v[i]);
    printf("%d\n",j);
}
