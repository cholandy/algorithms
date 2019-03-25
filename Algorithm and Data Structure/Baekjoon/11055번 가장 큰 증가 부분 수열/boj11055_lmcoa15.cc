#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int N;
    cin>>N;
 
    vector<int> arr(N,0);
    vector<int> dp(N,0);
    for(int i=0;i<N;i++)
        scanf("%d",&arr[i]);
    
    int ans=0;
    for(int i=0;i<N;i++){
        dp[i]=arr[i];
        
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
        }
        ans=max(ans,dp[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}
 
