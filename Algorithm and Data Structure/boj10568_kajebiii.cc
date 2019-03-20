#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

int P, W, Q;
typedef tuple<int, int, int> ti;
typedef pair<string, string> ps;
int main() {
	int TC; cin >> TC;
	for(int tc=1; tc<=TC; tc++) {
		scanf("%d", &P);
		vector<string> list;
		map<string, ti> Ps;
		for(int i=0; i<P; i++) {
			char temp[99]; int x, y, z; scanf("%s%d%d%d", temp, &x, &y, &z);
			Ps[temp] = ti(x, y, z);
			list.push_back(temp);
		}
		map<ps, double> dis;
		for(string &a : list) for(string &b : list) {
			int ax, ay, az, bx, by, bz; tie(ax, ay, az) = Ps[a], tie(bx, by, bz) = Ps[b];
			ll dx = ax - bx, dy = ay - by, dz = az - bz;
			dis[ps(a, b)] = sqrt(dx * dx + dy * dy + dz * dz);
		}
		scanf("%d", &W);
		for(int i=0; i<W; i++) {
			char temp[2][99]; scanf("%s%s", temp[0], temp[1]);
			dis[ps(temp[0], temp[1])] = 0;
		}
		for(string &k : list) for(string &i : list) for(string &j : list)
			dis[ps(i, j)] = min(dis[ps(i, j)], dis[ps(i, k)] + dis[ps(k, j)]);
		scanf("%d", &Q);
		printf("Case %d:\n", tc);
		for(int i=0; i<Q; i++) {
			char temp[2][99]; scanf("%s%s", temp[0], temp[1]);
			printf("The distance from %s to %s is %.0f parsecs.\n", temp[0], temp[1], dis[ps(temp[0], temp[1])]);
		}
	}
	return 0;
}
