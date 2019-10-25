#include <iostream>

using namespace std;

int main() {
    int n, i, j, a[31] = {1, 1,};

    cin >> n;
    if (n < 3) {
        for (i = 0; i < n; i++) cout << "1 ";
        cout << endl;
    } else {
        for (i = 2; i<n;i++){
            for (j = i - 1; j >= 0; j--) a[j] = a[j-1]+a[j];
            a[i] = 1;
        }
        for (i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}