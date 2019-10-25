#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i, j;
    string a;
    cin >> a;
    for (i = 0; i < a.length(); i++)
    {
        for (j = i; j < a.length(); j++)
            cout << a[j];
        for (j = 0; j < i; j++)
            cout << a[j];
        cout << endl;
    }
    return 0;
}