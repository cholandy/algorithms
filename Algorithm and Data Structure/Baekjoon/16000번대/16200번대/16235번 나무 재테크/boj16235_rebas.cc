#include <cstdio>
#include <deque>
using namespace std;

int N, M, K, ans;
int a[10][10];
int nutrient[10][10];
deque<int> tree[10][10];
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring_summer() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            int &nt = nutrient[i][j];
            deque<int> &tr = tree[i][j];
            for (int k=0; k<(int)tr.size(); k++) {
                if (nt >= tr[k]) { // Spring
                    nt -= tr[k];
                    tr[k]++;
                } else { // Summer
                    while (k < (int)tr.size()) {
                        nt += (tr.back()/2);
                        tr.pop_back();
                        ans--;
                    }
                    break;
                }
            }
        }
    }
}

void fall_winter() {
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<(int)tree[i][j].size(); k++) {
                if (tree[i][j][k]%5 == 0) { // Fall
                    for (int t=0; t<8; t++) {
                        int x = i+dx[t], y = j+dy[t];
                        if (x < 0 || x >= N || y < 0 || y >= N) continue;
                        tree[x][y].push_front(1);
                        ans++;
                    }
                }
            }
            nutrient[i][j] += a[i][j]; // Winter
        }
    }
}

void solve() {
    while (K--) {
        spring_summer();
        fall_winter();
    }
    printf("%d\n", ans);
}

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d", &a[i][j]);
            nutrient[i][j] = 5;
        }
    }
    for (int i=0; i<M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        tree[x-1][y-1].push_back(z);
        ans++;
    }
    solve();
    return 0;
}


