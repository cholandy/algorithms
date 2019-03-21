#include <cstdio>
int a[10005],n;
int data[10005];

int dp(int p){
    if(p>=n) return 0;
    if(p>=0 && data[p]>=0) return data[p];
    int max=1e9;
    for (int i=1; i<=3; i++) {
        if(max>dp(p+i)) max=dp(p+i);
    }
    if(p>=0) max+=a[p];
    return data[p]=max;
}
int main(){
    scanf("%d",&n);
    int r=0;
    for (int i=0; i<10000; i++) {
        data[i]=-1;
    }
    for (int i=0; i<n; i++){
        scanf("%d",&a[i]);
        r+=a[i];
    }
    printf("%d",r-dp(-1));
}