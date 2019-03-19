#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

stack<int> s;

int n,a[100005];

long long proc(){
    scanf("%d",&n);
    if(n == 0) return -1;
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    long long res = 0;
    for (int i=0; i<n; i++) {
        while(!s.empty() && a[s.top()] > a[i]){
            int q = s.top(), w = 0;
            s.pop();
            if(s.empty()) w = i;
            else w = i - 1 - s.top();
            res = max(res,1ll * w*a[q]);
        }
        s.push(i);
    }
    while (!s.empty()){
        int q = s.top(), w = 0;
        s.pop();
        if(s.empty()) w = n;
        else w = n - 1 - s.top();
        res = max(res,1ll * w * a[q]);
    }
    return res;
}

int main(){
    while (1) {
        long long r = proc();
        if(r != -1) printf("%lld\n",r);
        else break;
    }
}