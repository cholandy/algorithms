#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <cmath>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
const ll MOD = 1e9 + 7;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v; queue<int> q; deque<int> dq;

pii vec[1000];
int dp[1000][16][16];
int n = 0;

int go(int o, int w, int b) {
	if (w > 15 || b > 15) return -1e9;
	if (w == 15 && b == 15) return 0;
	if (o == n) return 0;
	if (dp[o][w][b] != -1) return dp[o][w][b];

	int mav = -1e9;
	mav = max(mav, go(o + 1, w + 1, b) + vec[o].first);
	mav = max(mav, go(o + 1, w, b + 1) + vec[o].second);
	mav = max(mav, go(o + 1, w, b));

	return dp[o][w][b] = mav;
}

int main() {
	while (scanf("%d %d", &vec[n].first, &vec[n].second) != EOF) { n++; }
	memset(dp, -1, sizeof(dp));

	printf("%d", go(0, 0, 0));
}