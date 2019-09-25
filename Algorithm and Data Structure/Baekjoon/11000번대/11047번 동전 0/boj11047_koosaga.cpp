#include <stdio.h>
int n, k, a[11];

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    int ret = 0;
    for(int i=n-1; i>=0; i--){
        ret += k / a[i];
        k %= a[i];
    }
    printf("%d",ret);
}