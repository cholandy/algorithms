#include <iostream>

using namespace std;

int main()
{
    int i;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[10] = {
        0,
    };

    for (i = 0; i < 10; i++)
        cout << a[i] << endl;
    for (i = 0; i < 10; i++)
        cout << b[i] << endl;

    return 0;
}