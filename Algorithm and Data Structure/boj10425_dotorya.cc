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
#include <unordered_set>
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
const int MOD = 1000000000;
const int INF = 1034567891;
const ll LL_INF = 2234567890123456789ll;
const db PI = 3.141592653589793238;

char in[22000];
int F[100];
int main() {
	int T;
	int i, j;
	F[0] = 0, F[1] = 1;
	for (i = 2; F[i - 1] <= INF; i++) F[i] = F[i - 1] + F[i - 2];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", in);
		int L = strlen(in);

		if (L <= 3) {
			int v = 0, ans;
			for (i = 0; in[i] != 0; i++) v = (10 * v + in[i] - '0');
			for (i = 0; F[i] <= v; i++) if (F[i] == v) ans = i;
			printf("%d\n", ans);
			continue;
		}

		ldb v = (in[0] - '0') + (in[1] - '0')*0.1 + (in[2] - '0')*0.01;
		ldb x = L - 1 + log10(v) + log10(5) / 2;
		x /= log10((1 + sqrt(5)) / 2);
		db ans = (db)x;
		printf("%.0lf\n", ans);
	}
	return 0;
}
//*/