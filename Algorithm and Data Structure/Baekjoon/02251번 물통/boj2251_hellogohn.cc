#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
 
int visited[200][200][200] = { 0 };
int capacity[3];
int now_water[3] = { 0 };
vector<int> answer_vec;  
int move_map[6][2] = { {0,1},{0,2},{1,0},{1,2},{2,0},{2,1} };
 
// 방문한 노드 1로 표시 
void plusVisited() {
    visited[now_water[0]][now_water[1]][now_water[2]] = 1;
}
 
// 방문 여부 리턴
int isVisited() {
    if (visited[now_water[0]][now_water[1]][now_water[2]]) return 1;
    else return 0;
}
 
// 정답이면 vec에 넣는다. 
void answerPush() {
    if (now_water[0] == 0 )  answer_vec.push_back(now_water[2]);
}
 
int dfs(int depth, int from, int to) {
    //cout << depth <<  " from = "  << from << "  to = " << to  << " _ " << now_water[0] << "/" << now_water[1] << "/" << now_water[2] <<  endl;
 
    // 현재 정보들 받아오기 위한 행렬 
    int sub_now_waters[3];
 
    // stack 에 있는 내용 받아오기 
    pair<int, int> now_move = pair<int, int>(from, to);
 
    // from 물통에서의 용량이 0 이면 그냥 종료 
    if (now_water[now_move.first] == 0) return -1;
    // to 물통이 다 차있으면 그냥 종료 
    if (now_water[now_move.second] == capacity[now_move.second]) return -1;
 
    // 만약 from 물통에서의 남은 물의 용량이 to 물통에서 넣을 수 있는 물의 용량보다 크다면 
    if (now_water[now_move.first] > capacity[now_move.second] - now_water[now_move.second]) {
        now_water[now_move.first] -= capacity[now_move.second] - now_water[now_move.second];
        now_water[now_move.second] = capacity[now_move.second];
    }
    // 반대로 넣을 수 있는 물의 용량이 작다면 
    else {
        now_water[now_move.second] += now_water[now_move.first];
        now_water[now_move.first] = 0;
    }
 
    // 방문한 노드면 그냥 종료 
    if (isVisited()) { 
        return 1;
    }
 
    // 현재 상태 방문 저장 
    plusVisited();
 
    // 만약 A의 용량이 0이면 해당 C의 용량을 답에 저장 
    answerPush();
 
    // 현재 노드 상태 저장 
    for (int i = 0; i < 3; i++) {
        sub_now_waters[i] = now_water[i];
    }
 
    // 다음 이동 경로 push 
    for (int i = 0; i < 6; i++) {   
        dfs(depth + 1,  move_map[i][0], move_map[i][1]);
        // 원래 상태로 복귀 
        for (int i = 0; i < 3; i++) {
            now_water[i] = sub_now_waters[i];
        }
    } 
 
    return 0; 
}
 
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> capacity[i]; 
    }
    // 초기 물 채워주기 
    now_water[2] = capacity[2];
    // 방문한 노드에 추가
    plusVisited(); 
    // 정답에 추가 
    answerPush();
     
    // 다음 이동 경로 push 
    for (int i = 4; i < 6; i++) { 
        
        dfs(0, move_map[i][0], move_map[i][1]);
            
        // 원래 상태로 복귀 
        now_water[0] = now_water[1] = 0;
        now_water[2] = capacity[2];
        
    } 
 
    sort(answer_vec.begin(), answer_vec.end()); 
    for (int i = 0; i < answer_vec.size(); i++)
        cout << answer_vec[i] << " ";
     
    return 0; 
}