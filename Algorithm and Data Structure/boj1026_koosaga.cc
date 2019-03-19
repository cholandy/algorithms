#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000005], b[1000005];
int n;

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    int res = 0;
    for (int i=0; i<n; i++) {
        res += a[i] * b[n-i-1];
    }
    printf("%d",res);
}