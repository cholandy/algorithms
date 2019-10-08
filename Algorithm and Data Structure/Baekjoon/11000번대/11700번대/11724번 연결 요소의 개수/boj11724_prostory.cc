#include <bits/stdc++.h>
using namespace std;
 
int adj[1005][1005];
int arr[1005],n,m,cnt;
 
int dfs(int k){
    for(int i=1;i<=n;i++){
        if(adj[k][i]==1&&arr[i]==0){
            arr[i]=1;
            dfs(i);
        }
    }
}
 
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i=1;i<=n;i++){
        if(arr[i]==0){
            arr[i]=1;
            dfs(i);
            cnt++;
        }
    }
    printf("%d",cnt);
    return 0;
}
