#include <iostream>
using namespace std;

int n, m, h;
int L[12], target[12];
bool install[35][15];

int dfs(int i, int j, int put){
    if(i == h){
        for(int i=0; i<n; i++) if(L[i] != target[i]) return 4;
        return put;
    }
    if(j >= n) return dfs(i+1, 1, put);
    if(install[i][j]){
        swap(L[j], L[j-1]);
        int ans = dfs(i, j+2, put);
        swap(L[j], L[j-1]);
        return ans;
    }
    if(install[i][j-1] || install[i][j+1]) return dfs(i, j+1, put);
    int ans = dfs(i, j+1, put);
    if(put < 3){
        swap(L[j], L[j-1]);
        ans = min(ans, dfs(i, j+2, put+1));
        swap(L[j], L[j-1]);
    }
    return ans;
}

int main(){
    cin>>n>>m>>h;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        install[a-1][b] = true;
    }
    for(int i=0; i<n; i++) L[i] = target[i] = i;
    int res = dfs(0, 1, 0);
    cout << (res == 4? -1:res);
}