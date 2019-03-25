#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    
    int n;
    cin>>n;
    
    vector<int> A(n,0);
    vector<int> dp(n,0);
    
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    
    int ans=0;
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[i]>A[j] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}