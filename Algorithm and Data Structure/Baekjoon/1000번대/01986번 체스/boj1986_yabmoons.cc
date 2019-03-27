#include<iostream>
#include<cstring>
 
#define endl "\n"
#define MAX 1001
using namespace std;
 
int N, M;
int Queen_Num, Knight_Num, Pawn_Num;
int MAP[MAX][MAX];
bool State[MAX][MAX];
 
int Q_dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int Q_dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
 
int K_dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int K_dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
 
void Input()
{
    cin >> N >> M;
    cin >> Queen_Num;
    for (int i = 0; i < Queen_Num; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;    // Queen = 1로 표현
    }
 
    cin >> Knight_Num;
    for (int i = 0; i < Knight_Num; i++)
    {
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 2;    // Knight = 2로 표현
    }
    
    cin >> Pawn_Num;
    for (int i = 0; i < Pawn_Num; i++)
    {
        int a, b; 
        cin >> a >> b;
        MAP[a][b] = 3;    // Pawn = 3으로 표현
    }
}
 
void State_Of_MAP(int x, int y, char C)
{
    if (C == 'Q')
    {
        for (int i = 0; i < 8; i++)
        {
            int nx = x + Q_dx[i];
            int ny = y + Q_dy[i];
 
            while (1)
            {
                if (nx < 1 || ny < 1 || nx > N || ny > M) break;
                if (MAP[nx][ny] != 0) break;
 
                State[nx][ny] = true;
                nx = nx + Q_dx[i];
                ny = ny + Q_dy[i];
            }
        }
    }
    else if (C == 'K')
    {
        for (int i = 0; i < 8; i++)
        {
            int nx = x + K_dx[i];
            int ny = y + K_dy[i];
 
            if (nx >= 1 && ny >= 1 && nx <= N && ny <= M)
            {
                if (MAP[nx][ny] == 0) State[nx][ny] = true;
            }
        }
    }
}
 
void Print()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (State[i][j] == true) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
 
void Make_MAP_State()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] == 0) continue;
            
            if (MAP[i][j] == 1)
            {
                State[i][j] = true;
                State_Of_MAP(i, j, 'Q');
            }
            else if (MAP[i][j] == 2)
            {
                State[i][j] = true;
                State_Of_MAP(i, j, 'K');
            }
            else if (MAP[i][j] == 3)
            {
                State[i][j] = true;
            }
        }
    }
}
 
int Check_Safe_Area()
{
    int Cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (MAP[i][j] == 0 && State[i][j] == false) Cnt++;
        }
    }
    return Cnt;
}
 
void Solution()
{
    Make_MAP_State();
    cout << Check_Safe_Area() << endl;
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    Solve();
 
    return 0;
}
