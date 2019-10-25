#include <iostream>

using namespace std;

int main()
{
    int a[7], min, max, mini, maxi;

    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    min = 100;
    max = 0;
    for (int i = 0; i < 7; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            maxi = i;
        }
        if (min > a[i])
        {
            min = a[i];
            mini = i;
        }
    }

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    cout << "Max Index = " << maxi << endl;
    cout << "Min Index = " << mini << endl;

    return 0;
}