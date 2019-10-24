#include <iostream>

using namespace std;

int a[100][100], i, j, n, m;

int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    return 0;
}