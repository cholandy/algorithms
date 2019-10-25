#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k, i, cnt, a[100] = {0,}, total = 0;
    cin >> n >> k;
    if (k == 0) {
        for (i=0; i<n; i++) cout << "B";
        cout << endl;
        cout << 1 << endl;
    }
    else if (k == n) {
        for (i=0; i<n; i++) cout << "F";
        cout << endl;
        cout << 1 << endl;
    } else {
        while (1) {
            i = n - 1;
            while (i >= 0) {
                a[i]++;
                if (a[i] == 2) {
                    a[i] = 0;
                    i--;
                } else break;
            }
            if (i == -1) break;
            cnt = 0;
            for (i = 0; i<n; i++){
                if (a[i] == 1) cnt++;
            }
            if (cnt == k) {
                for (i=0;i<n;i++) {
                    if (a[i] == 1) cout << "F";
                    else cout << "B";
                }
                cout << endl;
                total++;
            }
        }
    }
    cout << total << endl;

    return 0;
}