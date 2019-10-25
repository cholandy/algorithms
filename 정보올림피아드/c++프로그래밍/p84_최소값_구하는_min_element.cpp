#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[7], *min, *max, i;
    for (int i = 0; i < 7; i++)
    {
        cin >> a[i];
    }

    max = max_element(a, a + 7);
    min = min_element(a, a + 7);

    cout << "Max = " << *max << endl;
    cout << "Min = " << *min << endl;
    cout << "Max Index = " << max - a << endl;
    cout << "Min Index = " << min - a << endl;

    return 0;
}