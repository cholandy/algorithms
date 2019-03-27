#include <iostream>
using namespace std;
 
int n,k, num[1001], cnt=0;
 
int main() {
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        if (num[i]%2!=0 && num[i]%3!=0 && num[i]==0) {
            num[i] = 1;
            cnt++;
            if (cnt == k) { cout << i; break; }
        }
        else {
            for (int j = 1; j*i <= n; j++) {
                if (num[j*i] == 0) {
                    num[j*i] = 1;
                    cnt++;
                    if (cnt == k) { cout << j*i; break; }
                }
            }
        }
    }
    return 0;
}
