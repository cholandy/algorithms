#include < iostream >
#include < string >
 
#define SZ 101
#define INF 987654321
 
using namespace std;
 
int map[SZ][SZ] = { 0, };
int r = 50, c = 50;
int d = 0; //남쪽
            // 남서북동 0 1 2 3
            // R : d=(d+1)%4;
            // L : d=(d-1)%4; if(d==-1) d=3;
int main(void) {
     
    // 시작위치 (50,50) 이동 가능 표시
    map[r][c] = 1;
 
    // 입력
    int n;
    cin >> n;
    string str;
    cin >> str;
 
    // 문자열에서 가리키는 이동가능한 위치들 다 표시
    for (int i = 0; i < n; i++) {
        switch (str[i]) // 문자열에서 문자 하나씩 처리
        {
        case 'F':
            // 현재 바라보는 방향에 따라 이동 다르게
            switch (d)
            {
            case 0: // 남
                r = r + 1;
                break;
            case 1: // 서
                c = c - 1;
                break;
            case 2: // 북
                r = r - 1;
                break;
            case 3: // 동
                c = c + 1;
                break;
            }
            break;
        case 'R':
            d = (d + 1) % 4;
            break;
        case 'L':
            d = (d - 1) % 4;
            if (d == -1) d = 3;
            break;
        }
        map[r][c] = 1; // 이동가능함 표시
    }
     
    // 직사각형의 가장 왼쪽 상단의 시작위치 찾기
    // 직사각형의 가로, 세로 크기 찾기
    int sp_x = INF, sp_y = INF;  // 시작위치
    int ep_x = -1, ep_y = -1; // 끝 위치
    for (int x = 0; x < SZ; x++) {
        for (int y = 0; y < SZ; y++) {
            if (map[x][y] == 1) {
                if (sp_x > x) { // 시작 위치
                    sp_x = x;
                }
                if (sp_y > y) {
                    sp_y = y;
                }
 
                if (ep_x < x) { // 끝 위치
                    ep_x = x;
                }
                if (ep_y < y) {
                    ep_y = y;
                }
                 
                 
            }
        }
    }
 
    // 미로 출력하기 map[][]==1 : .
    //               map[][]==0 : #
    for (int x = sp_x; x <= ep_x; x++) {
        for (int y = sp_y; y <= ep_y; y++) {
            if (map[x][y]==1) {
                cout << ".";
            }
            else {
                cout << "#";
            }
        }
        cout << endl;
    }
 
 
    return 0;
}