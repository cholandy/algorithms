//*
#include <algorithm>
#include <iostream>
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
#include <string>
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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 262144;
const int MOD = 1000000;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int cnt[205];
int dp[205][4005];
int main() {
	int T, A, S, B, t, i, j, k;
	scanf("%d %d %d %d", &T, &A, &S, &B);
	for (i = 1; i <= A; i++) {
		scanf("%d", &t);
		cnt[t]++;
	}

	dp[0][0] = 1;
	for (i = 1; i <= T; i++) {
		for (j = 0; j <= B; j++) {
			for (k = j; k >= 0 && j - k <= cnt[i]; k--) dp[i][j] += dp[i - 1][k];
			dp[i][j] %= MOD;
		}
	}

	int ans = 0;
	for (i = S; i <= B; i++) ans += dp[T][i];
	printf("%d", ans%MOD);
	return 0;
}
//*/