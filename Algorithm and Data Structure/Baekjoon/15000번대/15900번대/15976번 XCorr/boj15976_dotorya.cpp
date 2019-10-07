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

vector <pll> Vl[2];
int main() {
	int i, j;
	for (i = 0; i < 2; i++) {
		int N;
		scanf("%d", &N);
		for (j = 0; j < N; j++) {
			ll t1, t2;
			scanf("%lld %lld", &t1, &t2);
			if (i == 1 && !Vl[i].empty()) t2 += Vl[i].back().second;
			Vl[i].emplace_back(t1, t2);
		}
	}

	ll ans = 0;
	ll A, B;
	scanf("%lld %lld", &A, &B);
	for (auto it : Vl[0]) {
		int p1 = lower_bound(all(Vl[1]), pll(it.first + A, -INF)) - Vl[1].begin();
		int p2 = lower_bound(all(Vl[1]), pll(it.first + B + 1, -INF)) - Vl[1].begin();

		ll s = 0;
		if (p1 != 0) s -= Vl[1][p1 - 1].second;
		if (p2 != 0) s += Vl[1][p2 - 1].second;
		ans += s * it.second;
	}
	return !printf("%lld\n", ans);
}