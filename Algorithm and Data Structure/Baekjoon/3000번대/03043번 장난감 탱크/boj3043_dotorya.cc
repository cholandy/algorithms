#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 1034567890;
const ll LL_INF = 1234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-16;

pii in[505];

pii u1[505];
int x[505];
pii u2[505];
int y[505];
int pos[505][505];
int main() {
	int N, i, j, k;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d %d", &in[i].first, &in[i].second);
		u1[i] = pii(in[i].first, i);
		u2[i] = pii(in[i].second, i);
	}
	sort(u1 + 1, u1 + N + 1);
	sort(u2 + 1, u2 + N + 1);
	int ans = 0;
	for (i = 1; i <= N; i++) {
		x[u1[i].second] = i;
		y[u2[i].second] = i;
		ans += abs(i - in[u1[i].second].first);
		ans += abs(i - in[u2[i].second].second);
	}

	printf("%d\n", ans);

	for (i = 1; i <= N; i++) pos[in[i].first][in[i].second] = i;
	for (i = 1; i <= N; i++) {
		int t = u1[i].second;
		while (in[t].first > i) {
			for (j = in[t].first - 1; pos[j][in[t].second] != 0; j--);
			for (k = j + 1; k <= in[t].first; k++) {
				int t2 = pos[k][in[t].second];
				in[t2].first--;
				ans--;
				printf("%d U\n", t2);
				pos[k][in[t].second] = 0;
				pos[k - 1][in[t].second] = t2;
			}
		}
		while (in[t].first < i) {
			for (j = in[t].first + 1; pos[j][in[t].second] != 0; j++);
			for (k = j - 1; k >= in[t].first; k--) {
				int t2 = pos[k][in[t].second];
				in[t2].first++;
				ans--;
				printf("%d D\n", t2);
				pos[k][in[t].second] = 0;
				pos[k + 1][in[t].second] = t2;
			}
		}
	}

	for (i = 1; i <= N; i++) {
		int t = u2[i].second;
		if (in[t].second > i) for (j = 1; j <= in[t].second - i; j++) printf("%d L\n", t);
		else for (j = 1; j <= i - in[t].second; j++) printf("%d R\n", t);
		ans -= abs(i - in[t].second);
	}
	return 0;
}