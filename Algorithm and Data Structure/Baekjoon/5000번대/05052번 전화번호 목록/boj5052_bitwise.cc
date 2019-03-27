#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <math.h>
#include <memory.h>
using namespace std;
 
#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long
 
#define c_reverse(s) reverse(s.begin(), s.end())
#define c_sort(s) sort(s.begin(), s.end())
 
#define print_vector(v) for(int i=0; i<v.size(); i++) cout << v[i];
 
int main() {
 
    cin.tie(0);
    std::ios::sync_with_stdio(false);
 
    int t; cin >> t;
 
    while (t--) {
        int n; cin >> n;
 
        vector<string> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
 
        sort(arr.begin(), arr.end());
 
        bool isOk = true;
        for (int i = 1; i < arr.size(); i++) {
            // 현자 문자열에서 이전의 문자열이 원소로 있다면 접두사를 갖는다는 의미로 처리 한다.
            if (arr[i - 1] == arr[i].substr(0, arr[i - 1].size())) {
                isOk = false;
                break;
            }
        }
 
        if (isOk) {
            cout << "YES" << CENDL;
        }
        else {
            cout << "NO" << CENDL;
        }
    }
    return 0;
}
