#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n%400 == 0) cout << "윤년" << endl;
    else if (n%100) cout << "평년" << endl;
    else if (n%4==0) cout << "윤년" << endl;
    else cout << "평년" << endl;

    return 0;
}