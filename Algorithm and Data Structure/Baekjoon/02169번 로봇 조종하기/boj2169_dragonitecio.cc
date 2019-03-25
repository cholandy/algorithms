#include <iostream>
#include <algorithm>
#define SIZE 1005 // 1005
using namespace std;
int map[SIZE][SIZE];
int dmap[SIZE][SIZE];
 
int x, y, nx, ny;
int store[2][SIZE]; // 0 이, 위와 오른쪽 비교, 1이 위와 왼쪽 비교 입니다.
int N, M;
 
void problemIn() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}
 
void solve() {
 
    // 1 행에 대해서 처리를 합니다.
    dmap[0][0] = map[0][0];
    for (int j = 1; j < M; j++) {
        dmap[0][j] = map[0][j] + dmap[0][j - 1];
    }
 
    for (int i = 1; i < N; i++) {
 
        // 위에서 내려왔을때 크기
        for (int j = 0; j < M; j++) {
            store[0][j] = store[1][j] = dmap[i - 1][j] + map[i][j]; // 일단 store 에 내려왔을때의 값을 저장해둡니다.
        }
 
        // 왼쪽에서 왔을 때
        for (int j = 1; j < M; j++) {
            store[0][j] = max(store[0][j], store[0][j-1]+map[i][j]);
        }
 
        // 오른쪽에서 돌아 왔을 때
        for (int j = M - 2; j >= 0; j--) {
            store[1][j] = max(store[1][j], store[1][j+1] + map[i][j]);
        }
 
        // 위,인,오 중에 가장 큰 값을 저장합니다.
        for (int j = 0; j < M; j++) {
            dmap[i][j] = max(store[0][j], store[1][j]);
        }
    }
}
 
int main() {
    problemIn();
    solve();
    cout << dmap[N - 1][M - 1] << endl;
    return 0;
}


