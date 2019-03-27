#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
 
    int num, cnt;
    cin >> num >> cnt;
    vector<vector<int> > arr(num + 1, vector<int>());
    vector<int> degree(num + 1, 0);
    queue<int> qq;
 
    int a, b;
    for (int i = 0; i < cnt; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        degree[b]++;
    }
    for (int i = 1; i <= num; i++)
        if (degree[i] == 0)
            qq.push(i);
 
    while (!qq.empty()) {
        int node = qq.front();
        qq.pop();
        cout << node << " ";
        for (int i = 0; i < arr[node].size(); i++) {
            int nn = arr[node][i];
            degree[nn]--;
            if (degree[nn] == 0) qq.push(nn);
        }
    }
    return 0;
}
