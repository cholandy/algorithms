#include<cstdio>
 
int a[1000][1000],an;
 
void gen(int l,int r,int u,int d)
{
    if(l<r&&u<d)
    {
        int i,j;
        for(i=l;i<r;i++)if(!a[i][u])a[i][u]=++an;
        for(j=u;j<d;j++)if(!a[r-1][j])a[r-1][j]=++an;
        for(i=r-1;i>=l;i--)if(!a[i][d-1])a[i][d-1]=++an;
        for(j=d-1;j>=u;j--)if(!a[l][j])a[l][j]=++an;
        gen(l+1,r-1,u+1,d-1);
    }
}
 
int main()
{
    int i,j,n,m,k;
    scanf("%d%d%d",&m,&n,&k);
    gen(0,n,0,m);
    for(i=0;i<n;i++)for(j=0;j<m;j++)if(a[i][j]==k)
    {
        printf("%d %d",j+1,i+1);
        return 0;
    }
    puts("0");
}