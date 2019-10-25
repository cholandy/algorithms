#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int i, j, a[100], count=0, n=0;
    string str;

    cin >> str;

    for (i=0; i<str.length();i++) {
        if (str[i]=='0') {
            if (count > 0 ) a[n++] = count;
            count = 0;
        }
        else count++;
    }
    if (count > 0) a[n++] = count;
    sort(a, a+n);
    for(i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}