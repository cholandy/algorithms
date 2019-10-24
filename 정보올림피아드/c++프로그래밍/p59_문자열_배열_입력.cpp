#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str[100];
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> str[i];
    }

    for (i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}