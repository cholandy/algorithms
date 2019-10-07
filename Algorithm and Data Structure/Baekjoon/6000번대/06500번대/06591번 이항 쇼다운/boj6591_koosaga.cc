#include <cstdio>
int dp[5000][5000];

int f(int a, int b){
    if(a==b || b==0) return 1;
    if(a-1==b || b==1) return a;
    if(a<5000 && b<5000){
        if(dp[a][b]) return dp[a][b];
        else return dp[a][b]=f(a-1,b)+f(a-1,b-1);
    }
    return f(a-1,b)+f(a-1,b-1);
}
int main(){
    int n,m;
    while (1) {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0) return 0;
        printf("%d\n",f(n,m));
    }
}