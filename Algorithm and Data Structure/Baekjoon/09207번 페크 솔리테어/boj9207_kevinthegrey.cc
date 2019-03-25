#include <iostream>
#include <algorithm>
#define endl '\n'
using namespace std;
int N, pin_cnt, move_cnt;
char map[6][10];
 
const int dR[] = { 1, 0, -1, 0 };
const int dC[] = { 0, 1, 0, -1 };
bool inRange(int row, int col)
{
    return (row >= 0 && row < 5) && (col >= 0 && col < 9);
}
void DFS(int depth, int cnt) 
{
    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 9; ++c)
        {
            int cR = r, cC = c;
            if (map[cR][cC] == 'o')
            {
                for (int i = 0; i < 4; ++i)
                {
                    int nR = cR + dR[i];
                    int nC = cC + dC[i];
                    if (inRange(nR, nC) && map[nR][nC] == 'o')
                    {
                        int nnR = nR + dR[i];
                        int nnC = nC + dC[i];
 
                        if (inRange(nnR, nnC) && map[nnR][nnC] == '.')
                        {
                            map[cR][cC] = '.';
                            map[nR][nC] = '.';
                            map[nnR][nnC] = 'o';
                            DFS(depth + 1, cnt - 1);
                            map[cR][cC] = 'o';
                            map[nR][nC] = 'o';
                            map[nnR][nnC] = '.';
                        }
                    }
                }
            }
        }
    }
    if (cnt <= pin_cnt)
    {
        if (cnt == pin_cnt)
            move_cnt = min(move_cnt, depth);
        else
            move_cnt = depth;
        pin_cnt = cnt;
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) 
        {
            cin >> map[i];
            for (int j = 0; j < 9; j++) 
                if (map[i][j] == 'o')  cnt++;
        }
        pin_cnt = cnt, move_cnt = 0;
        DFS(0, cnt);
        cout << pin_cnt << " " << move_cnt << endl;
    }
    return 0;
}
