#include <iostream>
#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef pair<int, pair<int, int> > pii;
 
int truck[10002];
pii arr[10002];
 
int main()
{
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);
 
    for (int i = 0; i < m; i++)
    {
        int from, to, val;
        scanf("%d %d %d", &from, &to, &val);
 
        arr[i].first = to;
        arr[i].second.first = from;
        arr[i].second.second = val;
    }
 
    // to를 기준으로 정렬
    sort(arr, arr + m);
 
    long long ans = 0;
 
    for (int i = 0; i < m; i++)
    {
        int get = 0;
        int from = arr[i].second.first;
        int to = arr[i].first;
        int val = arr[i].second.second;
 
        // 트럭이 적재하고 있는 최댓값을 구한다.
        for (int j = from; j < to; j++)
            get = max(get, truck[j]);
 
        // 트럭에 실을 수 있는 최솟값을 구한다.
        get = min(c - get, val);
        ans += get;
 
        // 트럭에 누적 적재 합을 더해준다.
        for (int j = from; j < to; j++)
            truck[j] += get;
    }
 
    printf("%lld", ans);
 
    return 0;
}
