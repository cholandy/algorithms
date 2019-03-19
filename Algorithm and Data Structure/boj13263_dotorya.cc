#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

#define ll __int128

typedef tuple<int, int, int> t3;
//typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 20;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-9;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

pll operator - (pll a, pll b) {
	return pll(a.first - b.first, a.second - b.second);
}
ll ccw(pll a, pll b) {
	return a.first*b.second - a.second*b.first;
}

ll A[100050];
ll B[100050];
ll dp[100050];
vector <pll> Vch;
int main() {
	int N, i;
	scanf("%d", &N);
	if (N == 1) return !printf("0\n");

	for (i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		A[i] = a;
	}
	for (i = 1; i <= N; i++) {
		int b;
		scanf("%d", &b);
		B[i] = b;
	}

	ll s = 0;
	for (i = 1; i <= N; i++) s += A[i] * B[N];
	for (i = 1; i <= N; i++) B[i] -= B[N];

	int p = 0;
	dp[1] = 0;
	Vch.emplace_back(B[1], 0);
	for (i = 2; i <= N; i++) {
		while (p + 1 < Vch.size()) {
			ll v1 = Vch[p].first * A[i] + Vch[p].second;
			ll v2 = Vch[p + 1].first * A[i] + Vch[p + 1].second;
			if (v1 > v2) p++;
			else break;
		}
		dp[i] = Vch[p].first * A[i] + Vch[p].second;

		pll u = pll(B[i], dp[i]);
		while (Vch.size() >= p + 2) {
			pll u1 = Vch[Vch.size() - 2];
			pll u2 = Vch.back();
			if (ccw(u - u1, u2 - u1) > 0) break;
			Vch.pop_back();
		}
		Vch.push_back(u);
	}

	__int128 ans = dp[N] + s;
	__int128 mo = 1;
	for (int i = 1; i <= 18; i++) mo *= 10;
	
	long long v1 = (long long)(ans / mo);
	long long v2 = (long long)(ans%mo);
	if (v1 != 0) {
		printf("%lld", v1);
		printf("%018lld", v2);
		return !printf("\n");
	}
	else printf("%lld\n", v2);
	return 0;
}