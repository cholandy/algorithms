#include <iostream>
#include <queue>
using namespace std;
 
struct str{
    int start;
    int end;
    str(int start,int end):start(start),end(end){};
};
 
bool operator<(str s1,str s2){
    if(s1.end!=s2.end)
        return s1.end>s2.end;
    else
        return s1.start>s2.start; //종료 시간 같을 때 시작 시간 빠른 순서대로
}
 
int main() {
    
    int n;
    cin>>n;
    
    int start, end; //시작, 종료 시간
    priority_queue<str> pq;
    
    for(int i=0;i<n;i++){
        scanf("%d %d",&start,&end);
        pq.push(str(start,end));
    }
    
    int ans=0;
    end=-1;
    
    while(!pq.empty()){
        str s=pq.top();
        pq.pop();
        
        if(s.start>=end){
            ans++;
            end=s.end;
        }
    }
    
    cout<<ans<<endl;
    return 0;
}
