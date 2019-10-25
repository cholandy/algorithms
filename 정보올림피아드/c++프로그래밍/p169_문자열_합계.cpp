#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string str;
    int sum = 0, i;
    cin >> str;

    for (i=0; i<str.length(); i++){
        if (islower(str[i])) sum += 1 + str[i] - 'a';
        else sum += 52 - (str[i] - 'A');
    }

    cout << sum << endl;

    return 0;
}