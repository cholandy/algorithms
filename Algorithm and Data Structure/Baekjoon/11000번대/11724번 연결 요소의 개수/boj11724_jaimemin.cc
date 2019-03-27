#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000 + 1;

int n, m;
vector<int> graph[MAX];
bool visited[MAX];


void DFS(int idx)
{
	visited[idx] = true;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];
		if (!visited[next]) DFS(next);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			DFS(i);
			cnt++;
		}
	}

	cout << cnt;

}
