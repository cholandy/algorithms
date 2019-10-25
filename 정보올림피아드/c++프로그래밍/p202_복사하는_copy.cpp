#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int i, a[10], b[10];

    for (i=0; i<10; i++) a[i] = i;
    copy(a, a+10, b);
    for (i=0;i<10;i++) cout << b[i] << " ";
    cout << endl;
    copy(a, a+5, a+5);

    for(i=0; i<10; i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}