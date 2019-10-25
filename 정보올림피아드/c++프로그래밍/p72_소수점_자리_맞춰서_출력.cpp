#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a;
    int i;

    for (i = 0; i < 3; i++)
    {
        cin >> a;
        cout << fixed << setprecision(4) << a << endl;
    }
    return 0;
}