#include <bits/stdc++.h>
using namespace std;
int perm[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3};
int N, a[15], ans;
 
int main(){
    N = 12;
    for(int i = 0; i < N; i++)
        scanf("%d", a + i);
    ans = 1e9;
    do{
        int s[4] = {0,};
        int mn = 1e9, mx = -1e9;
        for(int i = 0; i < N; i++)
            s[perm[i]] += a[i];
        for(int i = 0; i < 4; i++){
            mx = max(mx, s[i]);
            mn = min(mn, s[i]); 
        }
        ans = min(ans, mx - mn);
    }while(next_permutation(perm, perm + 12));
    printf("%d\n", ans);
    return 0;
}

