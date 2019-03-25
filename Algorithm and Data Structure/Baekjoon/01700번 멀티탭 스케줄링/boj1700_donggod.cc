#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <cstdio>
using namespace std;
 
#define ll long long
#define MOD ((int)1e9 + 9)
#define MAX_SIZE (int)1e5
#define mp make_pair
#define INF 987654321
#define pii pair<int, int>
//ios::sync_with_stdio(false); cin.tie(0);
 
int arr[100];
bool use[100];
int tab[100];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, nn;
    cin >> n >> nn;
 
    for (int i = 0; i < nn; i++) {
        cin >> arr[i];
        arr[i]--;
    }
 
    int ret = 0;
    int tabIdx = 0;
 
    for (int i = 0; i < nn; i++) {
 
        if (use[arr[i]]) continue; //사용하던 아이템임        
                                   //멀티탭 공간이 남음
        else if (tabIdx < n) {
            tab[tabIdx++] = arr[i];
            use[arr[i]] = 1;
            continue;
        }
 
 
        ret++; // 위 두가지 경우를 제외하고는 뽑을 수 밖에 없음.
 
        int port = 0;
        int farDistance = 0;
 
        //멀티탭에 꽂혀있는 것을 검사
        for (int j = 0; j < n; j++) {
            int distance = INF;
 
            for (int k = i + 1; k < nn; k++) {
                if (tab[j] == arr[k]) {
                    distance = k;
                    break;
                }
            }
 
            if (distance > farDistance) {
                port = j;
                farDistance = distance;
            }
        }
 
        //현재 꽂혀있는 것 중에 가장 먼 아이템을 포트에서 제거
        use[tab[port]] = 0;
        use[arr[i]] = 1;
        tab[port] = arr[i];
    }
 
    cout << ret;
 
    return 0;
}