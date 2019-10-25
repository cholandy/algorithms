#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, i, j, a[100][100];

    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << setw(2) << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}