#include <iostream>

using namespace std;

int n, cnt;
int a[5][5];
int y[25], x[25], l[25];

void push(int xx, int yy, int ll) 
{
    x[cnt] = xx;
    y[cnt] = yy;
    l[cnt] = ll;
    cnt++;
}

void BFS()
{
    int pos;
    y[0] = 0;
    x[0] = 0;
    l[0] = 1;
    pos = 0;
    cnt = 1;

    while (pos < cnt && (x[pos] != n-1 || y[pos] != n-1)) {
        a[y[pos]][x[pos]] = 0;
        if (y[pos] > 0 && a[y[pos]-1][x[pos]] == 1) push(x[pos], y[pos]-1, l[pos]+1);
        if (y[pos] < n-1 && a[y[pos]+1][x[pos]] == 1) push(x[pos], y[pos]+1, l[pos]+1);
        if (x[pos] > 0 && a[y[pos]][x[pos]-1] == 1) push(x[pos]-1, y[pos], l[pos]+1);
        if (x[pos] < n-1 && a[y[pos]][x[pos]+1] == 1) push(x[pos]+1, y[pos], l[pos]+1);

        pos++;
    }
    if (pos < cnt) cout << l[pos] << endl;
}

int main() 
{
    cin >> n;
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) cin >> a[i][j];
    }

    BFS();

    return 0;
}