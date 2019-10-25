#include <iostream>

using namespace std;

int num = 2;
int c[2];

void coin(int n)
{
    int i;
    if (n==num) {
        for (i=0; i<num; i++) {
            if (c[i] == 1) cout << "Front ";
            else cout << "Back ";
        }
        cout << endl;
        return;
    }
    for (i = 1; i<=2; i++) {
        c[n] = i;
        coin(n+1);
    }
}

int main() {
    coin(0);
    return 0;
}