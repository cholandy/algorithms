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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 17;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}
int main() {
	ll N, M, T, i, j;
	vector<pair<ll, pll>> Ve;
	scanf("%lld %lld %lld", &N, &M, &T);
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Ve.emplace_back(t3, pii(t2, t1));
	}

	sort(all(Ve));
	for (i = 1; i <= N; i++) r[i] = i;

	ll ans = (N - 1) * (N - 2) / 2 * T;
	for (auto it : Ve) {
		int x = it.second.first, y = it.second.second;
		if (root(x) == root(y)) continue;
		r[root(x)] = root(y);
		ans += it.first;
	}
	return !printf("%lld\n", ans);
}