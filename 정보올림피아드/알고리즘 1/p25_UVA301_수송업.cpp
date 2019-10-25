#include <iostream>

using namespace std;

int from[22], to[22], people[22];
int mx, cap[8], sum, orders;

void DFS(int now);

int main()
{
    int i;
    int capacity, station;

    while (cin >> capacity >> station >> orders) {
        if (capacity == 0 && station == 0 && orders == 0) break;

        mx = 0;
        for (i=0; i<orders; i++) {
            cin >> from[i] >> to[i] >> people[i];
        }
        for (i=0; i<=station; i++) cap[i] = capacity;
        sum = 0;
        DFS(0);
        cout << mx << endl;
    }
    return 0;
}

void DFS(int now)
{
    int i;
    bool flag;

    if (now == orders) {
        if (sum > mx) mx = sum;
    } else {
        flag = false;
        for (i=from[now]; i<to[now]; i++) {
            if (cap[i] < people[now]) flag = true;
        }

        if (!flag) {
            for (i=from[now]; i<to[now]; i++) cap[i] -= people[now];
            sum += people[now] * (to[now] - from[now]);
            DFS(now+1);
            for (i = from[now]; i<to[now]; i++) cap[i] += people[now];
            sum -= people[now] * (to[now] - from[now]);
        }
        DFS(now+1);
    }
}