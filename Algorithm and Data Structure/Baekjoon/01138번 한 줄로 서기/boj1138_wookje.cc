#include <cstdio>
#include <vector>
using namespace std;

int n, x, a[12];
vector<int> v;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    v.push_back(n);
    for (int i = n-1; i >= 1; i--) {
        v.insert(v.begin()+a[i], i);
    }
    for (int it : v) {
        printf("%d ", it);
    }
    
    return 0;
}