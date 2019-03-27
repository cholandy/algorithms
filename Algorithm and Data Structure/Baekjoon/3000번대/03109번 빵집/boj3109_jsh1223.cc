#include <iostream>
 
using namespace std;
int R, C, ans;
int dir[3][2] = { { -1, 1 }, {0,1},{ 1, 1 } };
char g[10000][501];
 
int pipe(int r, int c) {
    g[r][c] = 'x';
    if (c == C - 1) return 1;
 
    for (int i = 0; i < 3; i++) {
        int nR = r + dir[i][0];
        int nC = c + dir[i][1];
 
        if (nR < 0 || nC < 0 || nR >= R || nC >= C) continue;
        if (g[nR][nC] == 'x') continue;
        
        if (pipe(nR, nC)) return 1; //return pipe(nR, nC); 오답! 
    }
    return 0;
}
int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        cin >> g[i];
    }
 
    for (int i = 0; i < R; i++) {
        ans += pipe(i, 0);
    }
 
    cout << ans << '\n';
 
    return 0;
}
