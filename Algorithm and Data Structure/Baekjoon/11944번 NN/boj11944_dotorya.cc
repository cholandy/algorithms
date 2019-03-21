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
const int INF = 2034567891;
const ll LL_INF = 8234567890123456789ll;
const db PI = acos(-1);
const ldb ERR = 1E-8;

char in[10];
vector <char> ans;
int main() {
	int N = 0, M, i;
	scanf("%s %d", in, &M);
	int L = strlen(in);
	for (i = 0; i < L; i++) N = 10 * N + in[i] - '0';

	M = min(M, N*L);
	
	int p = 0;
	for (i = 1; i <= M; i++) {
		ans.push_back(in[p]);
		p = (p + 1) % L;
	}
	for (auto it : ans) printf("%c", it);
	printf("\n");
	return 0;
}