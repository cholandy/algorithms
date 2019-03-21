#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lint;

bool a[1000005];

int main(){
    lint s,e;
    scanf("%lld %lld",&s,&e);
    for (lint i=2; i<=1000000; i++) {
        for (lint j=s - (s % (i*i)); j<=e; j+=i*i) {
            if(j >= s) a[j - s] = 1;
        }
    }
    printf("%d",(int)count(a,a+e-s+1,false));
}