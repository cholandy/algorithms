#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, i, j, count = 1, a[1000];
    bool sosu;

    cin >> n;

    a[0] = 2;
    int cnt = 1;
    if (n >= 2) cout << "2 ";

    for (i=3; i<=n; i++) {
        sosu = true;

        for (j=0; a[j] <= (int)sqrt(i); j++) {
            if (i%a[j] == 0) {
                sosu = false;
                break;
            }
        }
        if (sosu) {
            if (count % 10 == 0) {
                cout << endl;
                cnt = 1;
            }
            a[count++] = i;
            cout << i << " ";
        }
    }
}