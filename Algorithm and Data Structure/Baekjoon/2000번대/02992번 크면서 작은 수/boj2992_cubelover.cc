#include<cstdio>
#include<algorithm>

char s[11];

int main()
{
	int i,n;
	scanf("%s",s);
	for(n=0;s[n];n++);
    if(std::next_permutation(s,s+n))puts(s);
    else puts("0");
}
