#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "ILoveItSo";
    cout << a.substr(3) << endl;
    cout << a.substr(2, 3) << endl;

    return 0;
}