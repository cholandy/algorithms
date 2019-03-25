#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int n,ans=0;
    cin>>n;
    
    vector<int> vec(n,0);
    for(int i=0;i<n;i++)
        scanf("%d",&vec[i]);
    
    sort(vec.begin(),vec.end());
    for(int i=0;i<n;i++)
        ans+=vec[i]*(n-i);
    
    cout<<ans<<endl;
 
    return 0;
}
