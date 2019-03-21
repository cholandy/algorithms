//*
#include <algorithm>
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

#define pow10 pasiodfiopsdjviozjxciovjxcviozj
#define pow2 qpowdskopjkcoizxnzoicn

#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
typedef pair <db, int> pdi;

int IT_MAX;
const int MOD = 1000000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

class data {
public:
	char v[35];
	int c, p;
	data() {
		c = -1, p = INF;
		for (int i = 0; i < 35; i++) v[i] = 0;
	}
	bool operator < (const data &l) const {
		if (c != l.c) return c < l.c;
		else return p > l.p;
	}
};

map <string, int> M;
data mx[100050];
char tx[35];
int main() {
	int N, K, mc = 0, i;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) {
		data u = data();
		scanf("%s %s %d %d", tx, u.v, &u.c, &u.p);
		string u2 = string(tx);
		if (!M.count(u2)) M[u2] = ++mc;
		if (mx[M[u2]] < u) mx[M[u2]] = u;
	}

	sort(mx + 1, mx + mc + 1);
	for (i = mc; i > mc - K; i--) printf("%s\n", mx[i].v);
	return 0;
}
//*/