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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 131072;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

set <int> out[12];
int po10[10] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
int main() {
	int N, K, L, i, j, k, l, tmp;
	scanf("%d %d", &N, &K);
	out[0].insert(N);
	
	tmp = N;
	for (L = 0; tmp != 0; L++, tmp /= 10);
	for (i = 0; i < K; i++) {
		set <int>::iterator it;
		for (it = out[i].begin(); it != out[i].end(); it++) {
			int x = *it;
			int* t = new int[L];
			for (j = 0; j < L; j++, x /= 10) t[j] = x % 10;
			for (j = 0; j < L; j++) {
				for (k = j + 1; k < L; k++) {
					if (k == L - 1 && t[j] == 0) continue;
					int x2 = *it + (t[j] - t[k])*(po10[k] - po10[j]);
					out[i + 1].insert(x2);
				}
			}
			free(t);
		}
	}
	if (out[K].size() == 0) printf("-1");
	else {
		set <int>::iterator it;
		it = out[K].end();
		it--;
		printf("%d", *it);
	}
	return 0;
}
//*/

