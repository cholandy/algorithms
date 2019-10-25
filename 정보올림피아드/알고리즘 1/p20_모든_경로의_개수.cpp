#include <iostream>

using namespace std;

int n, cnt;
int a[5][5];
void DFS(int y, int x) {
    if (y==n-1 && x==n-1) {
        cnt++;
        return;
    }
    a[y][x] = 0;

    if (y > 0 && a[y-1][x] == 1) DFS(y-1, x);
    if (y < n-1 && a[y+1][x] == 1) DFS(y+1, x);
    if (x > 0 && a[y][x-1] == 1) DFS(y, x-1);
    if (x < n-1 && a[y][x+1] == 1) DFS(y, x+1);

    a[y][x] = 1;
}

int main()
{
    cin >> n;
    int i, j;
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            cin >> a[i][j];
        }
    }

    DFS(0,0);
    cout << cnt << endl;
    return 0;
}