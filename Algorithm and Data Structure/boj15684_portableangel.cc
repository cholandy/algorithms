#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ip;

bool h[31][11];
int n, w;

bool pos() {
	int p[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < w; j++) {
			if (h[i][j]) swap(p[j], p[j + 1]);
		}
	}
	for (int i = 1; i <= w; i++) {
		if (p[i] != i) return false;
	}
	return true;
}

int main() {
	int m;
	scanf("%d %d %d", &w, &m, &n);
	while (m--) {
		int r, c;
		scanf("%d %d", &r, &c);
		h[r][c] = true;
	}
	vector<ip> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < w; j++) {
			if (!h[i][j] && !h[i][j - 1] && !h[i][j + 1]) v.push_back(ip(i, j));
		}
	}
	if (pos()) {
		puts("0");
		return 0;
	}
	for (int i = 0; i < v.size(); i++) {
		h[v[i].first][v[i].second] = true;
		if (pos()) {
			puts("1");
			return 0;
		}
		h[v[i].first][v[i].second] = false;
	}
	for (int i = 0; i < v.size(); i++) {
		h[v[i].first][v[i].second] = true;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].first == v[j].first && v[i].second + 1 == v[j].second) continue;
			h[v[j].first][v[j].second] = true;
			if (pos()) {
				puts("2");
				return 0;
			}
			h[v[j].first][v[j].second] = false;
		}
		h[v[i].first][v[i].second] = false;
	}
	for (int i = 0; i < v.size(); i++) {
		h[v[i].first][v[i].second] = true;
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i].first == v[j].first && v[i].second + 1 == v[j].second) continue;
			h[v[j].first][v[j].second] = true;
			for (int k = j + 1; k < v.size(); k++) {
				if (v[j].first == v[k].first && v[j].second + 1 == v[k].second) continue;
				h[v[k].first][v[k].second] = true;
				if (pos()) {
					puts("3");
					return 0;
				}
				h[v[k].first][v[k].second] = false;
			}
			h[v[j].first][v[j].second] = false;
		}
		h[v[i].first][v[i].second] = false;
	}
	puts("-1");
	return 0;
}