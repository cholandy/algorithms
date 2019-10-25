#include <iostream>

using namespace std;

int main()
{
    int a[5], i, j, rank;

    for (i = 0; i < 5; i++)
        cin >> a[i];
    for (i = 0; i < 5; i++)
    {
        rank = 1;
        for (j = 0; j < 5; j++)
        {
            if (a[i] < a[j])
                rank++;
        }
        cout << rank << endl;
    }
    return 0;
}