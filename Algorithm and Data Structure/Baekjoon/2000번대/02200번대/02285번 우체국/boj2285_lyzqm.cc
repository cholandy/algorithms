#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

typedef long long ll;

int n;

pair<int, int> arr[MAXN];

int main() {

    scanf("%d", &n);

    ll sum = 0, s = 0;

    for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].first, &arr[i].second), sum += arr[i].second;

    sort(arr, arr + n);

    for (int i = 0; i < n; i++) {

        s += arr[i].second;

        if (s * 2ll >= sum) {

            printf("%d\n", arr[i].first);

            break;

        }

    }

    return 0;

}
