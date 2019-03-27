#include <cstdio>

int x,n,a[300005];

bool trial(int m){
    long long r = 0;
    for (int i=0; i<n; i++) {
        r += (a[i] + m - 1) / m;
    }
    if(r > x) return 0;
    else return 1;
}
int main(){
    scanf("%d %d",&x,&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int s = 0, e = 1e9;
    while (s != e) {
        int m = (s+e)/2;
        if(trial(m)) e = m;
        else s = m+1;
    }
    printf("%d",e);
}