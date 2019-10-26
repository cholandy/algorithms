#include <iostream>
#include <deque>

using namespace std;

int n;
int a[5][5];

void BFS() 
{
    deque<int> y, x, l;
    y.push_back(0);
    x.push_back(0);
    l.push_back(1);

    while (!x.empty() && (x.front() != n-1 || y.front() != n-1)) {
        a[y.front()][x.front()]
    }
}