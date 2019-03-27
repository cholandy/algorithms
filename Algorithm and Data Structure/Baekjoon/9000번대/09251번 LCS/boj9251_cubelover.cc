#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str1[1005],str2[1005];
int dp[1005][1005];

int f(int p1, int p2){
    if(!str2[p2] || !str1[p1]) return 0;
    if(~dp[p1][p2]) return dp[p1][p2];
    int r = max(f(p1,p2+1),f(p1+1,p2));
    r = max(r,f(p1+1,p2+1) + (str1[p1] == str2[p2]));
    return dp[p1][p2]=r;
}

int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%s %s",str1,str2);
    printf("%d",f(0,0));
}