#include <stdio.h>

int par[100001];

int find(int x) {
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void link(int x, int y) {
    par[find(y)] = find(x);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }

    while(q--) {
        int cmd, x, y;
        scanf("%d %d %d", &cmd, &x, &y);
        if(cmd == 1) {
            link(x, y);
        } else {
            if(find(x) == find(y)) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}