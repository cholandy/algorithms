#include <stdio.h>

bool ispos(int n)
{
	int c=0;

	while(n>0)
	{
		if(n%10==6)
			c++;
		else
			c=0;
		if(c==3)
			return true;
		n/=10;
	}

	return false;
}

int main()
{
	int n, c=0;
	int cur=666;

	scanf("%d",&n);

	while(1)
	{
		if(ispos(cur++))
			c++;
		if(c==n)
		{
			printf("%d",cur-1);
			return 0;
		}
	}
}