#include <iostream>
#include <string>
#include <map>
using namespace std;
int n, m, num;
string grp, str;
map<string, string> mp;
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    while (n--) {
        cin >> grp >> num;
        while (num--) {
            cin >> str;
            mp[grp] = str; mp[str] = grp;
        }
    }
    while (m--) {
        cin >> str >> num;
        if (!num) for (auto it : mp) {
            if (it.second == str) cout << it.first << "\n";
        }
        else {
            cout << mp[str] << "\n";
        }
    }
    return 0;
}