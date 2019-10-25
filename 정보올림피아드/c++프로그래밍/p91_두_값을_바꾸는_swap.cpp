#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a = 2, b = 3;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    swap(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}