#include <iostream>
#include <string>
#include <queue>
using namespace std;
 
struct Node {
    int n;
    string str;
    Node(int n,string str) :n(n),str(str) {}
};
 
int t;
string res;
 
int funcD(int n) {
    return (n * 2 > 9999) ? (n * 2) % 10000 : 2 * n;
}
int funcS(int n) {
    return (n == 0) ? 9999 : n - 1;
}
int funcL(int n) {
    int ans = n / 1000;
    n -= (ans * 1000);
    n *= 10;
    ans += n;
    return ans;
}
int funcR(int n) {
    int ans = (n % 10) * 1000;
    n /= 10;
    ans += n;
    return ans;
}
 
void bfs(int a,int b) {
    queue<Node> q;
    q.push(Node(a,""));
    bool visited[10000] = { false, };
 
    visited[a] = true;
 
    while (!q.empty()) {
        int n = q.front().n;
        string str = q.front().str;
        q.pop();
 
        if (n == b) {
            res += str + "\n";
            return;
        }
        
        int next;
        next = funcD(n);
        if (!visited[next])q.push(Node(next, str + "D"));
        visited[next]=true;
        next = funcS(n);
        if (!visited[next])q.push(Node(next, str + "S"));
        visited[next] = true;
        next = funcL(n);
        if (!visited[next])q.push(Node(next, str + "L"));
        visited[next] = true;
        next = funcR(n);
        if (!visited[next])q.push(Node(next, str + "R"));
        visited[next] = true;
    }
}
 
int main(){ 
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
    cout << res;
}