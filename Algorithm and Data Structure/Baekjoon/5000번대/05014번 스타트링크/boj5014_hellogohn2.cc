#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
int main(){
    int F,S,G,U,D; cin>>F>>S>>G>>U>>D;
    
    bool *visited = (bool*)malloc(sizeof(bool)*(F+1));
    visited[S]=1;
    queue<pair<int,int>> q; q.push(make_pair(S,0));
    
    int ans=-1,stair=0,cnt=0;
    while(!q.empty()){
        stair=q.front().first; cnt=q.front().second; q.pop();
        if(stair==G){
            ans=cnt;
            break;
        }
        if(stair+U<=F && !visited[stair+U]){
            q.push(make_pair(stair+U,cnt+1));
            visited[stair+U]=1;
        }
        if(stair-D>0 && !visited[stair-D]){
            q.push(make_pair(stair-D,cnt+1));
            visited[stair-D]=1;
        }
    }
    free(visited);
    if(ans!=-1) cout<<ans<<endl;
    else    cout<<"use the stairs"<<endl;
    return 0;
} 