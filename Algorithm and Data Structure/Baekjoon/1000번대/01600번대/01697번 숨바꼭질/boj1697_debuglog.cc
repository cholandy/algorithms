#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
​
int find(int from, int to)
{
    queue<pair<int, int>> q;
    bool visited[100001] = { false };
    q.push({ from, 0 });
​
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
​
        if (cur < 0 || cur > 100000) continue;
        if (visited[cur]) continue;
​
        visited[cur] = true;
​
        if (cur == to)
            return cnt;
​
        q.push({ cur * 2, cnt + 1 });
        q.push({ cur + 1, cnt + 1 });
        q.push({ cur - 1, cnt + 1 });
    }
}
​
int main(void) {
    int n, k;
    scanf("%d %d", &n, &k); 
    printf("%d\n", find(n, k));
    return 0;
}