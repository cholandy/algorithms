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

char u[15];
set <string> Sx;
vector <string> Vl;

char in[5][5];
bool dchk[5][5];
string cur;
void aa(int x, int y) {
	if (Sx.count(cur)) {
		Vl.push_back(cur);
		Sx.erase(cur);
	}
	if (cur.size() == 8) return;

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if (i < 0 || i > 3 || j < 0 || j > 3) continue;
			if (dchk[i][j]) continue;

			cur += in[i][j];
			dchk[i][j] = true;
			aa(i, j);
			dchk[i][j] = false;
			cur.pop_back();
		}
	}
}

int main() {
	int N, i, j;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", u);
		Sx.emplace(u);
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 4; i++) scanf("%s", in[i]);

		for (i = 0; i < 4; i++) {
			for (j = 0; j < 4; j++) {
				dchk[i][j] = true;
				cur += in[i][j];
				aa(i, j);
				cur = "";
				dchk[i][j] = false;
			}
		}

		int s = 0;
		string mx = "";
		for (auto it : Vl) {
			if (it.size() == 3 || it.size() == 4) s++;
			if (it.size() == 5) s += 2;
			if (it.size() == 6) s += 3;
			if (it.size() == 7) s += 5;
			if (it.size() == 8) s += 11;

			if (mx.size() < it.size() || (mx.size() == it.size() && mx > it)) mx = it;
		}
		printf("%d %s %d\n", s, mx.c_str(), (int)Vl.size());

		for (auto it : Vl) Sx.insert(it);
		Vl.clear();
	}
	return 0;
}