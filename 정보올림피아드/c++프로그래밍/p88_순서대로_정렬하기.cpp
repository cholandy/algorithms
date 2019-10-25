#include <iostream>

using namespace std;

int main()
{
    int a[7], i, j, t;

    for (i = 0; i < 7; i++)
        cin >> a[i];

    for (i = 0; i < 6; i++)
    {
        for (j = i + 1; j < 7; j++)
        {
            if (a[i] > a[j])
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    for (i = 0; i < 7; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}