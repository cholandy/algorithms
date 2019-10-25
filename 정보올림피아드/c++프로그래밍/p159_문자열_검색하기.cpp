#include <iostream>
#include <string>

using namespace std;

int main() {
    string a,b;
    int i,j;
    bool fnd;

    getline(cin, a);
    getline(cin, b);

    for (i=0; i<=a.length()-b.length(); i++){
        fnd = true;
        for (j=0;j<b.length();j++){
            if(a[i+j] != b[j]) {
                fnd = false;
                break;
            }
        }
        if (fnd) {
            cout << i+1 << endl;
            break;
        }
    }
    if (fnd == false) cout << "-1" << endl;
    return 0;

}