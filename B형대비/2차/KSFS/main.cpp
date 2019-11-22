#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
extern void init();
extern int mkdir(char name[]);
extern int cd(char path[]);
extern int rm(char path[]);
extern int ls(char path[]);
int t,s,n,type[40210],mx[10]={0,20000,10000,10000,200},(*cmd[10])(char[])={NULL,mkdir,cd,rm,ls};
int _strlen(const char *str)
{
	int ret=0;
	while(str[ret])ret++;
	return ret;
}
int _strcmp(const char *str1,const char *str2)
{
	int pos=0;
	while(str1[pos]&&str2[pos]&&str1[pos]==str2[pos])pos++;
	if(!str1[pos]&&!str2[pos])return 0;
	if(!str1[pos])return -1;
	if(!str2[pos])return 1;
	return str1[pos]-str2[pos];
}
void _strcpy(char *dst,const char *src)
{
	int pos=0;
	while(src[pos])
	{
		dst[pos]=src[pos];
		pos++;
	}
	dst[pos]=0;
}
void _strcat(char *dst,const char *src)
{
	_strcpy(dst+_strlen(dst),src);
}
template<typename T> void _swap(T &a,T &b)
{
	T tmp=a;
	a=b;
	b=tmp;
}
int main()
{
	int i,j,k,x,l;
	char arg[20];
	scanf("%d",&t);
	for(i=1;i<=t;++i)
	{
		x=0;
		for(j=1;j<=4;++j)for(k=1;k<=mx[j];++k)type[++x]=j;
		for(j=1;j<=40200;++j)_swap(type[j],type[rand()%40200+1]);
		init();
		scanf("%d%d",&s,&n);
		srand(s);
		printf("#%d\n",i);
		for(j=1;j<=n;++j)
		{
			if(s==0)
			{
				scanf("%d%s",&x,arg);
				if(arg[0]=='0')arg[0]=0;
			}
			else
			{
				x=type[j];
				l=rand()%2;
				if(x==1&&l==0)l=1;
				for(k=0;k<l;++k)arg[k]=rand()%26+'a';
				arg[k]=0;
				if(x==2)
				{
					if(rand()%1000==0)_strcpy(arg,"/");
					if(rand()%10==0)_strcpy(arg,"..");
				}
			}
			if(x==2&&_strcmp(arg,"/")&&_strcmp(arg,".."))_strcat(arg,"\t");
			if(x==3||x==4)_strcat(arg,"*");
			printf("%d\n",(*cmd[x])(arg));
		}
	}
	return 0;
}