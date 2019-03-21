#include<cstdio>
#include<cstring>
#include<algorithm>

char s[11];

int main()
{
    int i,n,r=0;
    scanf("%s",s);
    n=strlen(s);
    std::sort(s,s+n);
    do
    {
        for(i=1;i<n;i++)if(s[i]==s[i-1])break;
        if(i==n)r++;
    }while(std::next_permutation(s,s+n));
    printf("%d",r);
}
