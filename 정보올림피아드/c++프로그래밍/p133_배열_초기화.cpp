#include <iostream>

using namespace std;

int a[10];

int main()
{
    int i;
    int b[10];

    for (i = 0; i < 10; i++)
        cout << a[i] << endl;
    for (i = 0; i < 10; i++)
        cout << b[i] << endl;

    return 0;
}