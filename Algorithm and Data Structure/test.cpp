#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    int test_case;
    freopen("input.txt","r", stdin);
    cin >> test_case;
    for (int T = 0; T < test_case; T++) {
        int a,b,c;
        cin >> a >> b >> c;
        cout << a << " " << b<< " " << c << endl;
    }
    return 0;
}