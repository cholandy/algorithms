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
        a[y.front()][x.front()];

        if (y.front() > 0 && a[y.front()-1][x.front()] == 1) {
            x.push_back(x.front());
            y.push_back(y.front()-1);
            l.push_back(l.front()+1);
        }

        if (y.front() < n-1 && a[y.front()+1][x.front()] == 1) {
            x.push_back(x.front());
            y.push_back(y.front()+1);
            l.push_back(l.front()+1);
        }
        
        if (x.front() > 0 && a[y.front()][x.front()-1] == 1) {
            x.push_back(x.front()-1);
            y.push_back(y.front());
            l.push_back(l.front()+1);
        }

        if (x.front() < n-1 && a[y.front()][x.front()+1] == 1) {
            x.push_back(x.front()+1);
            y.push_back(y.front());
            l.push_back(l.front()+1);
        }
        
        x.pop_front();
        y.pop_front();
        l.pop_front();
    }

    if (!x.empty()) cout << l.front() << endl;
}

int main() {
    cin >> n;

    int i, j;

    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) cin >> a[i][j];
    }

    BFS();

    return 0;
}