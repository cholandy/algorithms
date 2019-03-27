#include<iostream>
 
using namespace std;
 
char board[5][9];
 
int move_cnt = 0;
int pin_num = 0;
 
int smallest_pin_num = 0;
int smallest_move_cnt = INT8_MAX; // 백준에선 INT_MAX 사용 -> 컴파일 에러
 
// 상하좌우
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
 
void dfs1();
 
void dfs(int _x, int _y) {
 
    for (int k = 0; k < 4; k++) {
        int x = _x + dx[k];
        int y = _y + dy[k];
        int new_x = x + dx[k];
        int new_y = y + dy[k];
 
        if ( (x<0 || x>4) || (y<0 || y>8)
            || (new_x<0 || new_x>4)
            || (new_y<0 || new_y>8) ) { // 범위를 벗어나면 continue
            continue;
        }
        if (board[x][y]=='o' && board[new_x][new_y]=='.') { // 핀있으면 뛰어 넘을 수 잇음
             
            board[_x][_y] = board[x][y] = '.';
            board[new_x][new_y] = 'o';
            pin_num--;
            move_cnt++;
             
            dfs1();
 
            pin_num++;
            move_cnt--;
            board[_x][_y] = board[x][y] = 'o';
            board[new_x][new_y] = '.';
        }
    }
}
 
void dfs1() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 'o') {
                dfs(i, j);
            }
        }
    }
    // 반복문 다 돌고, 재귀도 다 돌고 나왔다는 것은
    // 더 이상 이동할 수 있는 핀이 없음
    if (smallest_pin_num == pin_num && smallest_move_cnt>move_cnt) {
        smallest_pin_num = pin_num;
        smallest_move_cnt = move_cnt;
    }
    else if (smallest_pin_num>pin_num) {
        smallest_pin_num = pin_num;
        smallest_move_cnt = move_cnt;
    }
}
 
int main() {
 
    int tc;
    cin >> tc;
 
    for (int i = 0; i < tc; i++) {
         
        // 입력받기
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                char temp;
                cin >> temp;
                 
                if (temp=='o') {
                    pin_num++;
                    smallest_pin_num++;
                }
                board[i][j] = temp;
            }
        }
 
        // 연산
        dfs1();
 
        // 출력
        cout << smallest_pin_num << " " << smallest_move_cnt << endl;
     
        // 초기화
        move_cnt = 0;
        pin_num = 0;
 
        smallest_pin_num = 0;
        smallest_move_cnt = INT8_MAX;
    }
    return 0;
}
