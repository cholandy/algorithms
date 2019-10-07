#include <bits/stdc++.h>
using namespace std;

const int n_ = 1e3 + 3;

int req[n_], dst[n_], idg[n_], ans[n_];
vector<int> gph[n_];

//
char buf[1<<16],*p=buf+(1<<16);
inline char G(){if(p==buf+(1<<16))fread(p=buf,1,1<<16,stdin);return *p++;}
inline int I(){int t,r=G()&15;while((t=G())>40)r=r*10+(t&15);return r;}
//

void dfs(int now) {
	idg[now]--;
	for (int nxt : gph[now]) {
		ans[nxt] = max(ans[nxt], ans[now] + req[nxt]);
		if (!(--idg[nxt])) {
			dfs(nxt);
		}
	}
}

int main() {
	int tc = I();

	while (tc--) {
		int n, k, w;
		n = I(), k = I();

		for (int i = 0; i <= n; i++) gph[i].clear();
		memset(req, 0, sizeof(req));
		memset(idg, 0, sizeof(idg));
		memset(ans, 0, sizeof(ans));
		
		for (int i = 1; i <= n; i++) {
			req[i] = I();
		}
		for (int i = 0; i < k; i++) {
			int u = I(), v = I();
			gph[u].push_back(v);
			idg[v]++;
		}
		w = I();

		for (int i = 1; i <= n; i++) {
			if (!idg[i]) {
				ans[i] = req[i];
				dfs(i);
			}
		}

		printf("%d\n", ans[w]);
	}

	return 0;
}