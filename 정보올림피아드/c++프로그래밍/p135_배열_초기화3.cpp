#include <iostream>

using namespace std;

int main()
{
    int a[10], b[10], i;

    for (i = 0; i < 10; i++)
        a[i] = 2;
    for (i = 0; i < 10; i++)
        b[i] = i + 1;

    for (i = 0; i < 10; i++)
        cout << a[i] << endl;
    for (i = 0; i < 10; i++)
        cout << b[i] << endl;

    return 0;
}