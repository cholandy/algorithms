#include <iostream>

using namespace std;

int n, cnt, pre[20];
bool notPrime[32] = {true, true, }, digit[20];

void DFS(int del);
int main()
{
    int i, j, cases = 1;
    for (i = 2; i < 16; i++) {
        if (!notPrime[i]) {
            for (j=2; i*j<32; j++) notPrime[i*j] = true;
        }
    }
    while (cin >> n) {
        if (cases > 1) cout << endl;
        cout << "Case " << cases++ << ":" << endl;
        for (i=0; i<n; i++) digit[i] = true;
        cnt = 1;
        pre[0] = 1;
        DFS(0);
    }
    return 0;
}

void DFS(int del) {
    int i,j;
    digit[del] = false;

    for (i=1; i<n; i++) {
        if (digit[i]) {
            if (notPrime[i+1+pre[cnt-1]]) continue;
            pre[cnt++] = i+1;
            if (cnt == n) {
                if (!notPrime[pre[cnt-1]+1]) {
                    for (j=0; j<n-1; j++) cout << pre[j] << " ";
                    cout << pre[n-1] << endl;
                }
            }
            else DFS(i);
            cnt--;
        }
    }
    digit[del] = true;
}