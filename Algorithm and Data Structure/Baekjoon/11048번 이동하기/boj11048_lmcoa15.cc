#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int N,M;
    cin>>N>>M;
    
    vector<vector<int>> dp(N+1,vector<int>(M+1,0));
    for(int i=1;i<=N;i++)
        for(int j=1;j<=M;j++){
            scanf("%d",&dp[i][j]);
            dp[i][j]+=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
        }
    
    cout<<dp[N][M]<<endl;
    return 0;
}
