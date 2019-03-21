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
const int MOD = 9901;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

char in[25][25];
int P[4][2] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
int main() {
	int N, M;
	for (int tc = 1; scanf("%d %d", &M, &N) != EOF; tc++) {
		if (M == 0 && N == 0) break;
		int i, j;
		int x, y, d;
		for (i = 0; i < N; i++) {
			scanf("%s", in[i]);
			for (j = 0; j < M; j++) {
				if (in[i][j] == '*') {
					x = i;
					y = j;
				}
			}
		}
		if (x == 0) d = 3;
		else if (x == N - 1) d = 1;
		else if (y == 0) d = 2;
		else d = 0;

		while (in[x][y] != 'x') {
			x += P[d][0];
			y += P[d][1];
			if (in[x][y] == '/') d ^= 3;
			if (in[x][y] == '\\') d ^= 1;
		}

		in[x][y] = '&';
		printf("HOUSE %d\n", tc);
		for (i = 0; i < N; i++) printf("%s\n", in[i]);
	}
	return 0;
}
//*/