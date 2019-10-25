#include <iostream>

using namespace std;

int main()
{
    int n, jin[100], cnt = 0, i;

    cin >> n;
    while (n > 1)
    {
        jin[cnt++] = n % 2;
        n /= 2;
    }
    jin[cnt++] = 1;

    for (i = cnt - 1; i >= 0; i--)
        cout << jin[i];
    cout << endl;

    return 0;
}