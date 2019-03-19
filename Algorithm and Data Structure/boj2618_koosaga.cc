#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,i,x[1005],y[1005],dp[1005][1005];
int dist(int p,int q){return abs(x[q]-x[p])+abs(y[q]-y[p]);}

int f(int n,int m){
    if(n==i+1 || m==i+1) return 0;
    if(dp[n][m]) return dp[n][m];
    int next=max(n,m)+1;
    return dp[n][m]=min(f(next,m)+dist(n,next),f(n,next)+dist(m,next));
}

int main(){
    scanf("%d %d",&n,&i);
    x[0]=y[0]=1,x[1]=y[1]=n;
    for (int j=1; j<=i; j++) {
        scanf("%d %d",&x[j+1],&y[j+1]);
    }
    printf("%d\n",f(1,0));
    int next,n=1,m=0;
    for (int j=1; j<=i; j++) {
        next=max(n,m)+1;
        if(dp[next][m]+dist(n,next)<dp[n][next]+dist(m,next)){
            n=next;
            puts("2");
        }
        else m=next,puts("1");
    }
}