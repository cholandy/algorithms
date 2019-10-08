#include<cstdio>

int t[33];
char s[111];

int main()
{
    int i;
    scanf("%s",s);
    for(i=0;s[i];i++)t[s[i]-97]++;
    for(i=0;i<26;i++)printf("%d ",t[i]);
}