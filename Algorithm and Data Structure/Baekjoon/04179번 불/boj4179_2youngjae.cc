#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define P pair<int,int>
using namespace std;
 
int r, c, sx, sy;
int map[1002][1002];
int visited[1002][1002];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
 
void spreadFire(int a,int b) {
    queue<P> q;
    q.push(P(a, b));
    visited[a][b] = 1;
 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            if (map[ax][ay] == '#' || map[ax][ay] == 0) continue;
 
            if (visited[ax][ay] == 0 || visited[ax][ay] > visited[x][y] + 1) {
                visited[ax][ay] = visited[x][y] + 1;
                q.push(P(ax, ay));
            }
        }
    }
}
 
void findExit() {
    queue<P> q;
    q.push(P(sx, sy));
    visited[sx][sy] = 1;
 
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
 
        if (x == 1 || y == 1 || x == r || y == c) {
            cout << visited[x][y] << endl;
            return;
        }
 
        for (int i = 0; i < 4; i++) {
            int ax = x + dx[i];
            int ay = y + dy[i];
            
            if (map[ax][ay] == '#' || map[ax][ay] == 0) continue;
 
            if (visited[ax][ay] == 0 || visited[ax][ay] > visited[x][y] + 1) {
                visited[ax][ay] = visited[x][y] + 1;
                q.push(P(ax, ay));
            }
        }
    }
 
    cout << "IMPOSSIBLE" << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> r >> c;
    vector<P> v;
 
    for (int i = 1; i <= r; i++) {
        string buf;
        cin >> buf;
        for (int j = 1; j <= c; j++) {
            map[i][j] = buf[j - 1];
            if (map[i][j] == 'J') {
                sx = i;
                sy = j;
            }
            if (map[i][j] == 'F') {
                v.push_back(P(i, j));
            }
        }
    }
 
    for (auto &p : v) {
        spreadFire(p.first, p.second);
    }
    findExit();
 
}
