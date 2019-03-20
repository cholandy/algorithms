#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 1e5 + 10;

int N, M, K;
vector<pi> Ed[MAX_N];
vector<int> sp[MAX_N]; int inD[MAX_N];
int main() {
	cin >> N >> M >> K;
	REP(i, K) {int x; scanf("%d", &x);}
	REP(i, M) {
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		Ed[x].push_back(pi(y, c));
		Ed[y].push_back(pi(x, c));
	}
	vector<int> dis = vector<int>(N+1, INF);
	vector<bool> vis = vector<bool>(N+1, false);
	priority_queue<pi, vector<pi>, greater<pi>> Q;
	Q.push(pi(0, 1)); dis[1] = 0;
	while(!Q.empty()) {
		int d, v; tie(d, v) = Q.top(); Q.pop();
		if(vis[v]) continue; vis[v] = true;
		for(pi &e : Ed[v]) {
			int w, c; tie(w, c) = e;
			if(d + c < dis[w]) Q.push(pi(dis[w] = d+c, w));
		}
	}
	for(int i=1; i<=N; i++) for(pi &e : Ed[i]) {
		int w, c; tie(w, c) = e;
		if(dis[i] + c == dis[w]) sp[i].push_back(w), inD[w]++;
	}
	vector<int> dy = vector<int>(N+1, 0);
	dy[1] = 1;
	queue<int> q; q.push(1);
	while(!q.empty()) {
		int v = q.front(); q.pop();
		for(int w : sp[v]) {
			dy[w] = min(2, dy[w] + dy[v]);
			if(--inD[w] == 0) q.push(w);
		}
	}
	if(dy[N] >= 2) puts("yes"); else puts("no");
	return 0;
}