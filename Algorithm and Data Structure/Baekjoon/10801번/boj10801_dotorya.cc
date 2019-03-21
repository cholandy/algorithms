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

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 2034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;

int in1[10];
int in2[10];
int main() {
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < 10; i++) scanf("%d", &in1[i]);
	for (int i = 0; i < 10; i++) scanf("%d", &in2[i]);
	for (int i = 0; i < 10; i++) {
		if (in1[i] > in2[i]) cnt1++;
		if (in1[i] < in2[i]) cnt2++;
	}
	if (cnt1 > cnt2) printf("A");
	if (cnt1 < cnt2) printf("B");
	if (cnt1 == cnt2) printf("D");
	return 0;
}
//*/

