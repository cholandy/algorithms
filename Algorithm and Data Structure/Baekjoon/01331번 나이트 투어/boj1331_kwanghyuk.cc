#include <iostream>
#include <string>
using namespace std;
 
// 조건
// 1. 모든 칸을 전부 방문 했는지
// 2. 겹치는 칸이 있는지
// 3. 나이트가 이동할 수 있는 경로로 이동했는지
// A -> ASCii 65번, 0 -> 48번
 
int main() {
    int visit[7][7];
    int a, b, preA, preB;
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {-2,-1,1,2,-2,-1,1,2};
    char input[37][3];
    string result="Valid";
 
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            visit[i][j] = 0;
 
    for (int i = 0; i < 36;i++)
        cin >> input[i][0] >> input[i][1];
 
    for (int i = 0; i < 36; i++) {
        a = (int)input[i][0] - 65;
        b = (int)input[i][1] - 49;
        preA = (int)input[i - 1][0] - 65;
        preB = (int)input[i - 1][1] - 49;
        // 2번 조건
        if (visit[a][b]) { break; }
        visit[a][b] = 1;
 
        // 3번 조건
        bool case3 = false;
        for (int j = 0; j < 8; j++) {
            int aa = preA + dx[j];
            int bb = preB + dy[j];
            if (aa < 0 || aa>5 || bb < 0 || bb>5)
                continue;
            if (aa == a && bb == b)
                case3 = true;
        }
        if (!case3 && i!=0) { break; }
    }
 
 
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (!visit[i][j])
                result = "Invalid";
 
    // 마지막 방문점에서 첫지점으로 갈 수 있는지 판별
    bool case4 = false;
    for (int j = 0; j < 8; j++) {
        int aa = ((int)input[0][0] - 65) + dx[j];
        int bb = ((int)input[0][1] - 49) + dy[j];
        if (aa < 0 || aa>5 || bb < 0 || bb>5)
            continue;
        if (aa == ((int)input[35][0] - 65) && bb == ((int)input[35][1] - 49))
            case4 = true;
    }
 
    if (!case4)
        result = "Invalid";
 
    cout << result;
    return 0;
}
