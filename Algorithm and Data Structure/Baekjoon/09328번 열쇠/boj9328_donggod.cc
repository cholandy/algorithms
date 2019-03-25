#include <cstdio>
#include <iostream>
#include <vector>
#include <string.h>
 
#define ll long long
#define MAX_SIZE 110
#define ALPHA_SIZE 26
using namespace std;
 
vector<pair<int, int> > v;
 
int h, w;
char map[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];
bool key[ALPHA_SIZE];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0,0};
bool flag;
 
void input()
{
    scanf("%d %d", &h, &w);
    getchar();
 
    for(int i = 1; i <= h; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            map[i][j] = getchar();
        }
        getchar();
    }
 
    while(1)
    {
        char c = getchar();
        if(c == '0' || c == '\n')break;
        else key[c - 'a'] = 1;
    }
}
 
int dfs(int x, int y)//0,0
{
    int ret = 0;
 
    visit[x][y] = 1;
 
    if(map[x][y] == '$') ret++;
 
    else if(map[x][y] >= 'a' && map[x][y] <= 'z')
    {
        key[map[x][y] - 'a'] = 1;
        flag = 1;
    }
 
 
    for(int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
 
        if(nx < 0 || ny < 0 || nx > h + 1|| ny > w + 1) continue;
        if(map[nx][ny] == '*') continue;
        if(visit[nx][ny]) continue;
 
        if(map[nx][ny] >= 'A' && map[nx][ny] <= 'Z' && !key[map[nx][ny] - 'A'])
        {
            v.push_back(make_pair(nx, ny));
            continue;
        }
 
        ret += dfs(nx, ny);
    }
 
 
    return ret;
}
 
 
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        //초기화 부분
        memset(visit, 0, sizeof(visit));
        memset(key, 0, sizeof(key));
        memset(map, 0, sizeof(map));
        v.clear();
 
        input(); // 입력 부분
 
        int ret = dfs(0, 0); // dfs 첫 탐색
 
        while(1) // 와일문을 반복하며 백터를 탐색
        {
            flag = 0;
 
            for(int i = 0; i < v.size(); i++)
            {
                if(key[map[v[i].first][v[i].second] - 'A'])
                    ret += dfs(v[i].first, v[i].second);
            }
 
            if(flag == 0) break; // 키를 얻은 것이 없다면 탈출
        }
 
        printf("%d\n", ret);
    }
    return 0;
}
