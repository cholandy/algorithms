#include <iostream>
using namespace std;
 
#define MAX 100000000000000
 
int main() {
    int n;
    long long m, t[100001], left=1,right=MAX,result=MAX;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    while (left <= right) {
        long long sum=0,mid = (left + right) / 2;
        for (int i = 0; i < n; i++)
            sum += (mid / t[i]);
        if (sum >= m) { 
            if (result > mid) { result = mid; }
            right = mid - 1;
        }
        else if (sum < m) { left = mid + 1; }
    }
    cout << result << '\n';
    return 0;
}
