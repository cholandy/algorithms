#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,a[100001];

struct rmq{
    int tree[270000], lim;
    void init(int n, int* a){
        fill(tree, tree+270000, 1e9);
        for(lim = 1; lim <= n; lim <<= 1);
        for(int i=1; i<=n; i++) tree[lim + i] = a[i];
        for(int i = lim - 1; i; i--) tree[i] = min(tree[2*i],tree[2*i+1]);
    }
    int q(int s, int e){
        int r = 1e9;
        s += lim;
        e += lim;
        while(s < e){
            if(s%2 == 1) r = min(r,tree[s++]);
            if(e%2 == 0) r = min(r,tree[e--]);
            s >>= 1;
            e >>= 1;
        }
        if(s == e) r = min(r,tree[s]);
        return r;
    }
}rmq;
int main(){
    int q,x,y;
    scanf("%d %d",&n,&q);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    rmq.init(n,a);
    for (int i=0; i<q; i++) {
        scanf("%d %d",&x,&y);
        printf("%d\n",rmq.q(x,y));
    }
}