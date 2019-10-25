#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int sum[100], cnt = 0, i, j, c = 0;

    cin >> a >> b;

    i = a.length() - 1;
    j = b.length() - 1;

    while (c > 0 || i >= 0 || j >= 0)
    {
        if (i >= 0)
        {
            c += a[i] - '0';

            i--;
        }
        if (j >= 0)
        {
            c += b[j] - '0';
            j--;
        }
        sum[cnt++] = c % 2;
        c /= 2;
    }
    for (i = cnt - 1; i >= 0; i--)
        cout << sum[i];
    cout << endl;

    return 0;
}