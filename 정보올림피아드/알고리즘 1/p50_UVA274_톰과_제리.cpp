#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <memory.h>

using namespace std;

int main()
{
    int rooms, toms, jerrys, cases, from, to, i;
    bool jerry[105][105], jerryreach[105];
    bool tom[105][105], tomreach[105];
    bool flag1, flag2, first = true;
    string str;

    deque<int> q;
    
    cin >> cases;

    while (cases--) {
        if (!first) cout << endl;
        first = false;

        cin >> rooms >> toms >> jerrys;

        memset(tom ,false, sizeof(tom));
        memset(jerry, false, sizeof(jerry));

        while (1) {
            cin >> from >> to;
            if (from < 0) break;

            tom[from][to] = true;
        }
        cin.get();

        while (1) {
            getline(cin, str);
            if (str == "") break;
            istringstream os(str);
            os >> from >> to;

            jerry[from][to] = true;
        }

        if (toms == jerrys) {
            cout << "Y N" << endl;
            continue;
        }

        flag1 = flag2 = false;
        fill(tomreach, tomreach+105, false);
        q.push_back(toms);
        tomreach[toms] = true;

        while (!q.empty()) {
            for (i=1; i<=rooms; i++) {
                if (tomreach[i]) continue;
                if (tom[q.front()][i]) {
                    tomreach[i] = true;
                    q.push_back(i);
                }
            }
            q.pop_front();
        }
        if (tomreach[jerrys]) {
            cout << "Y N" << endl;
            continue;
        }
        q.clear();
        fill(jerryreach, jerryreach+105, false);
        q.push_back(jerrys);
        jerryreach[jerrys] = true;

        while (!q.empty()) {
            for (i=1; i<=rooms; i++) {
                if (jerry[q.front()][i] && i == jerrys && jerryreach[q.front()]) {
                    flag2 = true;
                }
                if (jerryreach[i]) continue;
                if (jerry[q.front()][i]) {
                    jerryreach[i] = jerryreach[q.front()];
                    if (tomreach[i]) {
                        flag1 =1;
                        jerryreach[i] = true;
                    }
                    q.push_back(i);
                }
            }
            q.pop_front();

            if (flag1 && flag2) break;
        }

        if (flag1) cout << "Y ";
        else cout << "N ";
        if (flag2) cout << "Y" << endl;
        else cout << "N" << endl;
    }

    return 0;
}