#include <map>
#include <set>
#include <iostream>

using namespace std;

int main() {
    set<int> S;
    S.insert(3);
    S.insert({5,1,7});
    if (S.find(6) == S.end()) cout << "6 is not in S\n" << endl;
    else cout << "6 is in S\n" << endl;
    cout << S.size() << '\n';
    S.erase(2);
    S.erase(1);
    S.insert(3);
    for (auto e : S) cout << e << ' ';
    cout << '\n';
    S.clear();
    cout << S.size() << endl;

    map<string, int> M;
    M["Kim"] = 13579;
    M["Woo"] = 24681;
    M["Apple"] = 45677;
    for (auto e : M) cout << e.first << " : " << e.second << '\n';

    return 0;
}