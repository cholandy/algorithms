#include <vector>
#include <queue>
using namespace std;
int N,M;
int map[1501][1501];
int numMelt = 0;
int numVisit = 1;
int check[1501][1501]={};
int water[1501][1501]={};
int L[2][2];
int dx[4] ={0,1,0,-1};
int dy[4] ={1,0,-1,0};
vector<pair<int, int> > ice;

int waterBFS(){
    int cnt = 1;
    queue<pair<int, int> > waterQ;
    
    for (int n = 0; n < N; n++)
        for (int m = 0; m < M; m++)
            if (map[n][m] == '.' || map[n][m] == 'L') {
                check[n][m] = 1;
                waterQ.push(make_pair(n,m));
            }
    while(!waterQ.empty()){
        int sz = waterQ.size();
        for(int i = 0;i<sz;i++){
            int x = waterQ.front().first;
            int y = waterQ.front().second;
            waterQ.pop();
            check[x][y] = 1;
            for(int i = 0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >=M || check[nx][ny]) continue;
                else if(map[nx][ny] != 'L'){
                    water[nx][ny] = cnt;
                    check[nx][ny] = 1;                    
                    waterQ.push(make_pair(nx,ny));
                }
            }
        }
        cnt++;
    }
    return cnt-2;
}
bool BFS(int limit){
    int ret = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(L[0][0],L[0][1]));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x == L[1][0] && y == L[1][1]) return true;        
        check[x][y] = numVisit;
        for(int i = 0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >=M || check[nx][ny] >= numVisit) continue;
                if(water[nx][ny] <= limit)
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = numVisit;
                }
    }
    return false;
}
int main(){
    int cnt = 0;
    scanf("%d%d",&N,&M);
    for(int i = 0;i<N;i++){
        char tp[1501];
        scanf("%s",tp);
        for(int j = 0;j<M;j++){
            map[i][j] = tp[j];
            if(map[i][j] == 'X'){
                ice.push_back(make_pair(i,j));
            }else{
                if(map[i][j] == 'L') {
                    L[cnt][0] = i;
                    L[cnt++][1] = j;
                }
            }
        }
    }
    int l=0,h,m=0;
    h = waterBFS();
    while(l <= h){        
        for(int i = 0;i<N;i++){
            for(int j = 0;j<M;j++){
                check[i][j] = 0;
            }
        }
        numVisit++;        
        m = (l+h)/2;
        
        if(BFS(m)) h = m -1;
        else l = m+1;
    }
    printf("%d\n",l);
}