#include <iostream>
#include <string> 
#include <set>
using namespace std;
int main() { 
    int N, M; cin >> N >> M;
    set<string> dont_see, dont_hear, dont_two;
    for (int idx = 0; idx < N; idx++) {
        string sub; cin >> sub; 
        dont_see.insert(sub);
    }
    for (int idx = 0; idx < M; idx++) {
        string sub; cin >> sub;
        dont_hear.insert(sub);
    }
    auto see_one = dont_see.begin();
    auto hear_one = dont_hear.begin();
    for (; see_one != dont_see.end();) {
        // 다 탐색하면 종료 
        if (hear_one == dont_hear.end()) break;
        // 순서 비교
        if (*hear_one > *see_one)
            see_one++;
        else if (*hear_one < *see_one) 
            hear_one++;
        else {
            dont_two.insert(*see_one);
            hear_one++;
            see_one++;
        } 
    }
    cout << dont_two.size() << "\n";
    for (auto each : dont_two) 
        cout << each << "\n";
    return 0;
}