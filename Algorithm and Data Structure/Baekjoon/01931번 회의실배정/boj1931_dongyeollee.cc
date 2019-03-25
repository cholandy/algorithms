#include <iostream>
#include <algorithm>
 
using namespace std;
 
struct Time {
    int start, end;
};
 
int N;
Time arr[100000];
 
bool cmp(const Time &a, const Time &b) {
    if(a.end == b.end) {
        return a.start < b.start;
    } else {
        return a.end < b.end;
    }
}
 
int main() {
 
    cin >> N;
 
    for(int i = 0; i < N; i ++) {
        cin >> arr[i].start >> arr[i].end;
    }
 
    // 오름차순 정렬, 만약 끝나는 시간이 같으면 시작 시간이 작은 순으로
    sort(arr, arr + N, cmp);
 
    int now = 0;
    int ans = 0;
    for(int i = 0; i < N; i ++) {
        if(now <= arr[i].start) {
            now = arr[i].end;
            ans += 1;
        }
    }
 
    cout << ans << endl;
    return 0;
}