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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

int N, M, H;
bool chk[35][35];

int ans = INF;
void aa(int lvl, int cnt) {
	if (lvl == (N - 1)*H) {
		for (int i = 1; i <= N; i++) {
			int t = i;
			for (int j = 1; j <= H; j++) {
				if (chk[j][t - 1]) t--;
				else if (chk[j][t]) t++;
			}
			if (t != i) return;
		}
		ans = min(ans, cnt);
		return;
	}
	
	int x = lvl / (N - 1) + 1;
	int y = lvl % (N - 1) + 1;

	aa(lvl + 1, cnt);
	if (chk[x][y] || cnt == 3 || chk[x][y-1] || chk[x][y+1]) return;

	chk[x][y] = true;
	aa(lvl + 1, cnt + 1);
	chk[x][y] = false;
}
int main() {
	int i, j;
	scanf("%d %d %d", &N, &M, &H);
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		chk[t1][t2] = true;
	}

	aa(0, 0);
	if (ans == INF) ans = -1;
	return !printf("%d\n", ans);
}