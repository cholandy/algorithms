#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    int n, i, j, t, x;

    t = GetTickCount();
    cin >> n;

    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            x = i+j;
        }
    }
    cout << (GetTickCount()-t)/1000 << endl;

    return 0;
}