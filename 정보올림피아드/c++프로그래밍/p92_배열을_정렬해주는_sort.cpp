#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[7], i;

    for (i = 0; i < 7; i++)
        cin >> a[i];
    sort(a, a + 7);
    for (i = 0; i < 7; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}