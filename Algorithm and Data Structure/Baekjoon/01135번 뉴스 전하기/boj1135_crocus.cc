#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
using namespace std;
 
typedef pair<int, int> pii;
 
vector<pii> vc[52];
 
bool comp(const pii &a, const pii &b)
{
    return a.first > b.first;
}
 
int dfs(int here)
{
    int ret = 0;
 
    // 현재 사람이 부하에게 전화하는데 걸리는 시간
    for (int i = 0; i < vc[here].size(); i++)
    {
        int next = vc[here][i].second;
        vc[here][i].first = 1 + dfs(next);
    }
 
    // 부하에게 전화하는데 가장 오래 걸리는 순으로 정렬
    sort(vc[here].begin(), vc[here].end(), comp);
 
    // 정렬된 순서대로 전화할때
    for (int i = 0; i < vc[here].size(); i++)
    {
        vc[here][i].first += i;
        ret = max(ret, vc[here][i].first);
    }
 
    return ret;
}
 
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
 
        if (val == -1)
            continue;
 
        vc[val].push_back({ 0,i });
    }
 
    printf("%d", dfs(0));
 
    return 0;
}
 