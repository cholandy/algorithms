#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 
#define RC_MX 1000 + 1
#define SIDE 4
#pragma warning(disable:4996)

int main() {
    char map[RC_MX][RC_MX] = { 0 };
    int jihoon_depth[RC_MX][RC_MX];
    int fire_depth[RC_MX][RC_MX];
    int side_arr[SIDE][2] = { {-1,0},{1,0},{0,-1},{0,1} };
    queue<pair<int, int>> jihoon_queue, fire_queue;
    int R, C; scanf("%d %d", &R, &C);
    int jihoon_size = 0, fire_size = 0;
    // input을 처리
    for (int row = 0; row < R; row++)
        for (int col = 0; col < C; col++){
            jihoon_depth[row][col] = fire_depth[row][col] = -1;
            scanf(" %c", &map[row][col]);

            if (map[row][col] == 'J') {
                jihoon_queue.push({ row , col });
                jihoon_size++;
                jihoon_depth[row][col] = 0;
            }
            else if (map[row][col] == 'F') {
                fire_queue.push({ row , col });
                fire_size++;
                fire_depth[row][col] = 0;
            }
        }

    // 불 먼저
    int depth = 1;
    while (jihoon_size) {
        // 불 갱신 
        while (fire_size) {
            fire_size--;
            pair<int, int> this_fire = fire_queue.front(); fire_queue.pop();
            for (int side_idx = 0; side_idx < SIDE; side_idx++) {
                int new_row = this_fire.first + side_arr[side_idx][0];
                int new_col = this_fire.second + side_arr[side_idx][1];

                // 인덱스 체크
                if (new_row < 0 || new_row >= R) continue;
                if (new_col < 0 || new_col >= C) continue;              
                if (map[new_row][new_col] == '#') continue; // 벽 체크 
                if (fire_depth[new_row][new_col] >= 0) continue; // 이전 단계 불 체크  
                fire_depth[new_row][new_col] = depth;
                fire_queue.push({ new_row, new_col });
            }
        }

        // 지훈 갱신
        while(jihoon_size){
            jihoon_size--;
            pair<int, int> this_jihoon = jihoon_queue.front(); jihoon_queue.pop();
            // 이전 단계에서 불이 넘친 구역이라면 그냥 넘긴다. 
            if (0 <= fire_depth[this_jihoon.first][this_jihoon.second]
                && fire_depth[this_jihoon.first][this_jihoon.second] < depth) continue;

            for (int side_idx = 0; side_idx < SIDE; side_idx++) {
                int new_row = this_jihoon.first + side_arr[side_idx][0];
                int new_col = this_jihoon.second + side_arr[side_idx][1];

                // 인덱스 체크 == 정답 
                if (new_row < 0 || new_row >= R || new_col < 0 || new_col >= C){
                    printf("%d", depth);
                    return 0; 
                }

                if (map[new_row][new_col] == '#') continue; // 벽 체크 
                if (0 <= fire_depth[new_row][new_col]
                    && fire_depth[new_row][new_col] < depth) continue; // 이전 단계 불 체크 
                if (jihoon_depth[new_row][new_col] >= 0) continue; // 이전 지훈 방문 여부 체크

                jihoon_depth[new_row][new_col] = depth;
                jihoon_queue.push({ new_row, new_col });
            }
        }

        if (jihoon_size == 0) {
            jihoon_size = jihoon_queue.size();  
            fire_size = fire_queue.size();
            depth++;
        }
    }

    printf("IMPOSSIBLE");
    return 0;
}