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

const int IT_MAX = 256;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;

int cnt[205];
int main() {
	int N, i, t;
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		cnt[t + 100]++;
	}
	scanf("%d", &t);
	printf("%d", cnt[t + 100]);
	return 0;
}
//*/