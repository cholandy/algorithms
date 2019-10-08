#include<cstdio>
#include<algorithm>

char a[1111];
char b[1111];

int d[1111][1111];

void print(int x,int y)
{
    if(x&&y)
	{
        if(a[x]==b[y])
		{
            print(x-1,y-1);
            putchar(a[x]);
		}
		else if(d[x-1][y]>d[x][y-1])print(x-1,y);
		else print(x,y-1);
	}
}

int main()
{
    int i,j;
    scanf("%s%s",a+1,b+1);
    for(i=1;a[i];i++)for(j=1;b[j];j++)
	{
        d[i][j]=std::max(d[i-1][j],d[i][j-1]);
        if(a[i]==b[j])d[i][j]=d[i-1][j-1]+1;
	}
	printf("%d\n",d[i-1][j-1]);
    print(i-1,j-1);
}
