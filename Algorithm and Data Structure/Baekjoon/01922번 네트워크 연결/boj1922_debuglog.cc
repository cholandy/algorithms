#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
​
int n, m;
priority_queue<tuple<int, int, int>> edges;
int parent[1001] = { 0, };
int r[1001] = { 0, };
int ans = 0;
​
void makeset(int v) {
    parent[v] = v;
    r[v] = 0;
}
​
int find(int v) {
    if (parent[v] == v) {
        return v;
    }
​
    return parent[v] = find(parent[v]);
}
​
void union_node(int a, int b) {
    int root_a = find(a);
    int root_b = find(b);
​
    if (r[root_a] < r[root_b]) {
        parent[root_a] = root_b;
    }
    else if (r[root_b] > r[root_b]) {
        parent[root_b] = root_a;
    }
    else {
        parent[root_b] = root_a;
        r[root_a]++;
    }
}
​
int main(void) {
    scanf("%d", &n);
    scanf("%d", &m);
​
    for (int i = 0; i < m; i++) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edges.push(make_tuple(-w, a, b));
    }
    
    for (int i = 1; i <= n; i++) {
        makeset(i);
    }
​
    while(!edges.empty()){
        auto edge = edges.top();
        
        int w = -get<0>(edge);
        int a = get<1>(edge);
        int b = get<2>(edge);
​
        if (find(a) != find(b)) {
            union_node(a, b);
            ans += w;
        }
​
        edges.pop();
    }
​
    printf("%d\n", ans);
​
    return 0;
}