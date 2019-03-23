#include <iostream>
#include <cstdio>
#include <queue>
 
using namespace std;
 
char str[255][255];
bool visit[255][255];
 
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
 
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
 
    int wolf = 0, lamb = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf(" %c", &str[i][j]);
            if (str[i][j] == 'v')
                wolf++;
            else if (str[i][j] == 'o')
                lamb++;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        queue<pair<int, int> > q;
 
        for (int j = 0; j < m; j++)
        {
            int tWolf = 0, tLamb = 0;
 
            if (str[i][j] != '#' && !visit[i][j])
            {
                q.push({ i,j });
 
                while (!q.empty())
                {
                    int y = q.front().first;
                    int x = q.front().second;
 
                    q.pop();
 
                    if (visit[y][x])
                        continue;
 
                    visit[y][x] = true;
 
                    if (str[y][x] == 'v')
                        tWolf++;
                    else if (str[y][x] == 'o')
                        tLamb++;
 
                    for (int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
 
                        if (!((0 <= ny && ny < n) && (0 <= nx && nx < m)) || str[ny][nx] == '#' || visit[ny][nx])
                            continue;
 
                        q.push({ ny,nx });
                    }
 
                }
                if (tWolf >= tLamb)
                    lamb -= tLamb;
                else
                    wolf -= tWolf;
            }
        }
    }
    
    printf("%d %d", lamb, wolf);
    
     return 0;
}
