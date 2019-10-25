#include <iostream>

using namespace std;

int main()
{
    int n, i, x, sum1 = 0, sum2 = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 1)
            sum1 += x;
        else
            sum2 += x;
    }
    cout << sum1 << endl;
    cout << sum2 << endl;

    return 0;
}