#include <cstdio>
#include <algorithm>
using namespace std;
int ar[12], ret = 1e9;

void backtrack(int p, int q, int r, int s, int a, int b, int c, int d, int dt){
    if(dt == 12){
        ret = min(ret,max(a,max(b,max(c,d))) - min(a,min(b,min(c,d))));
        return;
    }
    if(p) backtrack(p-1,q,r,s,a + ar[dt],b,c,d,dt+1);
    if(q) backtrack(p,q-1,r,s,a,b + ar[dt],c,d,dt+1);
    if(r) backtrack(p,q,r-1,s,a,b,c + ar[dt],d,dt+1);
    if(s) backtrack(p,q,r,s-1,a,b,c,d + ar[dt],dt+1);
}

int main(){
    for (int i=0; i<12; i++) {
        scanf("%d",&ar[i]);
    }
    backtrack(3,3,3,3,0,0,0,0,0);
    printf("%d",ret);
}