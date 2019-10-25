#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, count = 0;
    string a;
    char x;
    bool one = false, zero = false;

    cin >> a;
    if (a[0] != '.') count++;
    for (i=1; i<a.length(); i++) {
        if (a[0] == '.') {
            if (count == 5) {
                if (x == '1') one = true;
                else zero = true;
            }
            count = 0;
        } else if (a[i] == a[i-1]) {
            count++;
            x = a[i];
        } else {
            if (count == 5) {
                if (x == '1') one = true;
                else zero = true;
            }
            count = 1;
        }
    }
    if (one == true) cout << "1 win" << endl;
    else if (zero == true) cout << "0 win" << endl;
    else cout << "no win" << endl;

    return 0;
}