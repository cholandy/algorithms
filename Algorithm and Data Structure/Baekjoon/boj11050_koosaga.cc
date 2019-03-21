#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
const int mod = 1e4 + 7;

int bino[1005][1005];

int main(){
    int n, k;
    cin >> n >> k;
    bino[0][0] = 1;
    for(int i=1; i<=n; i++){
        bino[i][0] = 1;
        for(int j=1; j<=i; j++){
            bino[i][j] = bino[i-1][j] + bino[i-1][j-1];
       //     bino[i][j] %= mod;
        }
    }
    cout << bino[n][k];
}