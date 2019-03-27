#include <cstdio>

int g(int a,int b){
    if(a<b) return g(b,a);
    if(a%b==0) return b;
    return g(b,a%b);
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    printf("%d\n%d",g(n,m),n*(m/g(n,m)));
}