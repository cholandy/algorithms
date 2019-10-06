#include <bits/stdc++.h>

using namespace std;

struct data{
    int x, y;
    bool operator< (const data &r) const{
        if (y!=r.y) return y < r.y;
        return x < r.x;
    }
} arr[100050];

int N;
long long sum;

int main ()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d", &N);
    for (int i=1; i<=N; i++) scanf("%d %d", &arr[i].x, &arr[i].y);
    sort(arr+1, arr+N+1);
    for (int i=1; i<=N; ++i) {
        if (arr[i].y != arr[i-1].y && arr[i].y != arr[i+1].y) continue;
        if (arr[i].y != arr[i-1].y) sum += arr[i+1].x - arr[i].x;
        else if (arr[i].y != arr[i+1].y) sum += arr[i].x - arr[i-1].x;
        else sum += min(arr[i+1].x - arr[i].x, arr[i].x - arr[i-1].x);
    }
    printf("%lld", sum);
    return 0;
}