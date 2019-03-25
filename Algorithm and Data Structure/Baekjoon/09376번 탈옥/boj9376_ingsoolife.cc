#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int min(int a, int b) {
 return (a < b) ? a : b;
}
struct node {
 int h, w;
};
bool inside(int h, int w, int H, int W) {
 return (h >= 0 && h <= H + 1) && (w >= 0 && w <= W + 1);
}
char board[102][102];
int H, W;
void solve(node src, int cache[102][102]);
int main() {
 int T;

 cin >> T;

 int c1[102][102];
 int c2[102][102];
 int c3[102][102];
 for (int t = 0; t < T; t++) {
  memset(c1, -1, sizeof(int) * 102 * 102);
  memset(c2, -1, sizeof(int) * 102 * 102);
  memset(c3, -1, sizeof(int) * 102 * 102);
  cin >> H >> W;
  for (int h = 0; h <= H+1; h++) {
   for (int w = 0; w <= W + 1; w++)
    board[h][w] = '.';
  }
  node pos1 = { -1,-1 }, pos2;
  for (int h = 1; h <= H; h++) {
   for (int w = 1; w <= W; w++) {
    cin >> board[h][w];
    if (board[h][w] == '$') {
     if (pos1.h == -1) {
      pos1.h = h;
      pos1.w = w;
     }
     pos2.h = h;
     pos2.w = w;
    }
   }
    
  }
  solve({ 0,0 }, c1);
  solve(pos1, c2);
  solve(pos2, c3);

  int ans = 100000;
  for (int h = 1; h < H + 1; h++) {
   for (int w = 1; w < W + 1; w++)
    if (board[h][w] == '#')
     ans = min(ans, c1[h][w] + c2[h][w] + c3[h][w] - 2);
  }

  ans = min(ans, c1[pos1.h][pos1.w] + c2[pos1.h][pos1.w] + c3[pos1.h][pos1.w]);
  ans = min(ans, c1[pos2.h][pos2.w] + c2[pos2.h][pos2.w] + c3[pos2.h][pos2.w]);
  cout << ans << endl;
 }
}
void solve(node src, int cache[102][102]) {
 queue<node> q;
 q.push(src);
 cache[src.h][src.w] = 0;
 node parent, child;
 int dirH[4] = { -1,1,0,0 };
 int dirW[4] = { 0,0,-1,1 };
 int nextH, nextW;

 while (!q.empty()) {
  parent = q.front();
  q.pop();

  for (int i = 0; i < 4; i++) {
   nextH = parent.h + dirH[i];
   nextW = parent.w + dirW[i];
   if (inside(nextH, nextW, H, W) && board[nextH][nextW] != '*') {
    if (board[nextH][nextW] == '#') {
     if (cache[nextH][nextW] == -1 || cache[parent.h][parent.w] + 1 < cache[nextH][nextW]) {
      child.h = nextH; child.w = nextW;
      cache[nextH][nextW] = cache[parent.h][parent.w] + 1;
      q.push(child);
     }
    }
    else {
     if (cache[nextH][nextW] == -1 || cache[parent.h][parent.w] < cache[nextH][nextW]) {
      child.h = nextH; child.w = nextW;
      cache[nextH][nextW] = cache[parent.h][parent.w];
      q.push(child);
     }
    }
   }
  }
 }


}