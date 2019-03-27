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
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

char DB1[10] = "UDFBLR";
int DB2[6][12] = {
{38, 37, 36, 29, 28, 27, 20, 19, 18, 11, 10, 9},
{15, 16, 17, 24, 25, 26, 33, 34, 35, 42, 43, 44},
{6, 7, 8, 18, 21, 24, 47, 46, 45, 44, 41, 38},
{2, 1, 0, 36, 39, 42, 51, 52, 53, 26, 23, 20},
{0, 3, 6, 9, 12, 15, 45, 48, 51, 35, 32, 29},
{8, 5, 2, 27, 30, 33, 53, 50, 47, 17, 14, 11}
};

int DB3[6][8] = {
{0, 1, 2, 5, 8, 7, 6, 3},
{45, 46, 47, 50, 53, 52, 51, 48},
{9, 10, 11, 14, 17, 16, 15, 12},
{27, 28, 29, 32, 35, 34, 33, 30},
{36, 37, 38, 41, 44, 43, 42, 39},
{18, 19, 20, 23, 26, 25, 24, 21}
};

char ans[60];
char u[60];
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, i, j;

		for (i = 0; i < 9; i++) ans[i] = 'w';
		for (i = 9; i < 18; i++) ans[i] = 'r';
		for (i = 18; i < 27; i++) ans[i] = 'b';
		for (i = 27; i < 36; i++) ans[i] = 'o';
		for (i = 36; i < 45; i++) ans[i] = 'g';
		for (i = 45; i < 54; i++) ans[i] = 'y';

		scanf("%d", &N);
		while (N--) {
			char c[3];
			scanf("%s", c);

			int p = 9;
			if (c[1] == '-') p = 3;
			int x = 0;
			for (i = 0; i < 6; i++) if (DB1[i] == c[0]) x = i;

			for (i = 0; i < 54; i++) u[i] = ans[i];
			for (i = 0; i < 12; i++) u[DB2[x][i]] = ans[DB2[x][(i + p) % 12]];
			
			p = 6;
			if (c[1] == '-') p = 2;
			for (i = 0; i < 8; i++) u[DB3[x][i]] = ans[DB3[x][(i + p) % 8]];
			for (i = 0; i < 54; i++) ans[i] = u[i];

			
		}
		for (i = 0; i < 9; i++) {
			printf("%c", ans[i]);
			if (i % 3 == 2) printf("\n");
		}
	}
	return 0;
}