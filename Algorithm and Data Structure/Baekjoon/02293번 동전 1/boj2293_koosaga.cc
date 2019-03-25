#include <cstdio>  
int n,m;  
long long dp[10004];  
int main(){  
    scanf("%d",&n);scanf("%d",&m);  
    dp[0] = 1;
    for(int i=0; i<n; i++){
        int x; scanf("%d",&x);
        for(int j=m; j>=0; j--){
            for(int k=1; k*x<=j; k++) dp[j] += dp[j-k*x];
        }
    }
    printf("%lld",dp[m]);  
}  