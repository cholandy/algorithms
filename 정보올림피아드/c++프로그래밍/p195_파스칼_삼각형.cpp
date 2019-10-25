#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, i, j, a[31] = {1,1,}, b[31] = {0,};
    
    cin >> n;

    if (n < 3) {
        for (i=0; i<n; i++) cout << "1 ";
        cout << endl;
    } else {
        for (i=2; i<n; i++) {
            cout << i << endl;
            b[0] = b[i] = 1;
            for (j = 1; j< i; j++) b[j] = a[j-1] + a[j];
            
            copy(b, b+i+1, a);
            
        }
        for (i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}