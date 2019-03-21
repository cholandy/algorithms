#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

// global
vector<vector<int>> node_edge;
vector<vector<int>> is_first_idx_parent;

int is_have_node(int _n, int _node_1, int _node_2) {
	vector<int> is_visited(_n + 1, 0);
	queue<int> bfs_queue; bfs_queue.push(_node_1);
	
	// 이미 노드가 자식 노드인 것을 파악했다면
	if(is_first_idx_parent[_node_1][_node_2]) return 1;

	while (!bfs_queue.empty()) {
		int now_node = bfs_queue.front(); bfs_queue.pop();
		// 찾는 노드면
		if (now_node == _node_2) return 1;

		// 방문한 노드면
		if (is_visited[now_node]) continue;
		is_visited[now_node] = 1; 

		// 연결된 노드 모두 넣기
		for (auto next_node : node_edge[now_node]){
			is_first_idx_parent[_node_1][next_node] = 1;
			is_first_idx_parent[now_node][next_node] = 1;
			bfs_queue.push(next_node);
		}
	}
	return 0;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	node_edge.resize(n + 1); is_first_idx_parent.resize(n+1);
	for (int idx = 0; idx < n + 1; idx++)
		is_first_idx_parent[idx] = vector<int>(n+1);
	for (int k_idx = 0; k_idx < k; k_idx++) {
		int before, after; scanf("%d %d", &before, &after);
		node_edge[before].push_back(after);
	}
	int s; scanf("%d", &s);
	for (int s_idx = 0; s_idx < s; s_idx++) {
		int node_1, node_2; scanf("%d %d", &node_1, &node_2);
		// 한 쪽에서 다른 한 쪽을 찾을 때 까지 자식을 계속 찾는다. 
		if (is_have_node(n, node_1, node_2)) printf("-1\n");
		else if (is_have_node(n, node_2, node_1)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}