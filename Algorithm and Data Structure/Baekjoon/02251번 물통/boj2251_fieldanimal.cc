#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int isVisited[201][201][201];
vector<int> ans;
typedef struct status {
    int h[3];
} status;
queue<status> q;
void bfs();
int cap[3];
int main()
{
    for (int i = 0; i < 3; ++i)
        scanf("%d", &cap[i]);
    bfs();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ", ans[i]);
}
void bfs()
{
    isVisited[0][0][cap[2]] = 1;
    q.push({ 0,0,cap[2] });
    while (!q.empty())
    {
        status cur = q.front();
        q.pop();
 
        if (cur.h[0] == 0)
            ans.push_back(cur.h[2]);
        for (int i = 0; i<3; ++i)
            for (int j = 0; j < 3; ++j)
            {
                if (cur.h[i] == 0)
                    continue;
                if (i != j)
                {
                    int tmp[3];
                    for (int k = 0; k < 3; ++k)
                        tmp[k] = cur.h[k];
                    if (cap[j] - tmp[j] <= tmp[i])
                    {
                        tmp[i]-=cap[j] - tmp[j];
                        tmp[j] = cap[j];
                    }
                    else
                    {
                        tmp[j] = tmp[j] + tmp[i];
                        tmp[i] = 0;
                    }
                    if (!isVisited[tmp[0]][tmp[1]][tmp[2]])
                    {
                        isVisited[tmp[0]][tmp[1]][tmp[2]] = 1;
                        q.push({ tmp[0],tmp[1],tmp[2] });
                    }
                }
                
            }
    }
}
