#include<cstdio>

int d[11111][11];

int main()
{
	int u,v,w,x,y,z;
    int i,j,k,n,t,r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%d%d%d%d%d%d",&u,&v,&w,&x,&y,&z);
        d[i][u]=z;
        d[i][v]=x;
        d[i][w]=y;
        d[i][x]=v;
        d[i][y]=w;
        d[i][z]=u;
	}
    for(j=1;j<=6;j++)
	{
		t=0;
		k=j;
		for(i=0;i<n;i++)
		{
            if(k<6&&d[i][k]<6)t+=6;
            else if(k<5||d[i][k]<5)t+=5;
            else t+=4;
            k=d[i][k];
		}
        if(t>r)r=t;
	}
	printf("%d",r);
}
