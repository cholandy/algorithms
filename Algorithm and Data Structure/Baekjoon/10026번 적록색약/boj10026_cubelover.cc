#include<cstdio>

char s[111][111];
int v[111][111];
int n;

void dfs(int x,int y,char z)
{
    if(x<0||x>=n||y<0||y>=n||s[x][y]!=z||v[x][y])return;
    v[x][y]=1;
    dfs(x+1,y,z);
    dfs(x-1,y,z);
    dfs(x,y+1,z);
    dfs(x,y-1,z);
}

int main()
{
    int i,j,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%s",s[i]);
    t=0;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(!v[i][j])
    {
        t++;
        dfs(i,j,s[i][j]);
    }
    printf("%d ",t);
    for(i=0;i<n;i++)for(j=0;j<n;j++)
    {
        v[i][j]=0;
        if(s[i][j]=='G')s[i][j]='R';
    }
    t=0;
    for(i=0;i<n;i++)for(j=0;j<n;j++)if(!v[i][j])
    {
        t++;
        dfs(i,j,s[i][j]);
    }
    printf("%d\n",t);
}
