#include <iostream>

using namespace std;

const int N = 5;

int main()
{
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
        cout << a[i];

    return 0;
}