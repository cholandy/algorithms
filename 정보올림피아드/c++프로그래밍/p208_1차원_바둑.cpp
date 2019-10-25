#include <iostream>
#include <string>

using namespace std;

int main() {
    int i, j, count, space, total;
    string a;
    cin >> a;
    int white =0, black=0,pre=-1;

    for (i=0; i<a.length();i++) {
        if (a[i] == '0') {
            if (pre != -1) {
                if (a[pre+1] == '1' && a[i-1] == '1') {
                    count = space = total = 0;
                    for (j = pre+1; j<i; j++) {
                        if (a[j] == '1') total++;
                        if (a[j-1]=='.' && a[j]=='.') count++;
                        if (a[j-1] != '.' && a[j] == '.') space++;
                    }
                    if (space == 0 || (space == 1 && count <=3)) white += total;
                }
            }
            pre = i;
        }
    }
    pre = -1;
    for (i=0;i<a.length();i++) {
        if (a[i] == '1') {
            if (pre != -1) {
                if (a[pre+1] == '0' && a[i-1] == '0') {
                    count = space = total = 0;
                    for (j=pre+1; j<i; j++) {
                        if (a[j] == '0') total++;
                        if (a[j-1] == '.' && a[j] == '.') count++;
                        if (a[j-1] != '.' && a[j] == '.') space++;
                    }
                    if (space == 0 || (space == 1 && count <= 3)) black+=total;
                }
            }
            pre = i;
        }
    }

    cout << "0: " << white << endl;
    cout << "1: " << black << endl;

    return 0;
}