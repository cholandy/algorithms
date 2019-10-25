#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[7], i;

    for (i = 0; i < 7; i++)
        a[i];

    sort(a, a + 7);
    cout << a[6] << endl;
    cout << a[5] << endl;

    return 0;
}