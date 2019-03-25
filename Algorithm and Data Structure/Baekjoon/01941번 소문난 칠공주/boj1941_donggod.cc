#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
 
#define ll long long
#define INF 987654321
#define MOD 1000000
#define MAX_SIZE 5
 
using namespace std;
 
char map[MAX_SIZE][MAX_SIZE];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
 
int visit;
 
pair<int, int> toPos(int num) {
    return make_pair(num / 5, num % 5);
}
 
int toNum(pair<int, int> pos) {
    return pos.first * 5 + pos.second;
}
 
//내가 선택한 7명이 연결되어있는지를 확인하는 함수
bool exploration(int state, pair<int, int> pos) {
    visit |= 1 << toNum(pos); // 전역 변수 visit에 해당 학생을 쉬프트하여 체크
    if (state == visit) return 1; //isConnected에서 넘겨받은 state와 exploration으로 방문한 학생이 같으면 리턴 1
 
    bool ret = 0;
 
    for (int i = 0; i < 4; i++) {
        pair<int, int> npos = make_pair(pos.first + dx[i], pos.second + dy[i]);
 
        if (npos.first < 0 || npos.second < 0 || npos.first >= 5 || npos.second >= 5) continue;
        
        int nNum = toNum(npos);
 
        if (visit & (1 << nNum)) continue;
        if ((1 << nNum) & state) ret = max(ret, exploration(state, npos));
    }
    return ret;
}
 
//전부 연결되어있다면 1을 아니라면 0을 리턴하는 함수
bool isConnected(int state) {
    pair<int, int> now;
    
    //포문을 이용하여 내가 선택한 7명 중 한명을 찾아 탐색의 시작점으로 선택
    for (int i = 0; i < 25; i++) {
        if ((1 << i) & state) {
            now = toPos(i);
            visit = 1 << i;
            break;
        }
    }
    
    return exploration(state, now);
}
 
//dfs를 이용하여 25명의 학생 중 7명을 고르는 함수
int f(int num, int d, int state, int sCnt) {
    if (d == 7) {
        if (sCnt >= 4) return isConnected(state);
        else return 0;
    }
    int ret = 0;
 
    for (int i = num + 1; i < 25; i++) {
        pair<int, int> pos = toPos(i);
        ret += f(i, d + 1, state | (1 << i), map[pos.first][pos.second] == 'S' ? sCnt + 1 : sCnt);
    }
 
    return ret;
}
 
int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = getchar();
        }
        getchar();
    }
 
    int ret = 0;
    for (int i = 0; i < 25 - 6; i++) {
        pair<int, int> pos = toPos(i);
        ret += f(i, 1, 1 << i, map[pos.first][pos.second] == 'S' ? 1 : 0);
    }
    printf("%d", ret);
    return 0;
}