#include <cstdio>
#include <vector>
using namespace std;

int n, x, y, d, g, ans;
vector<int> v;
bool a[101][101];
const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

// Make all dragon curve (~10th generation)
void dragon() {
    v.push_back(0);
    for (int i=1; i<=10; i++) {
        int k = 1<<(i-1);
        for (int j=0; j<k; j++) {
            v.push_back((v[k-j-1]+1)%4);
        }
    }
}

// Draw dragon curves by input.
void solve() {
    a[x][y] = true;
    for (int i=0; i<(1<<g); i++) {
        x += dx[(v[i]+d)%4], y += dy[(v[i]+d)%4];
        a[x][y] = true;
    }
}

// Count squares.
void count() {
    for (int i=0; i<100; i++) {
        for (int j=0; j<100; j++) {
            if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) ans++;
        }
    }
}

int main() {
    dragon();
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d", &x, &y, &d, &g);
        solve();
    }
    count();
    printf("%d\n", ans);
    return 0;
}


