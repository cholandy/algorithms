#include<cstdio>

char a[66][66];
int d[66][66];

void print(int sx,int sy,int ex,int ey)
{
    int t=d[ex][ey]-d[sx][ey]-d[ex][sy]+d[sx][sy];
    if(t==0)
    {
        putchar(48);
        return;
    }
    if(t==(ex-sx)*(ey-sy))
    {
        putchar(49);
        return;
    }
    putchar('(');
    print(sx,sy,(sx+ex)>>1,(sy+ey)>>1);
    print(sx,(sy+ey)>>1,(sx+ex)>>1,ey);
    print((sx+ex)>>1,sy,ex,(sy+ey)>>1);
    print((sx+ex)>>1,(sy+ey)>>1,ex,ey);
    putchar(')');
}

int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",a[i]+1);
        for(j=1;j<=n;j++)d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+a[i][j]-48;
    }
    print(0,0,n,n);
}
