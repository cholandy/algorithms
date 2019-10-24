#include <fstream>

using namespace std;

int main()
{
    int a[1000], num;
    ifstream in("input.txt");

    num = 0;
    while (in >> a[num])
        num++;

    return 0;
}