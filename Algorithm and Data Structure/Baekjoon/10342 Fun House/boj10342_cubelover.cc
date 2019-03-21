#include<cstdio>

char s[22][22];

int main()
{
    int tc;
    for(tc=1;;tc++)
    {
        int x,y,px,py;
        int i,j,n,m;
        scanf("%d%d",&m,&n);
        if(!n&&!m)break;
        printf("HOUSE %d\n",tc);
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<m;j++)if(s[i][j]=='*')
            {
                x=i;
                y=j;
                if(i==0)px=1,py=0;
                if(i==n-1)px=-1,py=0;
                if(j==0)px=0,py=1;
                if(j==m-1)px=0,py=-1;
            }
        }
        while(x>=0&&x<n&&y>=0&&y<m)
        {
            if(s[x][y]=='/'||s[x][y]=='\\')px^=py^=px^=py;
            if(s[x][y]=='/')px=-px,py=-py;
            x+=px;
            y+=py;
        }
        if(x<0)s[0][y]='&';
        if(x>=n)s[n-1][y]='&';
        if(y<0)s[x][0]='&';
        if(y>=m)s[x][m-1]='&';
        for(i=0;i<n;i++)puts(s[i]);
    }
}
