#include <iostream>

using namespace std;

int main()
{
    int a = 2, b = 3, t;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    t = a;
    a = b;
    b = t;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}