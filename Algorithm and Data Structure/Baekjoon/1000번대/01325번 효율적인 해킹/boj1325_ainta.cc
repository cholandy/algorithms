#include<stdio.h>
#include<algorithm>
#include<vector>
#define uint unsigned int
using namespace std;
vector<int>E[10100], F[10100], G[10100];
int Num[65536], ord[10100], cnt, SCC[10100], C[10100];
int n, m, sz, Res[10100], RC;
uint D[10100][320];
bool v[10100];
void DFS(int a){
    int i;
    v[a]=true;
    for(i=0;i<E[a].size();i++){
        if(!v[E[a][i]])DFS(E[a][i]);
    }
    ord[++cnt] = a;
}
void DFS2(int a){
    int i;
    SCC[a] = cnt;
    G[cnt].push_back(a);
    for(i=0;i<F[a].size();i++){
        if(!SCC[F[a][i]])DFS2(F[a][i]);
    }
}
int main(){
    int i, j, a, b, k, l;
    for(i=0;i<65536;i++)for(j=0;j<16;j++)if(i&(1<<j))Num[i]++;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        F[b].push_back(a);
    }
    sz = n>>5;
    for(i=1;i<=n;i++){
        if(!v[i])DFS(i);
    }
    cnt = 0;
    for(i=n;i>=1;i--){
        if(!SCC[ord[i]]){
            cnt++;
            DFS2(ord[i]);
        }
    }
    for(i=1;i<=cnt;i++){
        for(j=0;j<G[i].size();j++) D[i][G[i][j]>>5] |= (1u << (G[i][j]&31));
        for(j=0;j<G[i].size();j++){
            a = G[i][j];
            for(k=0;k<E[a].size();k++){
                b = SCC[E[a][k]];
                if(b==i)continue;
                for(l=0;l<=sz;l++)D[b][l] |= D[i][l];
            }
        }
    }
    int mx = 0;
    for(i=1;i<=cnt;i++){
        for(j=0;j<=sz;j++) C[i] += Num[D[i][j]&65535] + Num[D[i][j]>>16];
        mx = max(mx, C[i]);
    }
    for(i=1;i<=cnt;i++){
        if(C[i] == mx){
            for(j=0;j<G[i].size();j++)Res[++RC] = G[i][j];
        }
    }
    sort(Res+1,Res+RC+1);
    for(i=1;i<=RC;i++)printf("%d ",Res[i]);
}
