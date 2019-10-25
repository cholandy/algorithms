#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[7], i;
    int *max;

    for (i = 0; i < 7; i++)
        cin >> a[i];

    max = max_element(a, a + 7);
    cout << *max << endl;
    a[max - a] = 0;
    max = max_element(a, a + 7);
    cout << *max << endl;
    return 0;
}