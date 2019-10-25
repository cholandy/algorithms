#include <iostream>
#include <string>

using namespace std;
int main() 
{
    string a = "0123456789)!@#$%^&*(";
    string b = ")!@#$%^&*(0123456789";
    string str;
    int i, j;
    cin >> str;

    for (i=0; i<str.length(); i++) {
        for (j=0; j<a.length(); j++){
            if (str[i] == a[j]) {
                cout << b[j];
                break;
            }
        }
    }
    cout << endl;
    return 0;
}