//*
#include <algorithm>
#include <ctype.h>
#include <functional>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
  
#pragma warning(disable:4996)
using namespace std;
  
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef pair <char, int> pci;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
  
int IT_MAX;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
  
int dp[1 << 16][16];
int in[16][16];
  
int main() {
    int N, i, j, k;
    scanf("%d", &N);
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) scanf("%d", &in[i][j]);
      
    for (i = 0; i < (1<<N); i++) for (j = 0; j < N; j++) dp[i][j] = INF;
    dp[1][0] = 0;
    for (i = 1; i < (1 << N) - 1; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                if (i & (1 << k)) continue;
                if(in[j][k] != 0) dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + in[j][k]);
            }
        }
    }
  
    int ans = INF;
    for (i = 1; i < N; i++) if(in[i][0]) ans = min(ans, dp[(1 << N) - 1][i] + in[i][0]);
    printf("%d", ans);
    return 0;
}