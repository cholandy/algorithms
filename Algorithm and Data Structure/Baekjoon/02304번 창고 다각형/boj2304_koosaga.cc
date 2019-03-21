#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

int n;
pi a[1005];

int cmp(pi a, pi b){
    return a.second < b.second;
}

int main(){
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(a,a+n);
    int p = (*max_element(a,a+n,cmp)).second;
    int r = 1e9, s = -1e9, t = 1e9, u = -1e9;
    for (int i=0; i<n; i++) {
        if(a[i].second == p){
            r = min(r,a[i].first);
            t = min(t,i);
            s = max(s,a[i].first);
            u = max(u,i);
        }
    }
    int cm = 0, res = p * (s - r + 1);
    for (int i=0; i<=t; i++) {
        if(i) res += (a[i].first - a[i-1].first) * cm;
        cm = max(cm,a[i].second);
    }
    cm = 0;
    for (int i=n-1; i>=u; i--) {
        if(i+1 != n) res += (a[i+1].first - a[i].first) * cm;
        cm = max(cm,a[i].second);
    }
    printf("%d",res);
}
