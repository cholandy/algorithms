#include<stdio.h>
#include<queue>
#include<string>
#include<math.h>
#include<stack>
#include<string.h>
using namespace std;
void bfs(int, int);
void trace(pair<int,int>[], int);
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int A, B;
        scanf("%d%d", &A, &B);
        bfs(A, B);
        printf("\n");
    }
}
void bfs(int A, int B)
{
    int isVisited[10000] = { 0, };
    pair<int, int> before[10000];
    queue<int> q;
    isVisited[A] = 1;
    before[A] = { -1,-1 };
    q.push(A);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (n == B) {
            trace(before, B); return;
        }
        int to[4];
        to[0] = n * 2 % 10000;
        to[1] = n == 0 ? 9999 : n - 1;
        to[2] = n % 1000 * 10 + n / 1000;
        to[3] = n % 10 * 1000 + n / 10;
        for (int i = 0; i < 4; ++i)
            if (!isVisited[to[i]])
            {
                isVisited[to[i]] = 1;
                before[to[i]] = { i,n };
                q.push(to[i]);
            }
    }
}
void trace(pair<int,int> before[],int n)
{
    stack<int> st;
    while (before[n].first!=-1)
    {
        st.push(before[n].first);
        n = before[n].second;
    }
    while (!st.empty())
    {
        switch (st.top())
        {
        case 0:printf("D"); break;
        case 1:printf("S"); break;
        case 2:printf("L"); break;
        case 3:printf("R"); break;
        }
        st.pop();
    }
}
 