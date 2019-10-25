#include <iostream>

using namespace std;

int n, cnt, mins = 25;
int a[5][5];

void DFS(int y, int x, int cnt) {
    if (mins < cnt) return;
    if (y==n-1 && x==n-1) {
        if (mins > cnt) {
            mins = cnt;
            return;
        }
        else return;
    }
    
    a[y][x] = 0;

    if (y > 0 && a[y-1][x] == 1) DFS(y-1, x, cnt+1);
    if (y < n-1 && a[y+1][x] == 1) DFS(y+1, x, cnt+1);
    if (x > 0 && a[y][x-1] == 1) DFS(y, x-1, cnt+1);
    if (x < n-1 && a[y][x+1] == 1) DFS(y, x+1, cnt+1);

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

    DFS(0,0,1);
    cout << mins << endl;
    return 0;
}