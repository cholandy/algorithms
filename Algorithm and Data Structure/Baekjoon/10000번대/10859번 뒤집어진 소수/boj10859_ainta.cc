#include<stdio.h>
char p[20];
bool Isprime(long long n){
    if(n==2)return true;
    if(n==1 || n%2==0)return false;
    long long i;
    for(i=3;i*i<=n;i+=2)if(n%i==0)return false;
    return true;
}
int main(){
    int i;
    long long n = 0, m = 0, t = 1;
    scanf("%s",p);
    for(i=0;p[i];i++){
        m*=10;
        m+=p[i]-'0';
        if(p[i]=='3'||p[i]=='7'||p[i]=='4'){
            printf("no\n");
            return 0;
        }
        if(p[i]=='6'||p[i]=='9')p[i]='6'+'9'-p[i];
        n += t * (p[i]-'0');
        t*=10;
    }
    if(Isprime(m) && Isprime(n))printf("yes\n");
    else printf("no\n");
}