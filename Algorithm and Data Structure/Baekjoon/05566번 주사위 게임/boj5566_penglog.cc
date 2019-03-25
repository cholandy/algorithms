#include <iostream>
 
using namespace std;
 
int direction[1001];
int dice[1001];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("../input.txt", "r", stdin);
 
    int board_cnt;
    int dice_cnt;
    cin >> board_cnt >> dice_cnt;
 
    for(int i = 1; i <= board_cnt; i++)
        cin >> direction[i];
 
    for(int i = 1; i <= dice_cnt; i++)
        cin >> dice[i];
 
    int cnt = 0;
    int player_position = 1;
 
    while(true){
        // 현재위치에서 주사위 눈금만큼 진행
        player_position += dice[++cnt];
        if(player_position >= board_cnt)
            break;
        // 진행한 위치에 있는 지시사항 수행
        player_position += direction[player_position];
        if(player_position >= board_cnt)
            break;
    }
    cout << cnt;
 
    return 0;
}
