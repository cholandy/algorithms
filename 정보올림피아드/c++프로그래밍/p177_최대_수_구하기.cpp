#include <iostream>

using namespace std;

int main() {
    int count[51] = {0,}, n, x, max, i;
    bool same;

    cin >> n;

    for (i=0; i<n; i++) {
        cin >> x;
        count[x]++;
    }

    max = 0;
    for (i=1; i<=50; i++) {
        if (max < count[i]) {
            max = count[i];
            same = false;
        }
        else if (max == count[i]) same = true;
    }

    if (same) cout << "-1" << endl;
    else cout << max << endl;

    return 0;
}