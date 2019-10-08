#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
const ll MOD = 1e9 + 7;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

char s[7][500];
char ans[7][500];
int rotn[10] = { 10, 6, 14, 9, 11, 13, 12, 8, 16, 15 };
int num[10][7][6];

int main() {
	for (int i = 0; i < 7; i++)
		scanf("%s", s[i]);
	int len = strlen(s[0]);
	int n = len / 6;

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < 7; j++)
			for (int k = 0; k < 6; k++)
				if (s[j][k + i * 6] == '1') cnt++;

		for (int j = 0; j < 10; j++)
			if (cnt == rotn[j]) {
				v.push_back(j);
				for (int k = 0; k < 7; k++)
					for (int kk = 0; kk < 6; kk++)
						num[j][k][kk] = s[k][kk + i * 6];
			}
	}

	int t = next_permutation(all(v));
	if (t == 0) printf("The End");
	else {
		for (int i = 0; i < sz(v); i++) {
			for (int j = 0; j < 7; j++)
				for (int k = 0; k < 6; k++)
					ans[j][i * 6 + k] = num[v[i]][j][k];
		}

		for (int i = 0; i < 7; i++)
			printf("%s\n", ans[i]);
	}
}