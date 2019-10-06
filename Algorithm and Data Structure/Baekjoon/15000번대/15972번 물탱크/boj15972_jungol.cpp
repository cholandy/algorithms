#include <bits/stdc++.h>

#define NN 1010

using namespace std;

int N,M,H,ans;
int rh[NN][NN], ch[NN][NN];
bool chk[NN][NN];

struct data {
    int r,c,h;
    bool operator< (const data &r) const{
        return h > r.h;
    }
};

priority_queue <data> que;

void push(int r, int c, int h) {
    if (chk[r][c]) return;
    que.push({r,c,h});
}

void input() {
    int i, j;
    scanf("%d %d %d", &N, &M, &H);
    for (i=1; i<=N+1; ++i) {
        for (j=1; j<=M; ++j) {
            scanf("%d", &rh[i][j]);
            if (rh[i][j] == -1) rh[i][j] = H;
        }
    }
    for (i=1; i<=N; ++i) {
        for (j=1; j<=M+1; ++j) {
            scanf("%d", &ch[i][j]);
            if (ch[i][j] == -1) ch[i][j] = H;
        }
    }
    for (i=1; i<=N; ++i) {
        push(i, 1, ch[i][1]);
        push(i, M, ch[i][M+1]);
        chk[i][0] = chk[i][M+1] = true;
    }
    for (i=1; i<=M; ++i) {
        push(1, i, rh[1][i]);
        push(N, i, rh[N+1][i]);
        chk[0][i] = chk[N+1][i] = true;
    }
}

int main() {
    input();
    data tmp;
    int r,c,h;
    while (!que.empty()) {
        tmp = que.top();
        que.pop();
        r = tmp.r, c = tmp.c, h = tmp.h;
        if (chk[r][c]) continue;
        chk[r][c] = true;
        ans +=h;
        push(r-1, c, max(h, rh[r][c]));
        push(r+1, c, max(h, rh[r+1][c]));
        push(r, c-1, max(h, ch[r][c]));
        push(r, c+1, max(h, ch[r][c+1]));
    }
    printf("%d\n", ans);
    return 0;
}