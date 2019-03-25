	
#include <iostream>
#include <queue>
 
using namespace std;
 
struct info {
    int r;
    int c;
    // 말 움직임 사용 횟수
    int cnt;
    int ans;
};
 
bool flag = false;
int K, W, H;
int map[201][201];
int visited[201][201][31];
// 말 움직임
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
// 위, 오른쪽, 아래, 왼쪽
int dr2[4] = {-1, 0, 1, 0};
int dc2[4] = {0, 1, 0, -1};
 
queue<info> q;
 
int main() {
    cin >> K >> W >> H;
 
    for(int r = 0; r < H; r ++) {
        for(int c = 0; c < W; c ++) {
            cin >> map[r][c];
        }
    }
    // r, c, 말 움직임 횟수
    visited[0][0][0] = 1;
    q.push({0, 0, 0, 0});
 
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int cnt = q.front().cnt;
        int ans = q.front().ans;
        q.pop();
 
        // 도착지라면 정답 출력
        if(r == H - 1 && c == W - 1) {
            flag = true;
            cout << ans;
            break;
        }
 
        // 말 움직임을 더할 수 있다면
        if(cnt < K) {
            for(int i = 0; i < 8; i ++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
 
                if(nr >= 0 && nr < H && nc >= 0 && nc < W) {
                    if(!map[nr][nc] && !visited[nr][nc][cnt + 1]) {
                        visited[nr][nc][cnt + 1] = 1;
                        q.push({nr, nc, cnt + 1, ans + 1});
                    }
                }
            }
        }
        // 위, 오른쪽, 아래, 왼쪽 이동
        for(int i = 0; i < 4; i ++) {
            int nr = r + dr2[i];
            int nc = c + dc2[i];
 
            if(nr >= 0 && nr < H && nc >= 0 && nc < W) {
                if(!map[nr][nc] && !visited[nr][nc][cnt]){
                    visited[nr][nc][cnt] = 1;
                    q.push({nr, nc, cnt, ans + 1});
                }
            }
        }
    }
 
    if(!flag)
        cout << -1;
 
    return 0;
}