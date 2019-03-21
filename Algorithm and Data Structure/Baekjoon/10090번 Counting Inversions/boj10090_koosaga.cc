#include <cstdio>

int tree[1000005], n;

void add(int idx, int val){
    while (idx<=n) {
        tree[idx]+=val;
        idx+=(-idx&idx);
    }
}

int sum(int idx){
    int sum=0;
    while (idx) {
        sum+=tree[idx];
        idx-=(-idx&idx);
    }
    return sum;
}

int main(){
    long long r=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
    	int t;
    	scanf("%d",&t);
    	add(t,1);
    	r += (i+1) - sum(t);
    }
    printf("%lld",r);
}