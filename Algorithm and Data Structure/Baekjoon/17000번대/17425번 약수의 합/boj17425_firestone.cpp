#include <bits/stdc++.h>

using namespace std;

long long arr[1000001] = {0,};

int main() {
    // cin.tie(NULL); 
    // ios_base::sync_with_stdio(false);
    int tc, n;
    scanf("%d", &tc);
    for (int i=1;i<1000001;++i) {
        for (int j=1; j<=(1000000/i); ++j) {
            arr[i*j] += j;
        }
        arr[i] += arr[i-1];
    }

    for (int i=0; i<tc; ++i) {
        scanf("%d", &n);
        printf("%lld\n", arr[n]);
    }
    return 0;
}
