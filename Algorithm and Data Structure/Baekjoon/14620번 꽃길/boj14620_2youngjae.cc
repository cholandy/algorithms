#include <iostream>
#include <algorithm>
using namespace std;
 
int n, res;
int map[10][10];
int d[10][10];
bool visited[10][10];
int filter_x[] = { -1,0,0,0,1 };
int filter_y[] = { 0,1,0,-1,0 };
 
bool isOK(int x,int y) {
    for (int i = 0; i < 5; i++) {
        if (visited[x + filter_x[i]][y + filter_y[i]]) return false;
    }
    return true;
}
 
int get_price(int x, int y) {
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        int ax = x + filter_x[i];
        int ay = y + filter_y[i];
        ans += map[ax][ay];
    }
    return ans;
}
 
void dfs(int x, int y,int cnt, int val) {
    
    if (cnt == 3) {
        res = min(res, val);
    }
    else {
        for (int i = 0; i < 5; i++) {
            visited[x + filter_x[i]][y + filter_y[i]] = true;
        }
 
        //같은라인
        for (int i = y + 3; i < n - 1; i++) {
            if (isOK(x, i)) dfs(x, i, cnt + 1, val + d[x][i]);
        }
        //다음라인
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (isOK(i, j)) dfs(i, j, cnt + 1, val + d[i][j]);
            }
        }
 
        for (int i = 0; i < 5; i++) {
            visited[x + filter_x[i]][y + filter_y[i]] = false;
        }
    }
}
//디버깅용
void printAll() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    res = 987654321;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
 
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            d[i][j] = get_price(i, j);
        }
    }
 
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            dfs(i, j, 1, d[i][j]);
        }
    }
 
    cout << res << endl;
}
