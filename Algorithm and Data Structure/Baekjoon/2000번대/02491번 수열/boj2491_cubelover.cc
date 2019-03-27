#include<cstdio>

int a[100000];

int main()
{
	int i,t,n,x;
	int max=0;

	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);

	t=a[0];
	x=1;
	for(i=1;i<n;i++)
	{
		if(t<=a[i])x++;
		else x=1;
		t=a[i];
		if(x>max)max=x;
	}

	t=a[0];
	x=1;
	for(i=1;i<n;i++)
	{
		if(t>=a[i])x++;
		else x=1;
		t=a[i];
		if(x>max)max=x;
	}

	if(x>max)max=x;
	printf("%d",max);
}
