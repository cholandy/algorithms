#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main() {
 
    int n, p1, p2, m;
    cin >> n >> p1 >> p2 >> m;
 
    int x, y;
    vector<int> vec[101];
    vector<int> visited(101, 0);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
 
    queue<int> q;
    q.push(p1);
    while (!q.empty()) {
        int p = q.front();
        q.pop();
 
        if (p == p2) {
            break;
        }
 
        for (int i = 0; i < vec[p].size(); i++) {
            if (!visited[vec[p][i]]) {
                visited[vec[p][i]] = visited[p] + 1;
                q.push(vec[p][i]);
            }
        }
    }
 
    if (visited[p2] != 0)
        cout << visited[p2] << endl;
    else
        cout << -1 << endl;
}
