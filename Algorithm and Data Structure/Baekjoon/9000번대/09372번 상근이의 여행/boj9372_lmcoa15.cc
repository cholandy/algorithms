#include <iostream>
#include <vector>
using namespace std;
 
struct str{
    int u,v,w;
    str(int u,int v):u(u),v(v){};
};
 
vector<int> parent;
 
int find(int p){
    if(parent[p]!=p){
        p=find(parent[p]);
    }
    
    return p;
}
int main(){
    
    int T;
    cin>>T;
    
    int N,M;
    int u,v;
    for(int testCase=0;testCase<T;testCase++){
        scanf("%d %d",&N,&M);
        
        vector<str> vec;
        parent=vector<int> (N+1,0);
        int ans=0;
        
        for(int i=0;i<M;i++){
            scanf("%d %d",&u,&v);
            vec.push_back(str(u,v));
        }
        
        for(int i=1;i<=N;i++)
            parent[i]=i;
        
        for(int i=0;i<vec.size();i++){
            int p1=find(vec[i].u);
            int p2=find(vec[i].v);
            
            if(p1!=p2){
                parent[p1]=p2;
                ans++;
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
 