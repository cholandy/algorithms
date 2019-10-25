#include <iostream>

using namespace std;

int main()
{
    int count[10] = {
        0,
    },
        x, i;
    while (cin >> x)
        count[x]++;
    for (i = 1; i < 10; i++)
        cout << i << "=" << count[i] << endl;
    return 0;
}