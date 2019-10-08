#include <iostream>
#include <string>
using namespace std;
int fail[200022];
string a, t, p;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> p;
    for (auto it : a) if (it < '0' || it > '9') t.push_back(it);
    for (int i = 1, j = 0; i < p.length(); ++i) {
        while (j && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    for (int i = 0, j = 0; i < t.length(); ++i) {
        while (j && t[i] != p[j]) j = fail[j - 1];
        if (t[i] == p[j]) {
            if (j == p.length() - 1) {
                cout << 1;
                return 0;
            }
            else ++j;
        }
    }
    cout << 0;
    return 0;
}