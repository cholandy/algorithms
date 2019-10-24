#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string s;
    int a, b;
    double c;
    getline(cin, s);
    istringstream sin(s);
    sin >> a >> b >> c;

    cout << "s: " << s << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    return 0;
}