#include <iostream>

using namespace std;

int main() {
    unsigned long long i, a, b, c, n;

    cin >> n;
    a = 1;
    b = 1;
    for (i=3; i<=n; i++) {
        c = a + b;
        a= b;
        b = c;
    }
    cout << c << endl;

    return 0;
}