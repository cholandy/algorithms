#include <iostream>

using namespace std;

int main() {
    int a,b,l,g;
    cin >> a >> b;
    if (a < b) {
        g = a;
        a = b;
        b = g;
    }
    l = a*b;
    g=b;
    while (a%b != 0) {
        g = a % b;
        a = b;
        b = g;
    }
    cout << g << endl << l/g << endl;

    return 0;
}